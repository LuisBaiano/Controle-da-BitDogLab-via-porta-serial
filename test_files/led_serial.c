
#include <stdio.h>
#include "pico/stdlib.h"

#define GPIO_LED_GREEN 11
#define GPIO_LED_BLUE 12
#define GPIO_LED_RED 13
#define GPIO_BUZZER 21

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
}

// função para desligar os leds
void turn_off_leds() {
    gpio_put(GPIO_LED_GREEN, 0);
    gpio_put(GPIO_LED_BLUE, 0);
    gpio_put(GPIO_LED_RED, 0);
}


// Função para o controle dos leds e do BUZZER conforme escolha feita no menu
void control_leds_and_bUZZER(int option) {
    switch (option) {
        case 1:
            turn_off_leds();
            gpio_put(GPIO_LED_GREEN, 1);
            printf("Led Verde ligado.\n");
            break;
        case 2:
            turn_off_leds();
            gpio_put(GPIO_LED_BLUE, 1);
            printf("Led azul ligado.\n");
            break;
        case 3:
            turn_off_leds();
            gpio_put(GPIO_LED_RED, 1);
            printf("Led Vermelho ligado.\n");
            break;
        case 4:
            gpio_put(GPIO_LED_GREEN, 1);
            gpio_put(GPIO_LED_BLUE, 1);
            gpio_put(GPIO_LED_RED, 1);
            printf("Todos os Leds ligados (Branco).\n");
            break;
        case 5:
            gpio_put(GPIO_LED_GREEN, 0);
            gpio_put(GPIO_LED_BLUE, 0);
            gpio_put(GPIO_LED_RED, 0);
            printf("Todos os Leds desligados.\n");
            break;
        case 6:
            gpio_put(GPIO_BUZZER, 1);
            printf("BUZZER (campainha) acionado por 2 segundos.\n");
            sleep_ms(2000);
            gpio_put(GPIO_BUZZER, 0);
            break;
        default:
            printf("opção invalida! tente novamente!\n");
            break;
    }
}

int main() {
    stdio_init_all();
    init_gpio();

    int option;

    printf("Controle da BitDogLab iniciado!\n");

// menu a ser exibido na porta serial para controle da placa
    while (1) {
        printf("\nMenu:\n 1 - Ligar LED Verde\n 2 - Ligar LED azul\n 3 - Ligar LED Vermelho\n 4 - Ligar todos os LEDs (Branco)\n 5 - Desligar todos os LEDs\n 6 - Acionar BUZZER\n Digite a option desejada: ");
        scanf("%d", &option);
        control_leds_and_bUZZER(option);
    }
    return 0;
}

