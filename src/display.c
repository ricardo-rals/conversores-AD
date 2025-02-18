#include "../includes/display.h"
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include <stdio.h>

ssd1306_t display;

void display_init() {
    i2c_init(i2c1, 400 * 1000);
    gpio_set_function(PINO_I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(PINO_I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(PINO_I2C_SDA);
    gpio_pull_up(PINO_I2C_SCL);

    ssd1306_init(&display, LARGURA_DISPLAY, ALTURA_DISPLAY, false, 0x3C, i2c1);
    ssd1306_config(&display);
    ssd1306_fill(&display, false);
    ssd1306_send_data(&display);
}

void display_atualizar(int x, int y) {
    ssd1306_fill(&display, false);
    ssd1306_rect(&display, y, x, TAMANHO_QUADRADO, TAMANHO_QUADRADO, true, true);
    ssd1306_send_data(&display);
    // printf("Posição no display - X: %d, Y: %d\n", x, y);
}

void display_desenhar_borda(uint8_t estilo) {
    ssd1306_rect(&display, 0, 0, LARGURA_DISPLAY, ALTURA_DISPLAY, true, false);
    ssd1306_send_data(&display);
}