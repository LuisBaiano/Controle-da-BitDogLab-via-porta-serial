# Controle de Buzzer e LED RGB com Raspberry Pi Pico W via porta serial

## Sobre o projeto

Este projeto demonstra como controlar LED RGB e um buzzer conectados Á placa de desenvolvimento BitDogLab utilizando comandos via terminal serial UART. O código está escrito em C, empregando o Pico SDK, e integra as funcionalidades de ativação e desativação de periféricos.

## Colaboradores

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
3. **LISTA DE COMANDOS**:

   Comandos pré-definidos para o controle do LED RGB e do buzzer:
   * RED_LED_ON: aciona o led vermelho
   * GREEN_LED_ON: aciona o led verde
   * BLUE_LED_ON: aciona o led azul
   * ALL_LEDS_ON: aciona todos os leds (cor branca)
   * ALL LEDS_OFF: desativa tiodos os leds
   * BUZZER_ON: aciona o buzzer por 2 segundos

## Demostração


## Configuração do Hardware

   ### Componentes Utilizados


   * **Placa de Desenvolvimento BitDogLab com uma Raspberry Pi Pico W**;
   * **LED RGB** conectado aos GPIOs 11 (vermelho), 12 (verde) e 13 (azul);
   * **Buzzer** conectado ao GPIO 21;
   * Monitor serial PuTTY

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
      * Configure a porta serial correta e ajuste a taxa de comunicação para 115200.
   4. Insira um dos comandos listados anteriormente
