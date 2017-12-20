#include "sunxi_gpio_lib.h"

#ifndef SUNXI_GPIO_USE_IOREMAP
#include <unistd.h> // _SC_PAGESIZE
#include <fcntl.h> // O_RDWR, O_SYNC
#include <sys/mman.h> // mmap, munmap
#else
#include <asm/io.h> // ioremap, iounmap
#endif

struct sunxi_gpio {
    uint32_t cfg[4];
    uint32_t dat;
    uint32_t drv[2];
    uint32_t pull[2];
};

/* gpio interrupt control */
struct sunxi_gpio_int {
    uint32_t cfg[3];
    uint32_t ctl;
    uint32_t sta;
    uint32_t deb;
};

struct sunxi_gpio_reg {
    struct sunxi_gpio gpio_bank[9];
    uint8_t res[0xbc];
    struct sunxi_gpio_int gpio_int;
};

static void *SUNXI_PIO_BASE = 0;
static void *SUNXI_PIO_BASE_LM = 0;

int sunxi_gpio_init()
{
#ifndef SUNXI_GPIO_USE_IOREMAP
	int fd;
	uint32_t PageSize, PageMask;
	uint32_t addr_start, addr_offset;

	if (SUNXI_PIO_BASE != 0 || SUNXI_PIO_BASE_LM != 0)
		return -1;

	if ((fd = open("/dev/mem", O_RDWR | O_SYNC)) < 0) // O_RDWR
		return -1;

	PageSize = sysconf(_SC_PAGESIZE);
	PageMask = (~(PageSize - 1));

	addr_start = SW_PORTC_IO_BASE & PageMask;
	addr_offset = SW_PORTC_IO_BASE & ~PageMask;
	SUNXI_PIO_BASE = mmap(0, PageSize * 2, PROT_READ|PROT_WRITE, MAP_SHARED, fd, addr_start);
	if (SUNXI_PIO_BASE != MAP_FAILED)
		SUNXI_PIO_BASE += addr_offset;

	addr_start = SW_PORTC_IO_BASE_LM & PageMask;
	addr_offset = SW_PORTC_IO_BASE_LM & ~PageMask;
	SUNXI_PIO_BASE_LM = mmap(0, PageSize * 2, PROT_READ|PROT_WRITE, MAP_SHARED, fd, addr_start);
	if (SUNXI_PIO_BASE_LM != MAP_FAILED)
		SUNXI_PIO_BASE_LM += addr_offset;
	else {
		sunxi_gpio_close();
		return -1;
	}

	close(fd);
#else
	if (SUNXI_PIO_BASE != 0 || SUNXI_PIO_BASE_LM != 0)
		return -1;

	if ((SUNXI_PIO_BASE = ioremap(SW_PORTC_IO_BASE, 0x400)) == 0)
		return -1;

	if ((SUNXI_PIO_BASE_LM = ioremap(SW_PORTC_IO_BASE_LM, 0x400)) == 0)
		return -1;
#endif

	return 0;
}

int sunxi_gpio_get_cfgpin(uint32_t pin)
{
	uint32_t cfg;
	uint32_t bank = GPIO_BANK(pin);
	uint32_t index = GPIO_CFG_INDEX(pin);
	uint32_t offset = GPIO_CFG_OFFSET(pin);
	struct sunxi_gpio *pio;

	if (SUNXI_PIO_BASE == 0)
		return -1;

	if (bank == 11)
		pio = &((struct sunxi_gpio_reg *)SUNXI_PIO_BASE_LM)->gpio_bank[0];
	else
		pio = &((struct sunxi_gpio_reg *)SUNXI_PIO_BASE)->gpio_bank[bank];

	cfg = *(&pio->cfg[0] + index);
	cfg >>= offset;

	return (cfg & 0xf);
}

