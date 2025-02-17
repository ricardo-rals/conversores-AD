#ifndef CONTROLE_LEDS_H
#define CONTROLE_LEDS_H

#include "pico/stdlib.h"

void controle_leds_init();
void controle_leds_atualizar(uint16_t valor_x, uint16_t valor_y);

#endif