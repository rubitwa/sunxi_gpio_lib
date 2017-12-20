RM ?= rm -f
CFLAGS ?= -Wall
LIBS ?= -lm

all: blinking_led

blinking_led: clean
	$(CC) $(CFLAGS) -o blinking_led ../sunxi_gpio_lib.c blinking_led.c $(LIBS)

clean:
	$(RM) blinking_led