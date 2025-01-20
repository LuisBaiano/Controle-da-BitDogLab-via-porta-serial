/*
Lista de comandos seriais
- REDLEDON
- GREENLEDON
- BLUELEDON
- ALLLEDSON
- ALLLEDSOFF
- BUZZERON
*/


#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"

//GPIO
#define GPIO_LED_GREEN 11
#define GPIO_LED_BLUE 12
#define GPIO_LED_RED 13
#define GPIO_BUZZER 21

//COMMANDS
#define COMMAND_RED_LED_ON "RED_LED_ON"
#define COMMAND_GREEN_LED_ON "GREEN_LED_ON"
#define COMMAND_BLUE_LED_ON "BLUE_LED_ON"
#define COMMAND_ALL_LEDS_ON "ALL_LEDS_ON"
#define COMMAND_ALL_LEDS_OFF "ALL_LEDS_OFF"
#define COMMAND_BUZZER_ON "BUZZER_ON"

#define MAX_COMMAND_LENGHT 1024
// função para iniciar as portas gpio
void init_gpio() {
    gpio_init(GPIO_LED_GREEN);
    gpio_set_dir(GPIO_LED_GREEN, GPIO_OUT);

    gpio_init(GPIO_LED_BLUE);
    gpio_set_dir(GPIO_LED_BLUE, GPIO_OUT);

    gpio_init(GPIO_LED_RED);
    gpio_set_dir(GPIO_LED_RED, GPIO_OUT);

    gpio_init(GPIO_BUZZER);
    gpio_set_dir(GPIO_BUZZER, GPIO_OUT);
    gpio_put(GPIO_BUZZER, 0);
}

// função para desligar os leds
void turn_off_leds() {
    gpio_put(GPIO_LED_GREEN, 0);
    gpio_put(GPIO_LED_BLUE, 0);
    gpio_put(GPIO_LED_RED, 0);
}

/*
*   @brief Funcao de configuracao do PWM no pino do buzzer com a frequência especificada
*   @param pin - pino do componente a ser modulado
*   @param frequency - frequencia de modulacao
*/
void buzzer_set_frequency(uint pin, uint frequency){
    // Obter o slice do PWM associado ao pino
    uint slice_num = pwm_gpio_to_slice_num(pin);

    // Configurar o pino como saída de PWM
    gpio_set_function(pin, GPIO_FUNC_PWM);

    // Configurar o PWM com frequência desejada
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, clock_get_hz(clk_sys) / (frequency * 4096)); // Calcula divisor do clock

    pwm_init(slice_num, &config, true);
    pwm_set_gpio_level(pin, 0); // Inicializa com duty cycle 0 (sem som)
}

/*
*   @brief // Função para tocar o buzzer por um tempo especificado (em milissegundos)
*/
void buzzer_play(uint32_t duration){
    buzzer_set_frequency(GPIO_BUZZER, 3350);
    pwm_set_gpio_level(GPIO_BUZZER, 2048);
    sleep_ms(duration);
    pwm_set_gpio_level(GPIO_BUZZER, 0);
}

int main() {
    stdio_init_all();
    init_gpio();

    char input_buffer[MAX_COMMAND_LENGHT];

    while (1) {
        scanf("%s", &input_buffer);
        printf("Command: %s\n", input_buffer);

        turn_off_leds();

        if(!strcmp(input_buffer, COMMAND_RED_LED_ON)){
            gpio_put(GPIO_LED_RED, 1);
        }else if (!strcmp(input_buffer, COMMAND_GREEN_LED_ON)){
            gpio_put(GPIO_LED_GREEN, 1);
        }else if (!strcmp(input_buffer, COMMAND_BLUE_LED_ON)){
            gpio_put(GPIO_LED_BLUE, 1);
        }else if (!strcmp(input_buffer, COMMAND_ALL_LEDS_ON)){
            gpio_put(GPIO_LED_GREEN, 1);
            gpio_put(GPIO_LED_RED, 1);
            gpio_put(GPIO_LED_BLUE, 1);
        }else if (!strcmp(input_buffer, COMMAND_ALL_LEDS_OFF)){
            gpio_put(GPIO_LED_GREEN, 0);
            gpio_put(GPIO_LED_RED, 0);
            gpio_put(GPIO_LED_BLUE, 0);
        }else if (!strcmp(input_buffer, COMMAND_BUZZER_ON)){
            buzzer_play(2000);
        }else{
            printf("Invalid command\n");
        }

    }
    return 0;
}