#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/pwm.h"
#include "hardware/gpio.h"
#include "hardware/irq.h"

#include "./includes/ssd1306.h"
#include "./includes/joystick.h"
#include "./includes/controle_leds.h"
#include "./includes/botoes.h"
#include "./includes/display.h"

int main() {
    stdio_init_all();

    adc_init();
    joystick_init();
    controle_leds_init();
    botoes_init();
    display_init();

    int posicao_x = (LARGURA_DISPLAY - TAMANHO_QUADRADO) / 2;
    int posicao_y = (ALTURA_DISPLAY - TAMANHO_QUADRADO) / 2;
    while (true) {
        uint16_t valor_x = ler_joystick_x();
        uint16_t valor_y = ler_joystick_y();

        controle_leds_atualizar(valor_x, valor_y);

        posicao_x = (valor_x * (LARGURA_DISPLAY - TAMANHO_QUADRADO)) / 4095;
        posicao_y = ((4095 - valor_y) * (ALTURA_DISPLAY - TAMANHO_QUADRADO)) / 4095;
        display_atualizar(posicao_x, posicao_y);
        
        // printf("X: %d, Y: %d\n", valor_x, valor_y);

        botoes_tratar();

        sleep_ms(10);
    }

    return 0;
}
