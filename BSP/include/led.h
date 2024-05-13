#ifndef LED_H
#define LED_H

#include "pico/stdlib.h"

void led_init(void);

#define LED_ON          gpio_put(PICO_DEFAULT_LED_PIN, 1)
#define LED_OFF         gpio_put(PICO_DEFAULT_LED_PIN, 0)
#define LED_ROLL        gpio_put(PICO_DEFAULT_LED_PIN, 1-gpio_get(PICO_DEFAULT_LED_PIN))

#endif