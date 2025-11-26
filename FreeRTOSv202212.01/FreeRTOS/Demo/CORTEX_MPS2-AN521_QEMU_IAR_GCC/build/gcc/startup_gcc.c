/* Standard includes. */
#include <stdint.h>

/* FreeRTOS interrupt handlers */
extern void SVC_Handler( void );
extern void PendSV_Handler( void );
extern void SysTick_Handler( void );

/* System Initialization */
extern void SystemInit( void );
extern int main( void );

/* Linker script definitions */
extern uint32_t _estack;
extern uint32_t _sidata;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;

/* Exception handlers */
/* BỎ attribute naked để trình biên dịch tự lo stack frame cho biến cục bộ */
void Reset_Handler( void ); 
void HardFault_Handler( void ) __attribute__( ( naked ) );
void Default_Handler( void ) __attribute__( ( naked ) );

/* Weak aliases for External Interrupts */
#define ALIAS(f) __attribute__((weak, alias (#f)))

void NONSEC_WATCHDOG_RESET_Handler(void) ALIAS(Default_Handler);
void NONSEC_WATCHDOG_Handler(void)       ALIAS(Default_Handler);
void S32K_TIMER_Handler(void)            ALIAS(Default_Handler);
void TIMER0_Handler(void)                ALIAS(Default_Handler);
void TIMER1_Handler(void)                ALIAS(Default_Handler);
void DUALTIMER_Handler(void)             ALIAS(Default_Handler);
void MHU0_Handler(void)                  ALIAS(Default_Handler);
void MHU1_Handler(void)                  ALIAS(Default_Handler);
void UARTRX0_Handler(void)               ALIAS(Default_Handler);
void UARTTX0_Handler(void)               ALIAS(Default_Handler);

/* Vector table for MPS2-AN521 (Cortex-M33) */
const uint32_t* isr_vector[] __attribute__((section(".isr_vector"))) =
{
    ( uint32_t * ) &_estack,               /* Top of Stack */
    ( uint32_t * ) &Reset_Handler,         /* -15 Reset */
    ( uint32_t * ) &Default_Handler,       /* -14 NMI */
    ( uint32_t * ) &HardFault_Handler,     /* -13 Hard Fault */
    ( uint32_t * ) &Default_Handler,       /* -12 MemManage */
    ( uint32_t * ) &Default_Handler,       /* -11 BusFault */
    ( uint32_t * ) &Default_Handler,       /* -10 UsageFault */
    ( uint32_t * ) &Default_Handler,       /* -9  SecureFault */
    0, 0, 0, 0,                            /* -8..-5 Reserved */
    ( uint32_t * ) &SVC_Handler,           /* -5  SVCall */
    ( uint32_t * ) &Default_Handler,       /* -4  Debug Monitor */
    0,                                     /* -3  Reserved */
    ( uint32_t * ) &PendSV_Handler,        /* -2  PendSV */
    ( uint32_t * ) &SysTick_Handler,       /* -1  SysTick */

    /* External Interrupts */
    ( uint32_t * ) &NONSEC_WATCHDOG_RESET_Handler, /* IRQ 0 */
    ( uint32_t * ) &NONSEC_WATCHDOG_Handler,       /* IRQ 1 */
    ( uint32_t * ) &S32K_TIMER_Handler,            /* IRQ 2 */
    ( uint32_t * ) &TIMER0_Handler,                /* IRQ 3 */
    ( uint32_t * ) &TIMER1_Handler,                /* IRQ 4 */
    ( uint32_t * ) &DUALTIMER_Handler,             /* IRQ 5 */
    ( uint32_t * ) &MHU0_Handler,                  /* IRQ 6 */
    ( uint32_t * ) &MHU1_Handler,                  /* IRQ 7 */
    0, 0, 0, 0, 0, 0, 0, 0,                        /* IRQ 8-15 */
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,/* IRQ 16-31 */
    ( uint32_t * ) &UARTRX0_Handler,               /* IRQ 32: UART0 RX */
    ( uint32_t * ) &UARTTX0_Handler,               /* IRQ 33: UART0 TX */
};

/* Reset Handler */
void Reset_Handler( void )
{
    /* 1. Bật FPU ngay đầu hàm để tránh lỗi khi copy data */
    /* SCB->CPACR ở địa chỉ 0xE000ED88 */
    __asm volatile (
        " ldr r0, =0xE000ED88 \n"
        " ldr r1, [r0] \n"
        " orr r1, r1, #(0xF << 20) \n" /* CP10, CP11 Full Access */
        " str r1, [r0] \n"
        " dsb \n"
        " isb \n"
        ::: "r0", "r1"
    );

    /* 2. Copy data từ Flash sang RAM */
    uint32_t *pSrc  = &_sidata;
    uint32_t *pDest = &_sdata;

    while( pDest < &_edata )
    {
        *pDest++ = *pSrc++;
    }

    /* 3. Xóa BSS */
    pDest = &_sbss;
    while( pDest < &_ebss )
    {
        *pDest++ = 0;
    }

    /* 4. Init System & Jump to Main */
    SystemInit();
    main();
}

/* HardFault Handler - Đã bỏ BKPT để tránh treo QEMU */
void HardFault_Handler( void )
{
    __asm volatile
    (
        " .align 4 \n"
        " tst lr, #4 \n"
        " ite eq \n"
        " mrseq r0, msp \n"
        " mrsne r0, psp \n"
        " ldr r1, [r0, #24] \n" /* Lấy địa chỉ lệnh gây lỗi (PC) */
        
        /* Vòng lặp vô tận để giữ trạng thái lỗi */
        " b . \n"
    );
}

void Default_Handler( void )
{
    for( ;; );
}