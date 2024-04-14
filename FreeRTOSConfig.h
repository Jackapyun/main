#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

/* include files*/

/* Hardware description related definitions. **********************************/
#define PLL_SYS_KHZ                                 (133 * 1000)
#define configCPU_CLOCK_HZ                          PLL_SYS_KHZ*1000
#define configTICK_RATE_HZ                          1000
#define configUSE_PREEMPTION                        1
#define configUSE_TIME_SLICING                      1
#define configUSE_PORT_OPTIMISED_TASK_SELECTION     0
#define configUSE_TICKLESS_IDLE                     0
#define configMAX_PRIORITIES                        5            
#define configMINIMAL_STACK_SIZE                    128
#define configMAX_TASK_NAME_LEN                     16
#define configTICK_TYPE_WIDTH_IN_BITS               TICK_TYPE_WIDTH_32_BITS
#define configIDLE_SHOULD_YIELD                     1
#define configTASK_NOTIFICATION_ARRAY_ENTRIES       3
#define configQUEUE_REGISTRY_SIZE                   10
#define configENABLE_BACKWARD_COMPATIBILITY         0
#define configNUM_THREAD_LOCAL_STORAGE_POINTERS     0
#define configUSE_MINI_LIST_ITEM                    1
#define configSTACK_DEPTH_TYPE                      uint16_t
#define configMESSAGE_BUFFER_LENGTH_TYPE            size_t
#define configHEAP_CLEAR_MEMORY_ON_FREE             1
#define configSTATS_BUFFER_MAX_LENGTH               0xFFFF
#define configUSE_NEWLIB_REENTRANT                  0

/* Software timer related definitions. ****************************************/
#define configUSE_TIMERS                            1
#define configTIMER_TASK_PRIORITY                   ( configMAX_PRIORITIES - 1 )
#define configTIMER_TASK_STACK_DEPTH                ( configMINIMAL_STACK_SIZE * 2 ) 
#define configTIMER_QUEUE_LENGTH                    10

/* Memory allocation related definitions. *************************************/
#define configSUPPORT_STATIC_ALLOCATION             0
#define configSUPPORT_DYNAMIC_ALLOCATION            1
#define configTOTAL_HEAP_SIZE                       ((size_t)(10 * 1024))
#define configAPPLICATION_ALLOCATED_HEAP            0
#define configSTACK_ALLOCATION_FROM_SEPARATE_HEAP   0
#define configENABLE_HEAP_PROTECTOR                 0

/* Interrupt nesting behaviour configuration. *********************************/
#ifdef __NVIC_PRIO_BITS
    #define configPRIO_BITS __NVIC_PRIO_BITS
#else
    #define configPRIO_BITS 4
#endif
/* 中断最低优先级 */
#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY         15  
/* FreeRTOS可管理的最高中断优先级 */                
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY    5        
#define configKERNEL_INTERRUPT_PRIORITY             ( configLIBRARY_LOWEST_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )
#define configMAX_SYSCALL_INTERRUPT_PRIORITY        ( configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << (8 - configPRIO_BITS)
#define configMAX_API_CALL_INTERRUPT_PRIORITY       configMAX_SYSCALL_INTERRUPT_PRIORITY

/* Use Pico SDK ISR handlers */
#define vPortSVCHandler                             isr_svcall
#define xPortPendSVHandler                          isr_pendsv
#define xPortSysTickHandler                         isr_systick

/* Hook and callback function related definitions. ****************************/
#define configUSE_IDLE_HOOK                         0
#define configUSE_TICK_HOOK                         0
#define configUSE_MALLOC_FAILED_HOOK                0
#define configUSE_DAEMON_TASK_STARTUP_HOOK          0
#define configUSE_SB_COMPLETED_CALLBACK             0
#define configCHECK_FOR_STACK_OVERFLOW              0

/* Run time and task stats gathering related definitions. *********************/
#define configGENERATE_RUN_TIME_STATS               0
#define configUSE_TRACE_FACILITY                    0
#define configUSE_STATS_FORMATTING_FUNCTIONS        0

/* Co-routine related definitions. ********************************************/
#define configUSE_CO_ROUTINES                       0
#define configMAX_CO_ROUTINE_PRIORITIES             0

/* Debugging assistance. ******************************************************/
/* Define to trap errors during development. */
#include "assert.h"
#define configASSERT( x )                           assert(x)

/* SMP( Symmetric MultiProcessing ) Specific Configuration definitions. *******/
#define configNUMBER_OF_CORES                       2
#define configRUN_MULTIPLE_PRIORITIES               1
#define configUSE_CORE_AFFINITY                     1
#define configUSE_TASK_PREEMPTION_DISABLE           0
#define configUSE_PASSIVE_IDLE_HOOK                 0
#define configTIMER_SERVICE_TASK_CORE_AFFINITY      tskNO_AFFINITY

/* Definitions that include or exclude functionality. *************************/
/* Set the following configUSE_* constants to 1 to include the named feature in
 * the build, or 0 to exclude the named feature from the build. */
#define configUSE_TASK_NOTIFICATIONS                1
#define configUSE_MUTEXES                           1
#define configUSE_RECURSIVE_MUTEXES                 1
#define configUSE_COUNTING_SEMAPHORES               1
#define configUSE_QUEUE_SETS                        1
#define configUSE_APPLICATION_TASK_TAG              1

/* Set the following INCLUDE_* constants to 1 to incldue the named API function,
 * or 0 to exclude the named API function.  Most linkers will remove unused
 * functions even when the constant is 1. */
#define INCLUDE_vTaskPrioritySet                    1
#define INCLUDE_uxTaskPriorityGet                   1
#define INCLUDE_vTaskDelete                         1
#define INCLUDE_vTaskSuspend                        1
#define INCLUDE_xResumeFromISR                      1
#define INCLUDE_vTaskDelayUntil                     1
#define INCLUDE_vTaskDelay                          1
#define INCLUDE_xTaskGetSchedulerState              1
#define INCLUDE_xTaskGetCurrentTaskHandle           1
#define INCLUDE_uxTaskGetStackHighWaterMark         1
#define INCLUDE_xTaskGetIdleTaskHandle              1
#define INCLUDE_eTaskGetState                       1
#define INCLUDE_xEventGroupSetBitFromISR            1
#define INCLUDE_xTimerPendFunctionCall              1
#define INCLUDE_xTaskAbortDelay                     1
#define INCLUDE_xTaskGetHandle                      1
#define INCLUDE_xTaskResumeFromISR                  1

/* Definitions that Pico related definitions. ********************************/
#define LIB_PICO_MULTICORE                          1
#define LIB_PICO_SYNC                               1
#define LIB_PICO_TIME                               1
#define configSUPPORT_PICO_SYNC_INTEROP             1
#define configSUPPORT_PICO_TIME_INTEROP             1

/* A header file that defines trace macro can be included here. */

#endif /* FREERTOS_CONFIG_H */
