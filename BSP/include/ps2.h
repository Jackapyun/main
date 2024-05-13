#ifndef PS2_H
#define PS2_H

#include "pico/stdlib.h"

// 摇杆扫描返回值定义
#define XLEFT       1   // X轴左推
#define XRIGHT      2   // X轴右推
#define YBEFORE     3   // Y轴前推
#define YAFTER      4   // Y轴后推
#define TOPLEFT     5   // 斜向左上推
#define TOPRIGHT    6   // 斜向右上推
#define LOWLEFT     7   // 斜向左下推
#define LOWRIGHT    8   // 斜向右下推
#define ZDOWN       9   // Z轴按下

#define PRESS_PIN   22

void ps2_press_init(void);
void ps2_xy_init(void);
void ps2_init(void);
u_int16_t get_adc_value(u_int8_t ch,u_int8_t times);
u_int8_t Ps2_read(void);

#endif