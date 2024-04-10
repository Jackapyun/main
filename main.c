#include <stdio.h>
#include "pico/stdlib.h"

static unsigned int count = 0;

int main()
{
    stdio_init_all();

    while(1){
        printf("count:%d",count++);
        printf("Hello, world!\r\n");
    }

    return 0;
}
