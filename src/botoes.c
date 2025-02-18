#include "../includes/botoes.h"
#include "../includes/controle_leds.h"
#include "../includes/display.h"
#include <stdio.h>

volatile bool botao_joystick_pressionado = false;
volatile bool botao_a_pressionado = false;
volatile bool estado_led_verde = false;
uint8_t estilo_borda = 0;

bool debounce(uint gpio) {
    static uint32_t ultimo_tempo = 0;
    uint32_t agora = to_ms_since_boot(get_absolute_time());
    if (agora - ultimo_tempo < 200) { // 200ms de debounce
        return false;
    }
    if (!gpio_get(gpio)) { // Verifica se o botão ainda está pressionado
        ultimo_tempo = agora;
        return true;
    }
    return false;
}

void interrupcao_botao(uint gpio, uint32_t eventos) {
  if (eventos & GPIO_IRQ_EDGE_FALL) {
      printf("Interrupção acionada no pino %d\n", gpio);
      if (debounce(gpio)) {
          if (gpio == PINO_BOTAO_JOYSTICK) {
              botao_joystick_pressionado = true;
              printf("Botão do joystick pressionado\n");
          } else if (gpio == PINO_BOTAO_A) {
              botao_a_pressionado = true;
              printf("Botão A pressionado\n");
          }
      }
  }
}

// **Função separada para inicializar apenas o botão do joystick**
void botoes_init() {
  // Inicializa o botão do joystick
  gpio_init(PINO_BOTAO_JOYSTICK);
  gpio_set_dir(PINO_BOTAO_JOYSTICK, GPIO_IN);
  gpio_pull_up(PINO_BOTAO_JOYSTICK);
  gpio_set_irq_enabled_with_callback(PINO_BOTAO_JOYSTICK, GPIO_IRQ_EDGE_FALL, true, &interrupcao_botao);
  printf("Botão do joystick inicializado no pino %d\n", PINO_BOTAO_JOYSTICK);

  // Inicializa o botão A
  gpio_init(PINO_BOTAO_A);
  gpio_set_dir(PINO_BOTAO_A, GPIO_IN);
  gpio_pull_up(PINO_BOTAO_A);
  gpio_set_irq_enabled_with_callback(PINO_BOTAO_A, GPIO_IRQ_EDGE_FALL, true, &interrupcao_botao);
  printf("Botão A inicializado no pino %d\n", PINO_BOTAO_A);
}

// **Função para tratar apenas o botão do joystick**
void botoes_tratar_joystick() {
    if (botao_joystick_pressionado) {
        printf("Tratando botão do joystick\n");
        botao_joystick_pressionado = false;
        estado_led_verde = !estado_led_verde;
        gpio_put(PINO_LED_VERDE, estado_led_verde);
        estilo_borda = (estilo_borda + 1) % 3;
        display_desenhar_borda(estilo_borda);
        printf("Botão do joystick pressionado! LED Verde: %d, Estilo Borda: %d\n", estado_led_verde, estilo_borda);
    }
}

// **Função para tratar apenas o botão A**
void botoes_tratar_a() {
    if (botao_a_pressionado) {
        printf("Tratando botão A\n");
        botao_a_pressionado = false;
        pwm_habilitado = !pwm_habilitado;
        printf("Botão A pressionado! PWM Habilitado: %d\n", pwm_habilitado);
    }
}