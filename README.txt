
If ure using this code in driver, uncomment #define SUNXI_GPIO_USE_IOREMAP 1 in sunxi_gpio_lib.h

Pin modes and etc defined in sunxi_gpio_lib.h
For select pin look pdf scheme of ur board and:
int pin1 = SUNXI_GPA(11) // PA11
int pin2 = SUNXI_GPL(14) // PL14

Dont forget init gpio memory pointer
sunxi_gpio_init() 0 - success, not 0 - failed

For set pin mode / get pin mode
sunxi_gpio_set_cfgpin(pin, mode) / sunxi_gpio_get_cfgpin(pin, mode)

For set value / get value
sunxi_gpio_input(pin) / sunxi_gpio_output(pin, value)

For Pull up/down
sunxi_gpio_pullup(pin, pull)

Remove memory ponter
sunxi_gpio_close()
