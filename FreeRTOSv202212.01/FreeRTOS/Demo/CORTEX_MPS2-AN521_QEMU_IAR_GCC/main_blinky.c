/* Standard includes. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* FreeRTOS includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

/* Hardware includes */
#include "system_CMSDK_CM33.h" /* <--- QUAN TRỌNG: File header bạn vừa làm */

/* Priorities */
#define mainBLINKY_TASK_PRIORITY      ( tskIDLE_PRIORITY + 1 )
#define mainUART_TASK_PRIORITY        ( tskIDLE_PRIORITY + 2 )
#define mainBLINKY_DELAY_MS           pdMS_TO_TICKS( 500UL )
#define mainUART_BUFFER_SIZE          ( 128 )

/* Định nghĩa Hardware cho AN521 */
#define LED_PORT                      CMSDK_GPIO0_NS
#define LED_PIN_MASK                  (1UL << 0) /* Giả sử LED ở Bit 0 */
#define UART_PORT                     CMSDK_UART0_NS

/* Function declarations */
static void vBlinkyTask(void *pvParameters);
static void vUARTTask(void *pvParameters);

/* Driver Functions (Thay thế Mock) */
void Hardware_Init(void);
void LED_Toggle(void);
int UART_Read_Blocking(char *buffer, int max_len);
void UART_Write(const char *buffer, int length);

/* Handles */
static SemaphoreHandle_t xUARTSemaphore = NULL;
static volatile int xBlinkingEnabled = 1;

/*-----------------------------------------------------------*/

void main_blinky(void)
{
    /* Initialize Hardware (Real Registers) */
    Hardware_Init();

    /* Create semaphore */
    xUARTSemaphore = xSemaphoreCreateBinary();

    /* Create tasks */
    xTaskCreate(vBlinkyTask, "Blinky", configMINIMAL_STACK_SIZE, NULL, mainBLINKY_TASK_PRIORITY, NULL);
    xTaskCreate(vUARTTask, "UART", configMINIMAL_STACK_SIZE, NULL, mainUART_TASK_PRIORITY, NULL);

    /* Start scheduler */
    vTaskStartScheduler();

    for (;;);
}

/*-----------------------------------------------------------*/

static void vBlinkyTask(void *pvParameters)
{
    (void) pvParameters;
    for (;;)
    {
        if (xBlinkingEnabled)
        {
            LED_Toggle();
            /* In ra console để debug trên QEMU */
            printf("LED Toggled\n"); 
        }
        vTaskDelay(mainBLINKY_DELAY_MS);
    }
}

static void vUARTTask(void *pvParameters)
{
    char buffer[mainUART_BUFFER_SIZE];
    int len;
    (void) pvParameters;

    for (;;)
    {
        /* Chờ ngắt UART báo có dữ liệu */
        if (xSemaphoreTake(xUARTSemaphore, portMAX_DELAY) == pdTRUE)
        {
            /* Đọc dữ liệu thật từ thanh ghi */
            len = UART_Read_Blocking(buffer, mainUART_BUFFER_SIZE);

            if (len > 0)
            {
                /* Echo back */
                UART_Write(buffer, len);

                /* Check commands */
                if (strncmp(buffer, "BLINK ON", 8) == 0)
                {
                    xBlinkingEnabled = 1;
                    UART_Write("\r\nCMD: ON\r\n", 11);
                }
                else if (strncmp(buffer, "BLINK OFF", 9) == 0)
                {
                    xBlinkingEnabled = 0;
                    UART_Write("\r\nCMD: OFF\r\n", 12);
                }
            }
        }
    }
}

/*-----------------------------------------------------------*/
/* REAL HARDWARE IMPLEMENTATION (Driver) */
/*-----------------------------------------------------------*/

/* Xử lý ngắt UART thật */
void UARTRX0_Handler(void)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    /* Xóa cờ ngắt RX */
    UART_PORT->INTCLEAR = CMSDK_UART_CTRL_RXIRQ_Msk;

    /* Báo cho Task xử lý */
    xSemaphoreGiveFromISR(xUARTSemaphore, &xHigherPriorityTaskWoken);

    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

void Hardware_Init(void)
{
    /* 1. Init LED (GPIO0) */
    /* Enable Output cho Pin 0 */
    LED_PORT->OUTENABLESET = LED_PIN_MASK; 
    
    /* 2. Init UART0 */
    UART_PORT->BAUDDIV = 16; 
    
    /* Bật TX, RX và Ngắt nhận (RX Interrupt) */
    UART_PORT->CTRL = (1ul << CMSDK_UART_CTRL_TXEN_Pos)    | 
                      (1ul << CMSDK_UART_CTRL_RXEN_Pos)    |
                      (1ul << CMSDK_UART_CTRL_RXIRQEN_Pos); // Bật ngắt nhận

    /* 3. Đăng ký ngắt với NVIC (Cortex-M33) */
    /* Lưu ý: Tên hàm UARTRX0_Handler phải khớp với file startup_... .s */
    NVIC_EnableIRQ(UARTRX0_IRQn);
}

void LED_Toggle(void)
{
    /* Đọc trạng thái hiện tại và đảo bit */
    uint32_t current = LED_PORT->DATAOUT;
    LED_PORT->DATAOUT = current ^ LED_PIN_MASK;
}

int UART_Read_Blocking(char *buffer, int max_len)
{
    int count = 0;
    
    /* Đọc tất cả dữ liệu có trong FIFO của UART */
    /* Kiểm tra bit RX Buffer Full (RXBF) -> Có dữ liệu thì đọc */
    while ( (UART_PORT->STATE & CMSDK_UART_STATE_RXBF_Msk) && (count < max_len - 1) )
    {
        buffer[count] = (char)(UART_PORT->DATA);
        count++;
    }
    buffer[count] = '\0'; // Null terminate
    return count;
}

void UART_Write(const char *buffer, int length)
{
    int i;
    for(i = 0; i < length; i++)
    {
        /* Chờ TX Buffer rỗng */
        while( (UART_PORT->STATE & CMSDK_UART_STATE_TXBF_Msk) );
        UART_PORT->DATA = buffer[i];
    }
}