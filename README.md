# Semáforo com Temporizador - Tarefa 1

Implementação de um semáforo utilizando Raspberry Pi Pico W com LEDs e temporizador.

## Funcionalidades

- Controle sequencial de 3 LEDs (vermelho, amarelo e verde)
- Temporização de 3 segundos para cada estado
- Comunicação serial para monitoramento

## Hardware

- Raspberry Pi Pico W
- 3 LEDs (vermelho, amarelo, verde)
- 3 Resistores de 330Ω

## Pinos Utilizados

- LED Vermelho: GPIO11
- LED Amarelo: GPIO12  
- LED Verde: GPIO13

## Compilação

```bash
mkdir build
cd build
cmake ..
make
