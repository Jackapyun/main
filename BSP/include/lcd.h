#ifndef LCD_H
#define LCD_H

#include "pico/stdlib.h"

#define LCD_SPI_RX_PIN      12
#define LCD_SPI_TX_PIN      15
#define LCD_SPI_SCK_PIN     14
#define LCD_SPI_CSN_PIN     13
#define LCD_SPI_DC_PIN      9
#define LCD_SPI_RES_PIN     10
#define LCD_SPI_BLE_PIN     11

#define LCD_WIDTH           240
#define LCD_HEIGHT          240

void lcd_init(void);

#endif