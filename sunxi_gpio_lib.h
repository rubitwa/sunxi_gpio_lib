#ifndef _GPIO_LIB_H_
#define _GPIO_LIB_H_

#include <inttypes.h>

// at the kernel level, for example, in the driver, need use ioremap
// at the user level, for example, in the simple executable binary, need use mmap
// so uncomment this defition if u need
//#define SUNXI_GPIO_USE_IOREMAP 1

#define SW_PORTC_IO_BASE 0x01c20800
#define SW_PORTC_IO_BASE_LM 0x01f02c00 // PL and PM offsets (SW_PORTC_IO_BASE - 0x2e2400)

#define SUNXI_GPIO_A	0
#define SUNXI_GPIO_B	1
#define SUNXI_GPIO_C	2
#define SUNXI_GPIO_D	3
#define SUNXI_GPIO_E	4
#define SUNXI_GPIO_F	5
#define SUNXI_GPIO_G	6
//by chow  add 
#define SUNXI_GPIO_H	7
#define SUNXI_GPIO_I	8
#define SUNXI_GPIO_J	9
#define SUNXI_GPIO_K	10
#define SUNXI_GPIO_L	11
#define SUNXI_GPIO_M	12
#define SUNXI_GPIO_N	13
#define SUNXI_GPIO_O	14

#define GPIO_BANK(pin)			((pin) >> 5)
#define GPIO_NUM(pin)			((pin) & 0x1F)

#define GPIO_CFG_INDEX(pin)		(((pin) & 0x1F) >> 3)
#define GPIO_CFG_OFFSET(pin)	((((pin) & 0x1F) & 0x7) << 2)

#define GPIO_PUL_INDEX(pin)		(((pin) & 0x1F )>> 4) 
#define GPIO_PUL_OFFSET(pin)	(((pin) & 0x0F) << 1)

/* GPIO bank sizes */
#define SUNXI_GPIO_A_NR	(32)
#define SUNXI_GPIO_B_NR	(32)
#define SUNXI_GPIO_C_NR	(32)
#define SUNXI_GPIO_D_NR	(32)
#define SUNXI_GPIO_E_NR	(32)
#define SUNXI_GPIO_F_NR	(32)
#define SUNXI_GPIO_G_NR	(32)
//BY CHOW add
#define SUNXI_GPIO_H_NR	(32)
#define SUNXI_GPIO_I_NR	(32)
#define SUNXI_GPIO_J_NR	(32)
#define SUNXI_GPIO_K_NR	(32)
#define SUNXI_GPIO_L_NR	(32)
#define SUNXI_GPIO_M_NR	(32)
#define SUNXI_GPIO_N_NR	(32)
#define SUNXI_GPIO_O_NR	(32)
//

#define SUNXI_GPIO_NEXT(__gpio) ((__gpio##_START)+(__gpio##_NR)+0)

enum sunxi_gpio_number {
	SUNXI_GPIO_A_START = 0,
	SUNXI_GPIO_B_START = SUNXI_GPIO_NEXT(SUNXI_GPIO_A), //32
	SUNXI_GPIO_C_START = SUNXI_GPIO_NEXT(SUNXI_GPIO_B), //64
	SUNXI_GPIO_D_START = SUNXI_GPIO_NEXT(SUNXI_GPIO_C), //96
	SUNXI_GPIO_E_START = SUNXI_GPIO_NEXT(SUNXI_GPIO_D), //128
	SUNXI_GPIO_F_START = SUNXI_GPIO_NEXT(SUNXI_GPIO_E), //160
	SUNXI_GPIO_G_START = SUNXI_GPIO_NEXT(SUNXI_GPIO_F), //192
// BY CHOW  ADD
	SUNXI_GPIO_H_START = SUNXI_GPIO_NEXT(SUNXI_GPIO_G), //224	
	SUNXI_GPIO_I_START = SUNXI_GPIO_NEXT(SUNXI_GPIO_H), //256
	SUNXI_GPIO_J_START = SUNXI_GPIO_NEXT(SUNXI_GPIO_I), //288	
	SUNXI_GPIO_K_START = SUNXI_GPIO_NEXT(SUNXI_GPIO_J), //320
	SUNXI_GPIO_L_START = SUNXI_GPIO_NEXT(SUNXI_GPIO_K), //352
	SUNXI_GPIO_M_START = SUNXI_GPIO_NEXT(SUNXI_GPIO_L), //384
	SUNXI_GPIO_N_START = SUNXI_GPIO_NEXT(SUNXI_GPIO_M), //448
	SUNXI_GPIO_O_START = SUNXI_GPIO_NEXT(SUNXI_GPIO_N), //448+32
};

/* SUNXI GPIO number definitions */
#define SUNXI_GPA(_nr) (SUNXI_GPIO_A_START + (_nr))
#define SUNXI_GPB(_nr) (SUNXI_GPIO_B_START + (_nr))
#define SUNXI_GPC(_nr) (SUNXI_GPIO_C_START + (_nr))
#define SUNXI_GPD(_nr) (SUNXI_GPIO_D_START + (_nr))
#define SUNXI_GPE(_nr) (SUNXI_GPIO_E_START + (_nr))
#define SUNXI_GPF(_nr) (SUNXI_GPIO_F_START + (_nr))
#define SUNXI_GPG(_nr) (SUNXI_GPIO_G_START + (_nr))
#define SUNXI_GPH(_nr) (SUNXI_GPIO_H_START + (_nr))
#define SUNXI_GPI(_nr) (SUNXI_GPIO_I_START + (_nr))
//add by chow
#define SUNXI_GPJ(_nr) (SUNXI_GPIO_J_START + (_nr))
#define SUNXI_GPK(_nr) (SUNXI_GPIO_K_START + (_nr))
#define SUNXI_GPL(_nr) (SUNXI_GPIO_L_START + (_nr))
#define SUNXI_GPM(_nr) (SUNXI_GPIO_M_START + (_nr))
#define SUNXI_GPN(_nr) (SUNXI_GPIO_N_START + (_nr))
#define SUNXI_GPO(_nr) (SUNXI_GPIO_O_START + (_nr))

/* GPIO pin function config */
#define SUNXI_GPIO_INPUT	(0)
#define SUNXI_GPIO_OUTPUT	(1)
#define SUNXI_GPIO_PER		(2)

#define SUNXI_PULL_NONE		(0)
#define SUNXI_PULL_UP		(1)
#define SUNXI_PULL_DOWN		(2)

#define SUNXI_LOW			(0)
#define SUNXI_HIGH			(1)

extern int sunxi_gpio_init(void);
extern int sunxi_gpio_set_cfgpin(uint32_t pin, uint8_t val); // sunxi_gpio_set_cfgpin(pin, SUNXI_GPIO_OUTPUT)
extern int sunxi_gpio_get_cfgpin(uint32_t pin); 
extern int sunxi_gpio_input(uint32_t pin); // get value
extern int sunxi_gpio_output(uint32_t pin, uint8_t val); // set value
extern int sunxi_gpio_pullup(uint32_t pin, uint8_t pull);
extern void sunxi_gpio_close(void);

#endif // _GPIO_LIB_H_ 