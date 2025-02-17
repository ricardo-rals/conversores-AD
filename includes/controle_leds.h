#ifndef CONTROLE_LEDS_H
#define CONTROLE_LEDS_H

#include "pico/stdlib.h"

#define PINO_LED_VERMELHO 11
#define PINO_LED_VERDE 12
#define PINO_LED_AZUL 13
extern volatile bool pwm_habilitado;

void controle_leds_init();
void controle_leds_atualizar(uint16_t valor_x, uint16_t valor_y);

#endif