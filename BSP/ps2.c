#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"
#include "ps2.h"

static const float conversion_factor = 3.3f / (1 << 12);

void ps2_press_init(void)
{
    gpio_init(PRESS_PIN);
    gpio_set_dir(PRESS_PIN, GPIO_IN);
    gpio_pull_up(PRESS_PIN);
}

void ps2_xy_init(void)
{
    adc_init();
    adc_gpio_init(26);
    adc_gpio_init(27);
}

void ps2_init(void)
{
    ps2_press_init();
    ps2_xy_init();
}

u_int16_t get_adc_value(u_int8_t ch,u_int8_t times)
{
    u_int32_t temp_val = 0;
    u_int8_t t;
    for(t=0;t<times;t++)
    {
        adc_select_input(ch);
        temp_val += adc_read();
    }
    return temp_val/times;
}

u_int8_t Ps2_read(void)
{
	u_int16_t xValue = 0;   // X轴电压值
	u_int16_t yValue = 0;   // Y轴电压值
	
	xValue = get_adc_value(0,5);   // 获取X轴AD值
	yValue = get_adc_value(1,5);   // 获取Y轴AD值
	
	// X轴右推
	if (xValue >= 3600 && (yValue >= 1800 && yValue <= 2200))
	{
		return XRIGHT;
	}
	// X轴左推
	if (xValue <= 600 && (yValue >= 1800 && yValue <= 2200))
	{
		return XLEFT;
	}
	// Y轴前推
	if (yValue <= 600 && (xValue >= 1800 && xValue <= 2200))
	{
		return YBEFORE;
	}
	// Y轴后推
	if (yValue >= 3600 && (xValue >= 1800 && xValue <= 2200))
	{
		return YAFTER;
	}
	// 斜向右上推
	if (xValue >= 3600 && yValue <= 600)
	{
		return TOPRIGHT;
	}
	// 斜向右下推
	if (xValue >= 3600 && yValue >= 3600)
	{
		return LOWRIGHT;
	}
	// 斜向左上推
	if (xValue <= 600 && yValue <= 600)
	{
		return TOPLEFT;
	}
	// 斜向左下推
	if (xValue <= 600 && yValue >= 3600)
	{
		return LOWLEFT;
	}
	// Z轴按下
	if (gpio_get(PRESS_PIN) == 0)
	{
        sleep_ms(2);
		if (gpio_get(PRESS_PIN) == 0)
		{
			while (!gpio_get(PRESS_PIN));   // 松手检测
			return ZDOWN;
		}
	}
	
	return 0;
}
