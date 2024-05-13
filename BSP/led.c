#include <stdio.h>
#include "pico/stdlib.h"
#include "led.h"

void led_init(void){

    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_put(LED_PIN, 1);
}