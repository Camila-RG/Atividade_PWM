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

// Configura o módulo PMW
void setup_pwm(uint gpio) {
    gpio_set_function(gpio, GPIO_FUNC_PWM);
    uint slice = pwm_gpio_to_slice_num(gpio);
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, PWM_DIVISOR);
    pwm_config_set_wrap(&config, PWM_WRAP);
    pwm_init(slice, &config, true);
}

// Define a posição do servo
void set_servo_position(uint level) {
    pwm_set_gpio_level(SERVO, level);
}

// Converte microsegundos para nível PWM
uint16_t convert_us_to_pwm_level(uint16_t us) {
    return (us * PWM_WRAP) / 20000;
}

// Função para ajustar o brilho do LED com base na posição do servo
void set_led_brightness(uint16_t us) {
    if (us == SERVO_MIN_US) {
        pwm_set_gpio_level(LED_B_PIN, 0);
    } else {
        uint16_t brightness = convert_us_to_pwm_level(SERVO_MAX_US - us);  
        pwm_set_gpio_level(LED_B_PIN, brightness);
    }
}

// Função que realiza a movimentação cíclica do servomotor entre os ângulos de 0 a 180 graus
void move_servo_cycle() {
    for (uint16_t pos = SERVO_MIN_US; pos <= SERVO_MAX_US; pos += SERVO_STEP_US) {
        set_servo_position(convert_us_to_pwm_level(pos));
        set_led_brightness(pos); // Sincroniza o brilho do LED com a posição do servo
        sleep_ms(SERVO_DELAY_MS);
    }

    for (uint16_t pos = SERVO_MAX_US; pos >= SERVO_MIN_US; pos -= SERVO_STEP_US) {
        set_servo_position(convert_us_to_pwm_level(pos));
        set_led_brightness(pos); // Sincroniza o brilho do LED com a posição do servo
        sleep_ms(SERVO_DELAY_MS);
    }
}

int main() {
    stdio_init_all();
    setup_pwm(SERVO); // Inicializa PWM para o servo
    setup_pwm(LED_B_PIN); // Inicializa PWM para o LED

    // 1. Mover servo para 180° e ajustar LED
    set_servo_position(convert_us_to_pwm_level(SERVO_MAX_US)); 
    set_led_brightness(SERVO_MAX_US);
    sleep_ms(5000); // Aguarda 5 segundos na posição 180°

    // 2. Mover servo para 90° e ajustar LED
    set_servo_position(convert_us_to_pwm_level(SERVO_MID_US)); 
    set_led_brightness(SERVO_MID_US);
    sleep_ms(5000); // Aguarda 5 segundos na posição 90°

    // 3. Mover servo para 0° e ajustar LED
    set_servo_position(convert_us_to_pwm_level(SERVO_MIN_US)); 
    set_led_brightness(SERVO_MIN_US);
    sleep_ms(5000); // Aguarda 5 segundos na posição 0°

    // 4. Executa o movimento cíclico suave do servo e LED
    move_servo_cycle();

    // 5. Movimentação periódica do servo entre 0° e 180° com sincronização com o LED
    while (true) {
        move_servo_cycle(); // Movimenta o servo de 0 a 180° e vice-versa periodicamente
    }
}