int sunxi_gpio_set_cfgpin(uint32_t pin, uint8_t val)
{
	uint32_t cfg;
	uint32_t bank = GPIO_BANK(pin);
	uint32_t index = GPIO_CFG_INDEX(pin);
	uint32_t offset = GPIO_CFG_OFFSET(pin);
	struct sunxi_gpio *pio;

	if (SUNXI_PIO_BASE == 0)
		return -1;

	if (bank == 11)
		pio = &((struct sunxi_gpio_reg *)SUNXI_PIO_BASE_LM)->gpio_bank[0];
	else
		pio = &((struct sunxi_gpio_reg *)SUNXI_PIO_BASE)->gpio_bank[bank];

	cfg = *(&pio->cfg[0] + index);
	cfg &= ~(0xf << offset);
	cfg |= val << offset;

	*(&pio->cfg[0] + index) = cfg;

	return 0;
}

int sunxi_gpio_input(uint32_t pin)
{
	uint32_t dat;
	uint32_t bank = GPIO_BANK(pin);
	uint32_t num = GPIO_NUM(pin);
	struct sunxi_gpio *pio;

	if (SUNXI_PIO_BASE == 0)
		return -1;

	if (bank == 11)
		pio = &((struct sunxi_gpio_reg *)SUNXI_PIO_BASE_LM)->gpio_bank[0];
	else
		pio = &((struct sunxi_gpio_reg *)SUNXI_PIO_BASE)->gpio_bank[bank];

	dat = *(&pio->dat);
	dat >>= num;

	return (dat & 0x1);
}

int sunxi_gpio_output(uint32_t pin, uint8_t val)
{
	uint32_t bank = GPIO_BANK(pin);
	uint32_t num = GPIO_NUM(pin);
	struct sunxi_gpio *pio;

	if (SUNXI_PIO_BASE == 0)
		return -1;

	if (bank == 11)
		pio = &((struct sunxi_gpio_reg *)SUNXI_PIO_BASE_LM)->gpio_bank[0];
	else
		pio = &((struct sunxi_gpio_reg *)SUNXI_PIO_BASE)->gpio_bank[bank];

	if (val)
		*(&pio->dat) |= 1 << num;
	else
		*(&pio->dat) &= ~(1 << num);

	return 0;
}

int sunxi_gpio_pullup(uint32_t pin, uint8_t pull)
{
	uint32_t cfg;
	uint32_t bank = GPIO_BANK(pin);
	uint32_t index = GPIO_PUL_INDEX(pin);
	uint32_t offset = GPIO_PUL_OFFSET(pin);
	struct sunxi_gpio *pio;

	if (SUNXI_PIO_BASE == 0)
		return -1;

	if (bank == 11)
		pio = &((struct sunxi_gpio_reg *)SUNXI_PIO_BASE_LM)->gpio_bank[0];
	else
		pio = &((struct sunxi_gpio_reg *)SUNXI_PIO_BASE)->gpio_bank[bank];

	cfg = *(&pio->pull[0] + index);
	cfg &= ~(0x3 << offset);
	cfg |= pull << offset;

	*(&pio->pull[0] + index) = cfg;

	return 0;
}

void sunxi_gpio_close(void)
{
#ifndef SUNXI_GPIO_USE_IOREMAP
	uint32_t PageSize = sysconf(_SC_PAGESIZE);
#endif

	if (SUNXI_PIO_BASE != 0)
#ifndef SUNXI_GPIO_USE_IOREMAP
		munmap(SUNXI_PIO_BASE, PageSize * 2);
#else
		iounmap(SUNXI_PIO_BASE);
#endif

	if (SUNXI_PIO_BASE_LM != 0)
#ifndef SUNXI_GPIO_USE_IOREMAP
		munmap(SUNXI_PIO_BASE_LM, PageSize * 2);
#else
		iounmap(SUNXI_PIO_BASE_LM);
#endif
	SUNXI_PIO_BASE = 0;
	SUNXI_PIO_BASE_LM = 0;
}