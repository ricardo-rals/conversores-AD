#include "../includes/joystick.h"
#include "hardware/adc.h"

#define PINO_JOYSTICK_X 26
#define PINO_JOYSTICK_Y 27

void joystick_init()
{
    adc_gpio_init(PINO_JOYSTICK_X);
    adc_gpio_init(PINO_JOYSTICK_Y);
}

uint16_t ler_joystick_x()
{
    adc_select_input(1);
    return adc_read();
}
uint16_t ler_joystick_y()
{
    adc_select_input(0);
    return adc_read();
}