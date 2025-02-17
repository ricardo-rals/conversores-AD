#include "../includes/controle_leds.h"
#include "hardware/pwm.h"

#define PINO_LED_VERMELHO 11
#define PINO_LED_VERDE 12
#define PINO_LED_AZUL 13

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
  } else {
    pwm_set_gpio_level(PINO_LED_VERMELHO, 0);
    pwm_set_gpio_level(PINO_LED_AZUL, 0);
  }
}