#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/spi.h"
#include "hardware/dma.h"
#include "hardware/pwm.h"
#include "st7789.h"
#include "lcd.h"

const struct st7789_config lcd_config = {
    .spi      = spi1,
    .gpio_din = LCD_SPI_TX_PIN,
    .gpio_clk = LCD_SPI_SCK_PIN,
    .gpio_cs  = LCD_SPI_CSN_PIN,
    .gpio_dc  = LCD_SPI_DC_PIN,
    .gpio_rst = LCD_SPI_RES_PIN,
    .gpio_bl  = LCD_SPI_BLE_PIN,
};
void lcd_init(void)
{
    st7789_init(&lcd_config, (uint16_t)LCD_WIDTH, (uint16_t)LCD_HEIGHT);
}
