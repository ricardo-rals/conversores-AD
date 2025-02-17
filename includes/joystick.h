#ifndef JOYSTICK_H
#define JOYSTICK_H

#include "pico/stdlib.h"

void joystick_init();
uint16_t ler_joystick_x();
uint16_t ler_joystick_y();

#endif 