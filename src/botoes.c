#include "../includes/botoes.h"
#include "../includes/controle_leds.h"
#include "../includes/display.h"

volatile bool botao_joystick_pressionado = false;
volatile bool botao_a_pressionado = false;
volatile bool estado_led_verde = false;
uint8_t estilo_borda = 0;

bool debounce(uint gpio) {
  static uint32_t ultimo_tempo = 0;
  uint32_t agora = to_ms_since_boot(get_absolute_time());
  if (agora - ultimo_tempo < 200) {
      return false;
  }
  ultimo_tempo = agora;
  return true;
}


void interrupcao_botao_joystick(uint gpio, uint32_t eventos) {
  if (debounce(gpio)) {
      botao_joystick_pressionado = true;
  }
}

void interrupcao_botao_a(uint gpio, uint32_t eventos) {
  if (debounce(gpio)) {
      botao_a_pressionado = true;
  }
}

void botoes_init() {
  gpio_init(PINO_BOTAO_JOYSTICK);
  gpio_set_dir(PINO_BOTAO_JOYSTICK, GPIO_IN);
  gpio_pull_up(PINO_BOTAO_JOYSTICK);
  gpio_set_irq_enabled_with_callback(PINO_BOTAO_JOYSTICK, GPIO_IRQ_EDGE_FALL, true, &interrupcao_botao_joystick);

  gpio_init(PINO_BOTAO_A);
  gpio_set_dir(PINO_BOTAO_A, GPIO_IN);
  gpio_pull_up(PINO_BOTAO_A);
  gpio_set_irq_enabled_with_callback(PINO_BOTAO_A, GPIO_IRQ_EDGE_FALL, true, &interrupcao_botao_a);
}

void botoes_tratar() {
  if (botao_joystick_pressionado) {
      botao_joystick_pressionado = false;
      estado_led_verde = !estado_led_verde;
      gpio_put(PINO_LED_VERDE, estado_led_verde);
      estilo_borda = (estilo_borda + 1) % 3;
      display_desenhar_borda(estilo_borda);
  }

  if (botao_a_pressionado) {
      botao_a_pressionado = false;
      pwm_habilitado = !pwm_habilitado;
  }
}