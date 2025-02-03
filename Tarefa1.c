#include "pico/stdlib.h"
#include <stdio.h>

const uint LED_VERMELHO = 11;
const uint LED_AMARELO = 12;
const uint LED_VERDE = 13;

typedef enum {
    VERMELHO,
    AMARELO,
    VERDE
} EstadoSemaforo;

volatile EstadoSemaforo estado_atual = VERMELHO;

bool repeating_timer_callback(struct repeating_timer *t) {
    gpio_put(LED_VERMELHO, 0);
    gpio_put(LED_AMARELO, 0);
    gpio_put(LED_VERDE, 0);
    
    switch(estado_atual) {
        case VERMELHO:
            estado_atual = AMARELO;
            gpio_put(LED_AMARELO, 1);
            printf("Mudança: AMARELO\n");
            break;
        case AMARELO:
            estado_atual = VERDE;
            gpio_put(LED_VERDE, 1);
            printf("Mudança: VERDE\n");
            break;
        case VERDE:
            estado_atual = VERMELHO;
            gpio_put(LED_VERMELHO, 1);
            printf("Mudança: VERMELHO\n");
            break;
    }
    return true;
}

int main() {
    stdio_init_all();
    
    gpio_init(LED_VERMELHO);
    gpio_init(LED_AMARELO);
    gpio_init(LED_VERDE);
    
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_set_dir(LED_AMARELO, GPIO_OUT);
    gpio_set_dir(LED_VERDE, GPIO_OUT);
    
    gpio_put(LED_VERMELHO, 1);
    
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);
    
    while(1) {
        printf("Sistema em execução - Estado atual: %d\n", estado_atual);
        sleep_ms(1000);
    }
}