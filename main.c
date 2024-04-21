#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/clocks.h"
#include "FreeRTOS.h"
#include "task.h"

void task0(void *param)
{
    static uint32_t cnt = 0;
    while (1) {
        taskENTER_CRITICAL();
        printf("%s cnt: %d\n", __FUNCTION__, cnt ++);
        printf("task %s is runing in core %d\r\n", __FUNCTION__, portGET_CORE_ID());
        taskEXIT_CRITICAL();
        vTaskDelay(1000);
    }
}

void task1(void *param)
{
    static uint32_t cnt = 0;
    while (1) {
        taskENTER_CRITICAL();
        printf("%s cnt: %d\n", __FUNCTION__, cnt ++);
        printf("task %s is runing in core %d\r\n", __FUNCTION__, portGET_CORE_ID());
        taskEXIT_CRITICAL();
        vTaskDelay(1000);
    }
}

void task2(void *para){
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    while (1)
    {
        gpio_put(LED_PIN,1);
        taskENTER_CRITICAL();
        printf("task %s is runing in core %d\r\n", __FUNCTION__, portGET_CORE_ID());
        taskEXIT_CRITICAL();
        vTaskDelay(200);
        gpio_put(LED_PIN,0);
        taskENTER_CRITICAL();
        printf("task %s is runing in core %d\r\n", __FUNCTION__, portGET_CORE_ID());
        taskEXIT_CRITICAL();
        vTaskDelay(500);
    }
}

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
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    TaskHandle_t task0_Handle = NULL;
    xTaskCreate(task0, "task0", configMINIMAL_STACK_SIZE*4, NULL, tskIDLE_PRIORITY + 1, &task0_Handle);
    // UBaseType_t task0_CoreAffinityMask = (1 << 0);
    // vTaskCoreAffinitySet(task0_Handle, task0_CoreAffinityMask); 

    TaskHandle_t task1_Handle = NULL;
    xTaskCreate(task1, "task1", configMINIMAL_STACK_SIZE*4, NULL, tskIDLE_PRIORITY + 2, &task1_Handle);
    // UBaseType_t task1_CoreAffinityMask = (1 << 1);
    // vTaskCoreAffinitySet(task1_Handle, task1_CoreAffinityMask); 

    TaskHandle_t task2_Handle = NULL;
    xTaskCreate(task2, "task2", configMINIMAL_STACK_SIZE*4, NULL, tskIDLE_PRIORITY + 6, &task2_Handle);

    vTaskStartScheduler();

    return 0;
}


