/* Standard includes. */
#include <stdio.h>
#include <string.h>

/* FreeRTOS includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

/* Hardware includes */
#include "CMSDK_CM33.h"
#include "system_CMSDK_CM33.h"

/* -------------------------- Definitions -------------------------- */

#define mainCREATE_SIMPLE_BLINKY_DEMO_ONLY      1

/* Priorities */
#define mainBLINKY_TASK_PRIORITY       ( tskIDLE_PRIORITY + 1 )
#define mainUART_TASK_PRIORITY         ( tskIDLE_PRIORITY + 2 )
#define mainBLINKY_DELAY_MS            pdMS_TO_TICKS( 500UL )
#define mainUART_BUFFER_SIZE           ( 128 )

/* Hardware Mapping (Secure) */
#define UART0               CMSDK_UART0_S
#define UART_TX_MASK        CMSDK_UART_STATE_TXBF_Msk
#define UART_RX_MASK        CMSDK_UART_STATE_RXBF_Msk
#define LED_PORT            CMSDK_GPIO0_S

/* ---------------------- Function Prototypes ---------------------- */
void main_blinky( void );
void main_full( void );

/* Tách hàm Init làm 2 phần */
static void prvUARTInit_Hardware( void ); 
static void prvUARTInit_NVIC( void );

static void vBlinkyTask( void *pvParameters );
static void vUARTTask( void *pvParameters );
int UART_Read_Blocking(char *buffer, int max_len);
void UART_Write(const char *buffer, int length);

/* Handles */
static SemaphoreHandle_t xUARTSemaphore = NULL;
static volatile int xBlinkingEnabled = 1;

/* ------------------------- Main Function ------------------------- */
int main( void )
{
    /* 1. Init Hardware (Chưa bật ngắt NVIC) -> AN TOÀN */
    prvUARTInit_Hardware();

    /* In thông báo khởi động (Dùng Polling, không cần ngắt) */
    printf("\r\n[System] MPS2-AN521 FreeRTOS Demo Starting (Secure)...\r\n");

    #if ( mainCREATE_SIMPLE_BLINKY_DEMO_ONLY == 1 )
    {
        main_blinky();
    }
    #else
    {
        main_full();
    }
    #endif

    return 0;
}

/* ------------------------- Demo Entry --------------------------- */
void main_blinky( void )
{
    /* 2. Tạo Semaphore trước */
    xUARTSemaphore = xSemaphoreCreateBinary();
    
    if( xUARTSemaphore != NULL )
    {
        /* 3. Semaphore đã có, giờ mới được phép bật ngắt NVIC */
        prvUARTInit_NVIC();

        /* 4. Tạo Task */
        xTaskCreate( vBlinkyTask, "Blinky", configMINIMAL_STACK_SIZE, NULL, mainBLINKY_TASK_PRIORITY, NULL );
        xTaskCreate( vUARTTask, "UART", configMINIMAL_STACK_SIZE, NULL, mainUART_TASK_PRIORITY, NULL );

        /* 5. Chạy Scheduler */
        vTaskStartScheduler();
    }
    else
    {
        printf("Error: Cannot create UART Semaphore\r\n");
    }

    /* Nếu không đủ heap để tạo Semaphore/Task thì sẽ rơi xuống đây */
    for( ;; );
}

void main_full( void ) { for( ;; ); }

/* ------------------------- Task Functions ------------------------ */

static void vBlinkyTask( void *pvParameters )
{
    ( void ) pvParameters;
    for( ;; )
    {
        if( xBlinkingEnabled )
        {
            printf( "LED Blink!\r\n" );
        }
        vTaskDelay( mainBLINKY_DELAY_MS );
    }
}

static void vUARTTask( void *pvParameters )
{
    char buffer[mainUART_BUFFER_SIZE];
    int len;
    ( void ) pvParameters;

    for( ;; )
    {
        /* Chờ ngắt UART báo có dữ liệu */
        if( xSemaphoreTake( xUARTSemaphore, portMAX_DELAY ) == pdTRUE )
        {
            len = UART_Read_Blocking(buffer, mainUART_BUFFER_SIZE);
            if( len > 0 )
            {
                /* Echo lại */
                UART_Write(buffer, len); 
                
                /* Xử lý lệnh */
                if( strncmp(buffer, "BLINK ON", 8) == 0 ) xBlinkingEnabled = 1;
                else if( strncmp(buffer, "BLINK OFF", 9) == 0 ) xBlinkingEnabled = 0;
            }
        }
    }
}

