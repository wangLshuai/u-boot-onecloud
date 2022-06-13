#include <common.h>

#include <amlogic/gpio.h>

typedef enum LED_ID {
	LED_ID_RED = 0,
	LED_ID_GREEN,
	LED_ID_BLUE,
} LED_ID;

typedef enum LED_STATUS {
	LED_STATUS_OFF,
	LED_STATUS_ON,
} LED_STATUS;

void onecloud_led_set(LED_ID id, LED_STATUS status)
{
	int offset = 0;
	int value = 0;

	if(id == LED_ID_RED)
		offset = GPIOAO_2;
	else if(id == LED_ID_GREEN)
		offset = GPIOAO_3;
	else if(id == LED_ID_BLUE)
		offset = GPIOAO_4;
	else
		return;

	if(status == LED_STATUS_OFF)
		value = 0;
	else if(status == LED_STATUS_ON)
		value = 1;
	else
		return;

	amlogic_gpio_direction_output(offset, value);
}

void onecloud_led_init(void)
{
	onecloud_led_set(LED_ID_RED, LED_STATUS_ON);
	onecloud_led_set(LED_ID_GREEN, LED_STATUS_OFF);
	onecloud_led_set(LED_ID_BLUE, LED_STATUS_OFF);
}
