#include <stdio.h>
#include "pico/stdlib.h"
#include "led.h"

struct repeating_timer basic_timer;

bool basic_timer_callback(struct repeating_timer *t) {
    LED_ROLL;
    return true;
}

void basic_timer_init(int period_ms){
    add_repeating_timer_ms(period_ms, basic_timer_callback, NULL, &basic_timer);
}

