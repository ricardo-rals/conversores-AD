# Projeto de Controle de LEDs e Display com Joystick

Este projeto tem como objetivo consolidar os conceitos de uso de conversores analógico-digitais (ADC) no RP2040 e explorar as funcionalidades da placa de desenvolvimento BitDogLab. O sistema utiliza um joystick para controlar a intensidade de LEDs RGB e a posição de um quadrado em um display SSD1306. Além disso, botões adicionais permitem alternar o estado de um LED verde, modificar o estilo da borda do display e habilitar/desabilitar o controle PWM dos LEDs.

---

## **Descrição do Projeto**

### **Funcionalidades Principais**
1. **Controle de LEDs RGB**:
   - O LED Azul tem seu brilho ajustado conforme o valor do eixo Y do joystick.
   - O LED Vermelho tem seu brilho ajustado conforme o valor do eixo X do joystick.
   - Quando o joystick está na posição central (valor 2048), os LEDs permanecem apagados.
   - O brilho dos LEDs aumenta gradualmente à medida que o joystick é movido para os extremos (0 e 4095).
   - Os LEDs são controlados via PWM para permitir variação suave da intensidade luminosa.

2. **Display SSD1306**:
   - Um quadrado de 8x8 pixels é exibido no display, movendo-se proporcionalmente aos valores do joystick.
   - O quadrado é inicialmente centralizado e se move conforme a posição do joystick.

3. **Botão do Joystick**:
   - Alterna o estado do LED Verde a cada acionamento.
   - Modifica o estilo da borda do display a cada novo acionamento.

4. **Botão A**:
   - Ativa ou desativa o controle PWM dos LEDs a cada acionamento.

---

## **Componentes Utilizados**
- **LED RGB**: Conectado às GPIOs 11 (vermelho), 12 (verde) e 13 (azul).
- **Botão do Joystick**: Conectado à GPIO 22.
- **Joystick**: Conectado às GPIOs 26 (eixo X) e 27 (eixo Y).
- **Botão A**: Conectado à GPIO 5.
- **Display SSD1306**: Conectado via I2C (GPIO 14 - SDA, GPIO 15 - SCL).

---

## **Requisitos do Projeto**
1. **Uso de Interrupções**:
   - Todas as funcionalidades relacionadas aos botões devem ser implementadas utilizando rotinas de interrupção (IRQ).

2. **Debouncing**:
   - O tratamento do bouncing dos botões deve ser implementado via software.

3. **Utilização do Display 128x64**:
   - O display deve ser utilizado para exibir o quadrado móvel e as bordas, demonstrando o entendimento do protocolo I2C e do funcionamento do display.

4. **Organização do Código**:
   - O código deve estar bem estruturado, modular e comentado para facilitar o entendimento.

---

## **Estrutura do Código**

### **Arquivos Principais**
- **src/butoes.c**: Implementa a lógica de inicialização e tratamento dos botões, incluindo debouncing e interrupções.
- **src/controle_leds.c**: Controla a intensidade dos LEDs RGB via PWM com base nos valores do joystick.
- **src/display.c**: Gerencia a exibição do quadrado móvel e a borda no display SSD1306.
- **src/joystick.c**: Implementa a leitura dos valores analógicos do joystick.
- **src/ssd1306.c**: Contém as funções básicas para controlar o display SSD1306.
- **conversores-AD.c**: Arquivo principal que inicializa os componentes e executa o loop principal do programa.

---

## **Como Funciona**

1. **Inicialização**:
   - Todos os componentes (joystick, LEDs, botões e display) são inicializados.
   - As interrupções dos botões são configuradas.

2. **Leitura do Joystick**:
   - Os valores analógicos dos eixos X e Y do joystick são lidos.
   - Esses valores são usados para ajustar a intensidade dos LEDs e a posição do quadrado no display.

3. **Atualização do Display**:
   - O quadrado no display é movido conforme a posição do joystick.
   - A borda do display é atualizada conforme o estilo definido pelo botão do joystick.

4. **Controle dos LEDs**:
   - A intensidade dos LEDs é ajustada com base nos valores do joystick.
   - O botão A habilita/desabilita o controle PWM dos LEDs.

5. **Tratamento dos Botões**:
   - O botão do joystick alterna o estado do LED verde e muda o estilo da borda do display.
   - O botão A ativa/desativa o controle PWM dos LEDs.

---

## **Instalação**
1. Clone o repositório:
   ```bash
   git clone https://github.com/ricardo-rals/conversores-AD.git
   cd conversores-AD
   ```

2. Abra o projeto no Visual Studio Code.

3. Configure o SDK do Raspberry Pi Pico W de acordo com a [documentação oficial](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf).

4. Siga as instruções no Visual Studio Code para compilar e carregar o projeto no seu Raspberry Pi Pico.

## Video de Apresentação

Para um guia visual sobre como configurar e executar este projeto, confira este.
[YouTube video](https://youtu.be/l2p6DPXXfL8). 
