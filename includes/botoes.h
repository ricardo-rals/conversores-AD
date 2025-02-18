#ifndef BOTOES_H
#define BOTOES_H

#include "pico/stdlib.h"

#define PINO_BOTAO_JOYSTICK 22  
#define PINO_BOTAO_A 5
extern volatile bool estado_led_verde;

void botoes_init();
void botoes_tratar_joystick();  // Verifica e trata apenas o joystick
void botoes_tratar_a();  

#endif 