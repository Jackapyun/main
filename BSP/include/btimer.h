#ifndef BTIMER_H
#define BTIMER_H

#include "pico/stdlib.h"

extern struct repeating_timer basic_timer;

bool basic_timer_callback(struct repeating_timer *t);
void basic_timer_init(int period);

#endif