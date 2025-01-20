# Controle de Buzzer e LED RGB com Raspberry Pi Pico W via porta serial

## Sobre o projeto

Este projeto demonstra como controlar LEDs e um buzzer conectados a um microcontrolador RP2040 (Raspberry Pi Pico W) utilizando comandos via terminal serial UART. O código está escrito em C, empregando o Pico SDK, e integra as funcionalidades de ativação e desativação de periféricos através de um menu interativo.

### Colaboradores

- [Camila Pereira](https://github.com/camilaqPereira)
- [Ricardo Rodrigues](https://github.com/ricardorodriguespes17)
- [Marlon Garrido](https://github.com/marlongarrido7)
- [Sérgio Mendes](https://github.com/sergiomnds)
- [Luis Baiano](https://github.com/luisbaiano)
- [Cleber Soares](https://github.com/cleberspjr)
- [Leonardo Rodrigues](https://github.com/engleonardorodrigues)

## Funcionalidades Implementadas

1. **Controle de LEDs RGB**:

   * Acender o LED Verde (GPIO 11);
   * Acender o LED Azul (GPIO 12);
   * Acender o LED Vermelho (GPIO 13);
   * Acender todos os LEDs ao mesmo tempo (luz branca);
   * Desligar todos os LEDs.
2. **Controle do Buzzer**:

   * Ativar o buzzer por 2 segundos (GPIO 21).
3. **Interface de Comando**:

   * Menu interativo para seleção de opções via terminal serial UART.

   ## Configuração do Hardware

   ### Componentes Utilizados


   * **Placa de Desenvolvimento BitDogLab com uma Raspberry Pi Pico W**;
   * **LED RGB** conectado aos GPIOs 11 (vermelho), 12 (verde) e 13 (azul);
   * **Buzzer** conectado ao GPIO 21;
   * **Resistor** de 330 Ω conectado ao LED RGB;
   * Conexões de GND compartilhadas entre os periféricos e o Pico.

   ## Instruções de Uso

   1. Configure o ambiente de desenvolvimento:
      * Instale o **Pico SDK** e configure-o no **VS Code**.
      * Clone este repositório em sua máquina local.
   2. Compile e envie o código para o Raspberry Pi Pico W:
      * Conecte o Pico ao computador via USB;
      * Compile o projeto utilizando o CMake;
      * Faça o upload do binário gerado para o Pico.
   3. Conecte ao terminal serial UART:
      * Utilize o software de terminal PuTTY;
      * Configure a porta serial correta e ajuste a taxa de comunicação.
   4. Interaja com o menu exibido no terminal:
      * Escolha uma opção digitando o número correspondente:
        * **1** - Ligar LED Verde;
        * **2** - Ligar LED Azul;
        * **3** - Ligar LED Vermelho;
        * **4** - Ligar todos os LEDs (Branco);
        * **5** - Desligar todos os LEDs;
        * **6** - Acionar o buzzer por 2 segundos.
