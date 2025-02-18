#include "../includes/controle_leds.h"
#include "../includes/botoes.h"
#include <stdlib.h>
#include "hardware/pwm.h"

volatile bool pwm_habilitado = true;

void configurar_pwm(uint pino) {
  gpio_set_function(pino, GPIO_FUNC_PWM);
  uint slice_num = pwm_gpio_to_slice_num(pino);
  pwm_set_wrap(slice_num, 4095);
  pwm_set_enabled(slice_num, true);
}

void controle_leds_init() {
  configurar_pwm(PINO_LED_VERMELHO);
  configurar_pwm(PINO_LED_VERDE);
  configurar_pwm(PINO_LED_AZUL);
}

void controle_leds_atualizar(uint16_t valor_x, uint16_t valor_y) {
  if (pwm_habilitado) {
    pwm_set_gpio_level(PINO_LED_VERMELHO, abs(valor_x - 2048));
    pwm_set_gpio_level(PINO_LED_AZUL, abs(valor_y - 2048));

    // Lógica para o LED verde (acionado pelo botão)
    if (estado_led_verde) {
      pwm_set_gpio_level(PINO_LED_VERDE, 2048); // Liga o LED verde no máximo
    } else {
      pwm_set_gpio_level(PINO_LED_VERDE, 0); // Desliga o LED verde
    }
  } else {
    pwm_set_gpio_level(PINO_LED_VERMELHO, 0);
    pwm_set_gpio_level(PINO_LED_AZUL, 0);
    pwm_set_gpio_level(PINO_LED_VERDE, 0); // Desliga o LED verde quando o PWM está desabilitado
  }
}