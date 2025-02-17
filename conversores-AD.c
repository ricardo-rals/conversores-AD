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

int main() {
    stdio_init_all();

    adc_init();
    joystick_init();
    controle_leds_init();


    while (true) {
        uint16_t valor_x = ler_joystick_x();
        uint16_t valor_y = ler_joystick_y();

        controle_leds_atualizar(valor_x, valor_y);


        printf("X: %d, Y: %d\n", valor_x, valor_y);

        sleep_ms(100);
    }

    return 0;
}
