// Bibliotecas necessárias para o projeto
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

// Definição dos pinos
#define SERVO 22
#define LED_B_PIN 12

#define PWM_FREQUENCY 50        // Frequência do PWM para o servo
#define PWM_WRAP 20000          // Valor máximo do contador PWM
#define PWM_DIVISOR 125.0         // Divisor de clock do PWM

#define SERVO_MIN_US 500        // Posição mínima do servo (0°)
#define SERVO_MID_US 1470       // Posição intermediária do servo (90°)
#define SERVO_MAX_US 2400       // Posição máxima do servo (180°)
#define SERVO_STEP_US 5         // Incremento/decremento de posição do servo
#define SERVO_DELAY_MS 10       // Tempo de espera entre os passos do servo

int main()
{
    stdio_init_all();

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}