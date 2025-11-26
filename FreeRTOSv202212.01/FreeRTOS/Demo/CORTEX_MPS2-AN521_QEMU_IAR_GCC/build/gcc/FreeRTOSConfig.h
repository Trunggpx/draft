#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

/*-----------------------------------------------------------
 * Application specific definitions.
 *----------------------------------------------------------*/

/* 1. Cấu hình Cơ bản (Basic Settings) */
#define configCPU_CLOCK_HZ                      ( 25000000UL )
#define configTICK_RATE_HZ                      ( ( TickType_t ) 1000 )
#define configMAX_PRIORITIES                    ( 5 )
#define configMINIMAL_STACK_SIZE                ( ( unsigned short ) 200 )
#define configTOTAL_HEAP_SIZE                   ( ( size_t ) ( 60 * 1024 ) ) /* 60KB Heap */
#define configMAX_TASK_NAME_LEN                 ( 10 )
#define configUSE_16_BIT_TICKS                  0
#define configIDLE_SHOULD_YIELD                 1
#define configQUEUE_REGISTRY_SIZE               8
#define configCHECK_FOR_STACK_OVERFLOW          2
#define configUSE_TRACE_FACILITY                1
#define configGENERATE_RUN_TIME_STATS           0

/* 2. Các định nghĩa BẮT BUỘC PHẢI CÓ (Sửa lỗi #error của bạn) */
#define configUSE_PREEMPTION                    1   /* 1: Chạy đa nhiệm ưu tiên (Preemptive) */
#define configUSE_IDLE_HOOK                     1   /* 1: Sử dụng hàm vApplicationIdleHook trong main.c */
#define configUSE_TICK_HOOK                     1   /* 1: Sử dụng hàm vApplicationTickHook trong main.c */
#define configUSE_DAEMON_TASK_STARTUP_HOOK      1   /* 1: Sử dụng vApplicationDaemonTaskStartupHook */

/* 3. Cấu hình cấp phát bộ nhớ (Memory Allocation) */
#define configSUPPORT_STATIC_ALLOCATION         1   /* 1: Vì main.c của bạn có hàm vApplicationGetIdleTaskMemory */
#define configSUPPORT_DYNAMIC_ALLOCATION        1   /* 1: Cho phép dùng xTaskCreate */
#define configUSE_MALLOC_FAILED_HOOK            1   /* 1: Báo lỗi khi hết Ram */

/* 4. Synchronization Primitives */
#define configUSE_MUTEXES                       1
#define configUSE_RECURSIVE_MUTEXES             1
#define configUSE_COUNTING_SEMAPHORES           1
#define configUSE_APPLICATION_TASK_TAG          0

/* 5. Co-routine & Software Timer */
#define configUSE_CO_ROUTINES                   0
#define configMAX_CO_ROUTINE_PRIORITIES         ( 2 )

#define configUSE_TIMERS                        1
#define configTIMER_TASK_PRIORITY               ( 2 )
#define configTIMER_QUEUE_LENGTH                10
#define configTIMER_TASK_STACK_DEPTH            ( configMINIMAL_STACK_SIZE * 2 )

/* 6. API Inclusion (Bật/Tắt các hàm API) */
#define INCLUDE_vTaskPrioritySet                1
#define INCLUDE_uxTaskPriorityGet               1
#define INCLUDE_vTaskDelete                     1
#define INCLUDE_vTaskCleanUpResources           1
#define INCLUDE_vTaskSuspend                    1
#define INCLUDE_vTaskDelayUntil                 1
#define INCLUDE_vTaskDelay                      1
#define INCLUDE_xTaskGetSchedulerState          1

/* 7. Cortex-M Specific Definitions */
#ifdef __NVIC_PRIO_BITS
    #define configPRIO_BITS                     __NVIC_PRIO_BITS
#else
    #define configPRIO_BITS                     3
#endif

/* Interrupt Priorities */
#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY      0x07
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY 5

#define configKERNEL_INTERRUPT_PRIORITY         ( configLIBRARY_LOWEST_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )
#define configMAX_SYSCALL_INTERRUPT_PRIORITY    ( configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )

/* Map FreeRTOS handlers to standard names (Quan trọng) */
#define vPortSVCHandler                         SVC_Handler
#define xPortPendSVHandler                      PendSV_Handler
#define xPortSysTickHandler                     SysTick_Handler

/* 8. TrustZone & Security (Non-Secure Only) */
#define configENABLE_TRUSTZONE                  0
#define configRUN_FREERTOS_SECURE_ONLY          0
#define configENABLE_FPU                        1 
#define configENABLE_MPU                        0

/* 9. Debugging */
extern void vAssertCalled( const char *pcFileName, uint32_t ulLine );
#define configASSERT( x ) if( ( x ) == 0 ) vAssertCalled( __FILE__, __LINE__ )

#endif /* FREERTOS_CONFIG_H */