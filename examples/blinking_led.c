#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // sleep, usleep
#include <signal.h> // signal
static volatile sig_atomic_t stop;
static void interrupt_handler(int sig)
{
	stop = 1;
	printf("\nStopping...\n");
}

#define ORANGEPI_WIN 1
#include "gpio_table.h" // sunxi_gpio_lib.h

static uint32_t led_pin = SUNXI_GPIO_PIN_07;

int main(int argc, const char *argv[])
{
	signal(SIGINT, interrupt_handler);
	signal(SIGTERM, interrupt_handler);
	signal(SIGABRT, interrupt_handler);
	signal(SIGQUIT, interrupt_handler);
	signal(SIGHUP, interrupt_handler);

	printf("sunxi_gpio_init(): ");
	if (sunxi_gpio_init() != 0)
	{
		printf("failed\n");
		return -1;
	} else {
		printf("success\n");
		stop = 0;
	}

	// configure pin for output
	if (sunxi_gpio_set_cfgpin(led_pin, SUNXI_GPIO_OUTPUT) != 0)
	{
		stop = 1;
		printf("sunxi_gpio_set_cfgpin(%d, SUNXI_GPIO_OUTPUT) failed!\n", led_pin);
	}

	while (!stop)
	{
		// on
		sunxi_gpio_output(led_pin, SUNXI_HIGH);
		usleep(1000000); // == sleep(1)

		// off
		sunxi_gpio_output(led_pin, SUNXI_LOW);
		usleep(1000000);
	}

	sunxi_gpio_close();

	return 0;
}