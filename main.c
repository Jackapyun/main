#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/clocks.h"
#include "hardware/spi.h"

#include "FreeRTOS.h"
#include "task.h"

#include "led.h"
#include "btimer.h"
#include "ps2.h"
#include "lcd.h"
#include "st7789.h"

int main()
{
    // clock initialization
    set_sys_clock_khz(PLL_SYS_KHZ, true);
    clock_configure(
        clk_peri,
        0,                                                // No glitchless mux
        CLOCKS_CLK_PERI_CTRL_AUXSRC_VALUE_CLKSRC_PLL_SYS, // System PLL on AUX mux
        PLL_SYS_KHZ * 1000,                               // Input frequency
        PLL_SYS_KHZ * 1000                                // Output (must be same as no divider)
    );
    
    // System default initialization
    stdio_init_all();
    printf("Measuring system clock with frequency counter:");
    printf("%u kHz\r\n", frequency_count_khz(CLOCKS_FC0_SRC_VALUE_CLK_SYS));
    printf("system init finish!\r\n");

    //LED initialization
    led_init();
    // basic timer initialization
    basic_timer_init(500);
    // lcd spi initialization
    lcd_init();
    // ps2 pressing and shanking initialization
    ps2_init();

    while(1){
        st7789_fill(0xffff);
        sleep_ms(1000);
        st7789_fill(0x0000);
        sleep_ms(1000);
    }

    return 0;
}