/* ------------------------- Driver Functions ---------------------- */

/* Hàm 1: Chỉ cấu hình thanh ghi UART, KHÔNG ĐỤNG ĐẾN NVIC */
static void prvUARTInit_Hardware( void )
{
    UART0->BAUDDIV = 16;
    
    /* Bật TX, RX và cho phép ngắt tại module UART (nhưng CPU chưa nhận) */
    UART0->CTRL = (1ul << CMSDK_UART_CTRL_TXEN_Pos) | 
                  (1ul << CMSDK_UART_CTRL_RXEN_Pos) |
                  (1ul << CMSDK_UART_CTRL_RXIRQEN_Pos);
    
    /* Xóa sạch các cờ ngắt tồn đọng */
    UART0->INTCLEAR = CMSDK_UART_CTRL_RXIRQ_Msk | CMSDK_UART_CTRL_TXIRQ_Msk;
}

/* Hàm 2: Bật ngắt NVIC (Chỉ gọi khi OS đã sẵn sàng) */
static void prvUARTInit_NVIC( void )
{
    NVIC_SetPriority(UARTRX0_IRQn, 5);
    NVIC_EnableIRQ(UARTRX0_IRQn);
}

/* Hàm xử lý ngắt UART */
void UARTRX0_Handler(void)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    
    /* Xóa cờ ngắt */
    UART0->INTCLEAR = CMSDK_UART_CTRL_RXIRQ_Msk;
    
    /* Kiểm tra kỹ Semaphore khác NULL mới Give */
    if( xUARTSemaphore != NULL )
    {
        xSemaphoreGiveFromISR(xUARTSemaphore, &xHigherPriorityTaskWoken);
        portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
    }
}

int UART_Read_Blocking(char *buffer, int max_len)
{
    int count = 0;
    while ( (UART0->STATE & UART_RX_MASK) && (count < max_len - 1) )
    {
        buffer[count] = (char)(UART0->DATA);
        count++;
    }
    buffer[count] = '\0';
    return count;
}

void UART_Write(const char *buffer, int length)
{
    int i;
    for(i = 0; i < length; i++)
    {
        while( (UART0->STATE & UART_TX_MASK) );
        UART0->DATA = buffer[i];
    }
}

/* Retarget printf */
int _write( int iFile, char *pcString, int iStringLength )
{
    ( void ) iFile;
    UART_Write(pcString, iStringLength);
    return iStringLength;
}

/* ------------------------- Hook Functions ------------------------ */
/* Các hàm Hook giữ nguyên, nhưng thêm portDISABLE_INTERRUPTS để an toàn */

void vApplicationMallocFailedHook( void )
{
    portDISABLE_INTERRUPTS();
    for( ;; );
}

void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName )
{
    (void)pxTask; (void)pcTaskName;
    portDISABLE_INTERRUPTS();
    for( ;; );
}

void vApplicationTickHook( void ) {}
void vApplicationIdleHook( void ) {}
void vApplicationDaemonTaskStartupHook( void ) {}

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
    static StaticTask_t xIdleTaskTCB;
    static StackType_t uxIdleTaskStack[ configMINIMAL_STACK_SIZE ];
    *ppxIdleTaskTCBBuffer = &xIdleTaskTCB;
    *ppxIdleTaskStackBuffer = uxIdleTaskStack;
    *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
}

void vApplicationGetTimerTaskMemory( StaticTask_t **ppxTimerTaskTCBBuffer, StackType_t **ppxTimerTaskStackBuffer, uint32_t *pulTimerTaskStackSize )
{
    static StaticTask_t xTimerTaskTCB;
    static StackType_t uxTimerTaskStack[ configTIMER_TASK_STACK_DEPTH ];
    *ppxTimerTaskTCBBuffer = &xTimerTaskTCB;
    *ppxTimerTaskStackBuffer = uxTimerTaskStack;
    *pulTimerTaskStackSize = configTIMER_TASK_STACK_DEPTH;
}

void vAssertCalled( const char *pcFileName, uint32_t ulLine )
{
    /* Dùng vòng lặp chết, không printf để tránh đệ quy */
    volatile uint32_t spin = 1;
    while(spin);
}

void *malloc( size_t size ) { (void)size; for( ;; ); }