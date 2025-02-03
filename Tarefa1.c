#include "pico/stdlib.h"
#include <stdio.h>

const uint LED_VERMELHO = 11;
const uint LED_AMARELO = 12;
const uint LED_VERDE = 13;

int main() {
    stdio_init_all();
    sleep_ms(1000);

    gpio_init(LED_VERMELHO);
    gpio_init(LED_AMARELO);
    gpio_init(LED_VERDE);
    
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_set_dir(LED_AMARELO, GPIO_OUT);
    gpio_set_dir(LED_VERDE, GPIO_OUT);

    while (true) {
        gpio_put(LED_VERMELHO, 1);
        printf("Vermelho\n");
        sleep_ms(3000);
        gpio_put(LED_VERMELHO, 0);

        gpio_put(LED_AMARELO, 1);
        printf("Amarelo\n");
        sleep_ms(3000);
        gpio_put(LED_AMARELO, 0);

        gpio_put(LED_VERDE, 1);
        printf("Verde\n");
        sleep_ms(3000);
        gpio_put(LED_VERDE, 0);
    }
}