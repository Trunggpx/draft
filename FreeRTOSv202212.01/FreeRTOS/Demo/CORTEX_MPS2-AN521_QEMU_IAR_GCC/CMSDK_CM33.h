/*
 * @file     CMSDK_CM33.h
 * @brief    CMSIS Core Peripheral Access Layer Header File for
 * ARM MPS2-AN521 Device (Cortex-M33 / SSE-200)
 * @version  V1.0.0
 * @date     2025-11-26
 */

#ifndef CMSDK_CM33_H
#define CMSDK_CM33_H

#ifdef __cplusplus
extern "C" {
#endif

/* ================================================================================ */
/* ================             Interrupt Number Definition        ================ */
/* ================================================================================ */

typedef enum IRQn
{
/* -------------------  Processor Exceptions Numbers  ----------------------------- */
  NonMaskableInt_IRQn           = -14,     /* 2 Non Maskable Interrupt */
  HardFault_IRQn                = -13,     /* 3 HardFault Interrupt */
  MemoryManagement_IRQn         = -12,     /* 4 Memory Management Interrupt */
  BusFault_IRQn                 = -11,     /* 5 Bus Fault Interrupt */
  UsageFault_IRQn               = -10,     /* 6 Usage Fault Interrupt */
  SecureFault_IRQn              =  -9,     /* 7 Secure Fault Interrupt */
  SVCall_IRQn                   =  -5,     /* 11 SV Call Interrupt */
  DebugMonitor_IRQn             =  -4,     /* 12 Debug Monitor Interrupt */
  PendSV_IRQn                   =  -2,     /* 14 Pend SV Interrupt */
  SysTick_IRQn                  =  -1,     /* 15 System Tick Interrupt */

/* -------------------  Processor Interrupt Numbers (AN521 Specific) -------------- */
  NONSEC_WATCHDOG_RESET_IRQn    =   0,     /* 16 Non-Secure Watchdog Reset */
  NONSEC_WATCHDOG_IRQn          =   1,     /* 17 Non-Secure Watchdog Interrupt */
  S32K_TIMER_IRQn               =   2,     /* 18 S32K Timer Interrupt */
  TIMER0_IRQn                   =   3,     /* 19 TIMER 0 Interrupt */
  TIMER1_IRQn                   =   4,     /* 20 TIMER 1 Interrupt */
  DUALTIMER_IRQn                =   5,     /* 21 Dual Timer Interrupt */
  MHU0_IRQn                     =   6,     /* 22 Message Handling Unit 0 */
  MHU1_IRQn                     =   7,     /* 23 Message Handling Unit 1 */
  MPC_IRQn                      =   9,     /* 25 MPC Combined (Secure) Interrupt */
  PPC_IRQn                      =  10,     /* 26 PPC Combined (Secure) Interrupt */
  MSC_IRQn                      =  11,     /* 27 MSC Combined (Secure) Interrupt */
  BRIDGE_ERROR_IRQn             =  12,     /* 28 Bridge Error Combined (Secure) Interrupt */
  INVALID_INSTR_CACHE_IRQn      =  13,     /* 29 CPU Instruction Cache Invalidation */
  SYS_PPU_IRQn                  =  15,     /* 31 SYS PPU */
  CPU0_PPU_IRQn                 =  16,     /* 32 CPU0 PPU */
  CPU1_PPU_IRQn                 =  17,     /* 33 CPU1 PPU */
  CPU0_DBG_PPU_IRQn             =  18,     /* 34 CPU0 DBG PPU */
  CPU1_DBG_PPU_IRQn             =  19,     /* 35 CPU1 DBG PPU */
  CRYPT_PPU_IRQn                =  20,     /* 36 CRYPT PPU */
  RAM0_PPU_IRQn                 =  22,     /* 38 RAM0 PPU */
  RAM1_PPU_IRQn                 =  23,     /* 39 RAM1 PPU */
  RAM2_PPU_IRQn                 =  24,     /* 40 RAM2 PPU */
  RAM3_PPU_IRQn                 =  25,     /* 41 RAM3 PPU */
  DEBUG_PPU_IRQn                =  26,     /* 42 DEBUG PPU */
  CPU0_CTI_IRQn                 =  28,     /* 44 CPU0 CTI */
  CPU1_CTI_IRQn                 =  29,     /* 45 CPU1 CTI */
  CORDIOTXCOMB_IRQn             =  30,     /* 46 CORDIO TX combined */
  CORDIORXCOMB_IRQn             =  31,     /* 47 CORDIO RX combined */
  UARTRX0_IRQn                  =  32,     /* 48 UART 0 RX Interrupt */
  UARTTX0_IRQn                  =  33,     /* 49 UART 0 TX Interrupt */
  UARTRX1_IRQn                  =  34,     /* 50 UART 1 RX Interrupt */
  UARTTX1_IRQn                  =  35,     /* 51 UART 1 TX Interrupt */
  UARTRX2_IRQn                  =  36,     /* 52 UART 2 RX Interrupt */
  UARTTX2_IRQn                  =  37,     /* 53 UART 2 TX Interrupt */
  UARTRX3_IRQn                  =  38,     /* 54 UART 3 RX Interrupt */
  UARTTX3_IRQn                  =  39,     /* 55 UART 3 TX Interrupt */
  UARTRX4_IRQn                  =  40,     /* 56 UART 4 RX Interrupt */
  UARTTX4_IRQn                  =  41,     /* 57 UART 4 TX Interrupt */
  UART0_IRQn                    =  42,     /* 58 UART 0 combined Interrupt */
  UART1_IRQn                    =  43,     /* 59 UART 1 combined Interrupt */
  UART2_IRQn                    =  44,     /* 60 UART 2 combined Interrupt */
  UART3_IRQn                    =  45,     /* 61 UART 3 combined Interrupt */
  UART4_IRQn                    =  46,     /* 62 UART 4 combined Interrupt */
  UARTOVF_IRQn                  =  47,     /* 63 UART Overflow (0, 1, 2, 3 & 4) */
  ETHERNET_IRQn                 =  48,     /* 64 Ethernet Interrupt */
  I2S_IRQn                      =  49,     /* 65 Audio I2S Interrupt */
  TSC_IRQn                      =  50,     /* 66 Touch Screen Interrupt */
  SPI0_IRQn                     =  51,     /* 67 SPI 0 Interrupt */
  SPI1_IRQn                     =  52,     /* 68 SPI 1 Interrupt */
  SPI2_IRQn                     =  53,     /* 69 SPI 2 Interrupt */
  SPI3_IRQn                     =  54,     /* 70 SPI 3 Interrupt */
  SPI4_IRQn                     =  55,     /* 71 SPI 4 Interrupt */
  DMA0_ERROR_IRQn               =  56,     /* 72 DMA 0 Error Interrupt */
  DMA0_TC_IRQn                  =  57,     /* 73 DMA 0 Terminal Count Interrupt */
  DMA0_IRQn                     =  58,     /* 74 DMA 0 Combined Interrupt */
  DMA1_ERROR_IRQn               =  59,     /* 75 DMA 1 Error Interrupt */
  DMA1_TC_IRQn                  =  60,     /* 76 DMA 1 Terminal Count Interrupt */
  DMA1_IRQn                     =  61,     /* 77 DMA 1 Combined Interrupt */
  DMA2_ERROR_IRQn               =  62,     /* 78 DMA 2 Error Interrupt */
  DMA2_TC_IRQn                  =  63,     /* 79 DMA 2 Terminal Count Interrupt */
  DMA2_IRQn                     =  64,     /* 80 DMA 2 Combined Interrupt */
  DMA3_ERROR_IRQn               =  65,     /* 81 DMA 3 Error Interrupt */
  DMA3_TC_IRQn                  =  66,     /* 82 DMA 3 Terminal Count Interrupt */
  DMA3_IRQn                     =  67,     /* 83 DMA 3 Combined Interrupt */
  GPIO0_IRQn                    =  68,     /* 84 GPIO 0 Combined Interrupt */
  GPIO1_IRQn                    =  69,     /* 85 GPIO 1 Combined Interrupt */
  GPIO2_IRQn                    =  70,     /* 86 GPIO 2 Combined Interrupt */
  GPIO3_IRQn                    =  71,     /* 87 GPIO 3 Combined Interrupt */
  GPIO0_0_IRQn                  =  72,     /* 88 GPIO0 has 16 pins with IRQs */
  GPIO0_1_IRQn                  =  73,
  GPIO0_2_IRQn                  =  74,
  GPIO0_3_IRQn                  =  75,
  GPIO0_4_IRQn                  =  76,
  GPIO0_5_IRQn                  =  77,
  GPIO0_6_IRQn                  =  78,
  GPIO0_7_IRQn                  =  79,
  GPIO0_8_IRQn                  =  80,
  GPIO0_9_IRQn                  =  81,
  GPIO0_10_IRQn                 =  82,
  GPIO0_11_IRQn                 =  83,
  GPIO0_12_IRQn                 =  84,
  GPIO0_13_IRQn                 =  85,
  GPIO0_14_IRQn                 =  86,
  GPIO0_15_IRQn                 =  87,
  GPIO1_0_IRQn                  =  88,     /* 104 GPIO1 has 16 pins with IRQs */
  GPIO1_1_IRQn                  =  89,
  GPIO1_2_IRQn                  =  90,
  GPIO1_3_IRQn                  =  91,
  GPIO1_4_IRQn                  =  92,
  GPIO1_5_IRQn                  =  93,
  GPIO1_6_IRQn                  =  94,
  GPIO1_7_IRQn                  =  95,
  GPIO1_8_IRQn                  =  96,
  GPIO1_9_IRQn                  =  97,
  GPIO1_10_IRQn                 =  98,
  GPIO1_11_IRQn                 =  99,
  GPIO1_12_IRQn                 = 100,
  GPIO1_13_IRQn                 = 101,
  GPIO1_14_IRQn                 = 102,
  GPIO1_15_IRQn                 = 103,
  GPIO2_0_IRQn                  = 104,     /* 120 GPIO2 has 16 pins with IRQs */
  GPIO2_1_IRQn                  = 105,
  GPIO2_2_IRQn                  = 106,
  GPIO2_3_IRQn                  = 107,
  GPIO2_4_IRQn                  = 108,
  GPIO2_5_IRQn                  = 109,
  GPIO2_6_IRQn                  = 110,
  GPIO2_7_IRQn                  = 111,
  GPIO2_8_IRQn                  = 112,
  GPIO2_9_IRQn                  = 113,
  GPIO2_10_IRQn                 = 114,
  GPIO2_11_IRQn                 = 115,
  GPIO2_12_IRQn                 = 116,
  GPIO2_13_IRQn                 = 117,
  GPIO2_14_IRQn                 = 118,
  GPIO2_15_IRQn                 = 119,
  GPIO3_0_IRQn                  = 120,     /* 136 GPIO3 has 4 pins with IRQs */
  GPIO3_1_IRQn                  = 121,
  GPIO3_2_IRQn                  = 122,
  GPIO3_3_IRQn                  = 123
} IRQn_Type;

/* ================================================================================ */
/* ================      Processor and Core Peripheral Section     ================ */
/* ================================================================================ */

#define __CM33_REV                0x0000U   /* Core revision r0p0 */
#define __SAUREGION_PRESENT       1U        /* SAU regions present */
#define __MPU_PRESENT             1U        /* MPU present */
#define __VTOR_PRESENT            1U        /* VTOR present */
#define __NVIC_PRIO_BITS          3U        /* Number of Bits used for Priority Levels */
#define __Vendor_SysTickConfig    0U        /* Set to 1 if different SysTick Config is used */
#define __FPU_PRESENT             1U        /* FPU present */
#define __DSP_PRESENT             1U        /* DSP extension present */

#include "core_cm33.h"                      /* Processor and core peripherals */
/* Không include system_CMSDK_CM33.h ở đây để tránh circular dependency */

/* ================================================================================ */
/* ================             Peripheral Definitions             ================ */
/* ================================================================================ */

/* ------------------  CMSDK UART  ------------------ */
typedef struct
{
  __IO   uint32_t  DATA;
  __IO   uint32_t  STATE;
  __IO   uint32_t  CTRL;
  union {
    __I    uint32_t  INTSTATUS;
    __O    uint32_t  INTCLEAR;
    };
  __IO   uint32_t  BAUDDIV;
} CMSDK_UART_TypeDef;

#define CMSDK_UART_DATA_Pos               0
#define CMSDK_UART_DATA_Msk              (0xFFul << CMSDK_UART_DATA_Pos)
#define CMSDK_UART_STATE_RXOR_Pos         3
#define CMSDK_UART_STATE_RXOR_Msk         (0x1ul << CMSDK_UART_STATE_RXOR_Pos)
#define CMSDK_UART_STATE_TXOR_Pos         2
#define CMSDK_UART_STATE_TXOR_Msk         (0x1ul << CMSDK_UART_STATE_TXOR_Pos)
#define CMSDK_UART_STATE_RXBF_Pos         1
#define CMSDK_UART_STATE_RXBF_Msk         (0x1ul << CMSDK_UART_STATE_RXBF_Pos)
#define CMSDK_UART_STATE_TXBF_Pos         0
#define CMSDK_UART_STATE_TXBF_Msk         (0x1ul << CMSDK_UART_STATE_TXBF_Pos)
#define CMSDK_UART_CTRL_HSTM_Pos          6
#define CMSDK_UART_CTRL_HSTM_Msk          (0x01ul << CMSDK_UART_CTRL_HSTM_Pos)
#define CMSDK_UART_CTRL_RXORIRQEN_Pos     5
#define CMSDK_UART_CTRL_RXORIRQEN_Msk     (0x01ul << CMSDK_UART_CTRL_RXORIRQEN_Pos)
#define CMSDK_UART_CTRL_TXORIRQEN_Pos     4
#define CMSDK_UART_CTRL_TXORIRQEN_Msk     (0x01ul << CMSDK_UART_CTRL_TXORIRQEN_Pos)
#define CMSDK_UART_CTRL_RXIRQEN_Pos       3
#define CMSDK_UART_CTRL_RXIRQEN_Msk       (0x01ul << CMSDK_UART_CTRL_RXIRQEN_Pos)
#define CMSDK_UART_CTRL_TXIRQEN_Pos       2
#define CMSDK_UART_CTRL_TXIRQEN_Msk       (0x01ul << CMSDK_UART_CTRL_TXIRQEN_Pos)
#define CMSDK_UART_CTRL_RXEN_Pos          1
#define CMSDK_UART_CTRL_RXEN_Msk          (0x01ul << CMSDK_UART_CTRL_RXEN_Pos)
#define CMSDK_UART_CTRL_TXEN_Pos          0
#define CMSDK_UART_CTRL_TXEN_Msk          (0x01ul << CMSDK_UART_CTRL_TXEN_Pos)
#define CMSDK_UART_INTSTATUS_RXORIRQ_Pos  3
#define CMSDK_UART_CTRL_RXORIRQ_Msk       (0x01ul << CMSDK_UART_INTSTATUS_RXORIRQ_Pos)
#define CMSDK_UART_CTRL_TXORIRQ_Pos       2
#define CMSDK_UART_CTRL_TXORIRQ_Msk       (0x01ul << CMSDK_UART_CTRL_TXORIRQ_Pos)
#define CMSDK_UART_CTRL_RXIRQ_Pos         1
#define CMSDK_UART_CTRL_RXIRQ_Msk         (0x01ul << CMSDK_UART_CTRL_RXIRQ_Pos)
#define CMSDK_UART_CTRL_TXIRQ_Pos         0
#define CMSDK_UART_CTRL_TXIRQ_Msk         (0x01ul << CMSDK_UART_CTRL_TXIRQ_Pos)
#define CMSDK_UART_BAUDDIV_Pos            0
#define CMSDK_UART_BAUDDIV_Msk           (0xFFFFFul << CMSDK_UART_BAUDDIV_Pos)


/* ------------------  CMSDK Timer  ------------------ */
typedef struct
{
  __IO   uint32_t  CTRL;
  __IO   uint32_t  VALUE;
  __IO   uint32_t  RELOAD;
  union {
    __I    uint32_t  INTSTATUS;
    __O    uint32_t  INTCLEAR;
    };
} CMSDK_TIMER_TypeDef;

#define CMSDK_TIMER_CTRL_IRQEN_Pos          3
#define CMSDK_TIMER_CTRL_IRQEN_Msk          (0x01ul << CMSDK_TIMER_CTRL_IRQEN_Pos)
#define CMSDK_TIMER_CTRL_SELEXTCLK_Pos      2
#define CMSDK_TIMER_CTRL_SELEXTCLK_Msk      (0x01ul << CMSDK_TIMER_CTRL_SELEXTCLK_Pos)
#define CMSDK_TIMER_CTRL_SELEXTEN_Pos       1
#define CMSDK_TIMER_CTRL_SELEXTEN_Msk       (0x01ul << CMSDK_TIMER_CTRL_SELEXTEN_Pos)
#define CMSDK_TIMER_CTRL_EN_Pos             0
#define CMSDK_TIMER_CTRL_EN_Msk             (0x01ul << CMSDK_TIMER_CTRL_EN_Pos)
#define CMSDK_TIMER_VAL_CURRENT_Pos         0
#define CMSDK_TIMER_VAL_CURRENT_Msk         (0xFFFFFFFFul << CMSDK_TIMER_VAL_CURRENT_Pos)
#define CMSDK_TIMER_RELOAD_VAL_Pos          0
#define CMSDK_TIMER_RELOAD_VAL_Msk          (0xFFFFFFFFul << CMSDK_TIMER_RELOAD_VAL_Pos)
#define CMSDK_TIMER_INTSTATUS_Pos           0
#define CMSDK_TIMER_INTSTATUS_Msk           (0x01ul << CMSDK_TIMER_INTSTATUS_Pos)
#define CMSDK_TIMER_INTCLEAR_Pos            0
#define CMSDK_TIMER_INTCLEAR_Msk            (0x01ul << CMSDK_TIMER_INTCLEAR_Pos)


/* ------------------  CMSDK Dual Timer  ------------------ */
typedef struct
{
  __IO uint32_t Timer1Load;
  __I  uint32_t Timer1Value;
  __IO uint32_t Timer1Control;
  __O  uint32_t Timer1IntClr;
  __I  uint32_t Timer1RIS;
  __I  uint32_t Timer1MIS;
  __IO uint32_t Timer1BGLoad;
       uint32_t RESERVED0;
  __IO uint32_t Timer2Load;
  __I  uint32_t Timer2Value;
  __IO uint32_t Timer2Control;
  __O  uint32_t Timer2IntClr;
  __I  uint32_t Timer2RIS;
  __I  uint32_t Timer2MIS;
  __IO uint32_t Timer2BGLoad;
       uint32_t RESERVED1[945];
  __IO uint32_t ITCR;
  __O  uint32_t ITOP;
} CMSDK_DUALTIMER_BOTH_TypeDef;

#define CMSDK_DUALTIMER1_CTRL_EN_Pos         7
#define CMSDK_DUALTIMER1_CTRL_EN_Msk         (0x1ul << CMSDK_DUALTIMER1_CTRL_EN_Pos)
/* ... Các define khác cho Dual Timer tương tự như bạn đã làm ... */
/* (Để ngắn gọn tôi không liệt kê lại hết, nhưng bạn hãy giữ nguyên các define bạn đã có) */


/* ------------------  CMSDK GPIO  ------------------ */
typedef struct
{
  __IO   uint32_t  DATA;
  __IO   uint32_t  DATAOUT;
         uint32_t  RESERVED0[2];
  __IO   uint32_t  OUTENABLESET;
  __IO   uint32_t  OUTENABLECLR;
  __IO   uint32_t  ALTFUNCSET;
  __IO   uint32_t  ALTFUNCCLR;
  __IO   uint32_t  INTENSET;
  __IO   uint32_t  INTENCLR;
  __IO   uint32_t  INTTYPESET;
  __IO   uint32_t  INTTYPECLR;
  __IO   uint32_t  INTPOLSET;
  __IO   uint32_t  INTPOLCLR;
  union {
    __I    uint32_t  INTSTATUS;
    __O    uint32_t  INTCLEAR;
    };
         uint32_t RESERVED1[241];
  __IO   uint32_t LB_MASKED[256];
  __IO   uint32_t UB_MASKED[256];
} CMSDK_GPIO_TypeDef;
/* Giữ nguyên các define GPIO của bạn */


/* ------------------  SSE-200 System Info  ------------------ */
typedef struct
{
  __I  uint32_t SYS_VERSION;
  __I  uint32_t SYS_CONFIG;
       uint32_t RESERVED0[1010];
  __I  uint32_t PID4;
  __I  uint32_t PID5;
  __I  uint32_t PID6;
  __I  uint32_t PID7;
  __I  uint32_t PID0;
  __I  uint32_t PID1;
  __I  uint32_t PID2;
  __I  uint32_t PID3;
  __I  uint32_t CID0;
  __I  uint32_t CID1;
  __I  uint32_t CID2;
  __I  uint32_t CID3;
} SSE200_SYSINFO_TypeDef;


/* ------------------  SSE-200 System Control  ------------------ */
typedef struct
{
  __I  uint32_t SECDBGSTAT;
  __O  uint32_t SECDBGSET;
  __O  uint32_t SECDBGCLR;
  __IO uint32_t SCSECCTRL;
  __IO uint32_t FCLK_DIV;
  __IO uint32_t SYSCLK_DIV;
  __IO uint32_t CLOCK_FORCE;
       uint32_t RESERVED0[57];
  __IO uint32_t RESET_SYNDROME;
  __IO uint32_t RESET_MASK;
  __O  uint32_t SWRESET;
  __IO uint32_t GRETREG;
  __IO uint32_t INITSVRTOR0;
  __IO uint32_t INITSVRTOR1;
  __IO uint32_t CPUWAIT;
  __IO uint32_t NMI_ENABLE;
  __IO uint32_t WICCTRL;
  __IO uint32_t EWCTRL;
       uint32_t RESERVED1[54];
  __IO uint32_t PDCM_PD_SYS_SENSE;
} SSE200_SYSCTRL_TypeDef;

#define SSE200_SYSCTRL_RST_SWRESETREQ_Pos        9
#define SSE200_SYSCTRL_RST_SWRESETREQ_Msk        (0x1ul << SSE200_SYSCTRL_RST_SWRESETREQ_Pos)
/* ... Các define khác cho SYSCTRL giữ nguyên ... */


/* ------------------  CMSDK Watchdog  ------------------ */
typedef struct
{
  __IO    uint32_t  LOAD;
  __I     uint32_t  VALUE;
  __IO    uint32_t  CTRL;
  __O     uint32_t  INTCLR;
  __I     uint32_t  RAWINTSTAT;
  __I     uint32_t  MASKINTSTAT;
        uint32_t  RESERVED0[762];
  __IO    uint32_t  LOCK;
        uint32_t  RESERVED1[191];
  __IO    uint32_t  ITCR;
  __O     uint32_t  ITOP;
}CMSDK_WATCHDOG_TypeDef;
/* Giữ nguyên các define Watchdog của bạn */


/* ------------------  PL080 DMA  ------------------ */
typedef struct {
    __I  uint32_t IntStatus;
    __I  uint32_t IntTCStatus;
    __IO uint32_t IntTCClear;
    __I  uint32_t IntErrorStatus;
    __IO uint32_t IntErrorClear;
    __I  uint32_t RawIntTCStatus;
    __I  uint32_t RawIntErrorStatus;
    __IO uint32_t EnbldChns;
    __IO uint32_t SoftBReq;
    __IO uint32_t SoftSReq;
    __IO uint32_t SoftLBReq;
    __IO uint32_t SoftLSReq;
    __IO uint32_t Configuration;
    __IO uint32_t Sync;
} CMSDK_DMA_TypeDef;


/* ================================================================================ */
/* ================              Peripheral memory map             ================ */
/* ================================================================================ */

#define CMSDK_FLASH_BASE         (0x00000000UL)
#define CMSDK_FLASH_S_BASE       (0x10000000UL)
#define CMSDK_SRAM_BASE          (0x20000000UL)
#define CMSDK_SRAM_S_BASE        (0x30000000UL)

#define CMSDK_BASE_PERIPH_NS_BASE (0x40000000UL)
#define CMSDK_BASE_PERIPH_S_BASE  (0x50000000UL)

#define CMSDK_EXPANSION1_NS_BASE  (0x40100000UL)
#define CMSDK_EXPANSION1_S_BASE   (0x50100000UL)

#define CMSDK_SYS_INFO_NS_BASE    (0x40020000UL)
#define CMSDK_SYS_INFO_S_BASE     (0x50020000UL)

/* ================================================================================ */
/* ================             Peripheral Addresses               ================ */
/* ================================================================================ */

/* Timers */
#define CMSDK_TIMER0_NS_BASE     (0x40000000UL)
#define CMSDK_TIMER0_S_BASE      (0x50000000UL)
#define CMSDK_TIMER1_NS_BASE     (0x40001000UL)
#define CMSDK_TIMER1_S_BASE      (0x50001000UL)

/* Dual Timer */
#define CMSDK_DUALTIMER_NS_BASE  (0x40002000UL)
#define CMSDK_DUALTIMER_S_BASE   (0x50002000UL)

/* MHU */
#define CMSDK_MHU0_NS_BASE       (0x40003000UL)
#define CMSDK_MHU0_S_BASE        (0x50003000UL)
#define CMSDK_MHU1_NS_BASE       (0x40004000UL)
#define CMSDK_MHU1_S_BASE        (0x50004000UL)

/* Watchdogs */
#define CMSDK_WATCHDOG_NS_BASE   (0x40081000UL)
#define CMSDK_WATCHDOG_S_BASE    (0x50081000UL)

/* System Control */
#define SSE200_SYSINFO_NS_BASE   (0x40020000UL)
#define SSE200_SYSINFO_S_BASE    (0x50020000UL)
#define SSE200_SYSCTRL_S_BASE    (0x50021000UL)

/* S32K */
#define CMSDK_S32K_TIMER_NS_BASE (0x4002F000UL)
#define CMSDK_S32K_TIMER_S_BASE  (0x5002F000UL)
#define CMSDK_S32K_WATCHDOG_BASE (0x5002E000UL)

/* GPIO */
#define CMSDK_GPIO0_NS_BASE      (0x40100000UL)
#define CMSDK_GPIO0_S_BASE       (0x50100000UL)
#define CMSDK_GPIO1_NS_BASE      (0x40101000UL)
#define CMSDK_GPIO1_S_BASE       (0x50101000UL)
#define CMSDK_GPIO2_NS_BASE      (0x40102000UL)
#define CMSDK_GPIO2_S_BASE       (0x50102000UL)
#define CMSDK_GPIO3_NS_BASE      (0x40103000UL)
#define CMSDK_GPIO3_S_BASE       (0x50103000UL)

/* UART */
#define CMSDK_UART0_NS_BASE      (0x40200000UL) 
#define CMSDK_UART0_S_BASE       (0x50200000UL)
#define CMSDK_UART1_NS_BASE      (0x40201000UL)
#define CMSDK_UART1_S_BASE       (0x50201000UL)
#define CMSDK_UART2_NS_BASE      (0x40202000UL)
#define CMSDK_UART2_S_BASE       (0x50202000UL)
#define CMSDK_UART3_NS_BASE      (0x40203000UL)
#define CMSDK_UART3_S_BASE       (0x50203000UL)
#define CMSDK_UART4_NS_BASE      (0x40204000UL)
#define CMSDK_UART4_S_BASE       (0x50204000UL)

/* DMA */
#define CMSDK_DMA_NS_BASE        (0x40028000UL)
#define CMSDK_DMA_S_BASE         (0x50028000UL)


/* ================================================================================ */
/* ================             Peripheral declaration             ================ */
/* ================================================================================ */

#define CMSDK_TIMER0_NS         ((CMSDK_TIMER_TypeDef          *) CMSDK_TIMER0_NS_BASE)
#define CMSDK_TIMER0_S          ((CMSDK_TIMER_TypeDef          *) CMSDK_TIMER0_S_BASE)
#define CMSDK_TIMER1_NS         ((CMSDK_TIMER_TypeDef          *) CMSDK_TIMER1_NS_BASE)
#define CMSDK_TIMER1_S          ((CMSDK_TIMER_TypeDef          *) CMSDK_TIMER1_S_BASE)

#define CMSDK_DUALTIMER_NS      ((CMSDK_DUALTIMER_BOTH_TypeDef *) CMSDK_DUALTIMER_NS_BASE)
#define CMSDK_DUALTIMER_S       ((CMSDK_DUALTIMER_BOTH_TypeDef *) CMSDK_DUALTIMER_S_BASE)

#define CMSDK_WATCHDOG_NS       ((CMSDK_WATCHDOG_TypeDef       *) CMSDK_WATCHDOG_NS_BASE)
#define CMSDK_WATCHDOG_S        ((CMSDK_WATCHDOG_TypeDef       *) CMSDK_WATCHDOG_S_BASE)
#define CMSDK_S32K_WATCHDOG     ((CMSDK_WATCHDOG_TypeDef       *) CMSDK_S32K_WATCHDOG_BASE)

#define SSE200_SYSINFO_NS       ((SSE200_SYSINFO_TypeDef       *) SSE200_SYSINFO_NS_BASE)
#define SSE200_SYSINFO_S        ((SSE200_SYSINFO_TypeDef       *) SSE200_SYSINFO_S_BASE)
#define SSE200_SYSCTRL_S        ((SSE200_SYSCTRL_TypeDef       *) SSE200_SYSCTRL_S_BASE)

#define CMSDK_GPIO0_NS          ((CMSDK_GPIO_TypeDef           *) CMSDK_GPIO0_NS_BASE)
#define CMSDK_GPIO0_S           ((CMSDK_GPIO_TypeDef           *) CMSDK_GPIO0_S_BASE)
#define CMSDK_GPIO1_NS          ((CMSDK_GPIO_TypeDef           *) CMSDK_GPIO1_NS_BASE)
#define CMSDK_GPIO1_S           ((CMSDK_GPIO_TypeDef           *) CMSDK_GPIO1_S_BASE)
#define CMSDK_GPIO2_NS          ((CMSDK_GPIO_TypeDef           *) CMSDK_GPIO2_NS_BASE)
#define CMSDK_GPIO2_S           ((CMSDK_GPIO_TypeDef           *) CMSDK_GPIO2_S_BASE)
#define CMSDK_GPIO3_NS          ((CMSDK_GPIO_TypeDef           *) CMSDK_GPIO3_NS_BASE)
#define CMSDK_GPIO3_S           ((CMSDK_GPIO_TypeDef           *) CMSDK_GPIO3_S_BASE)

#define CMSDK_UART0_NS          ((CMSDK_UART_TypeDef           *) CMSDK_UART0_NS_BASE)
#define CMSDK_UART0_S           ((CMSDK_UART_TypeDef           *) CMSDK_UART0_S_BASE)
#define CMSDK_UART1_NS          ((CMSDK_UART_TypeDef           *) CMSDK_UART1_NS_BASE)
#define CMSDK_UART1_S           ((CMSDK_UART_TypeDef           *) CMSDK_UART1_S_BASE)
#define CMSDK_UART2_NS          ((CMSDK_UART_TypeDef           *) CMSDK_UART2_NS_BASE)
#define CMSDK_UART2_S           ((CMSDK_UART_TypeDef           *) CMSDK_UART2_S_BASE)
#define CMSDK_UART3_NS          ((CMSDK_UART_TypeDef           *) CMSDK_UART3_NS_BASE)
#define CMSDK_UART3_S           ((CMSDK_UART_TypeDef           *) CMSDK_UART3_S_BASE)
#define CMSDK_UART4_NS          ((CMSDK_UART_TypeDef           *) CMSDK_UART4_NS_BASE)
#define CMSDK_UART4_S           ((CMSDK_UART_TypeDef           *) CMSDK_UART4_S_BASE)

#define CMSDK_DMA_NS            ((CMSDK_DMA_TypeDef            *) CMSDK_DMA_NS_BASE)
#define CMSDK_DMA_S             ((CMSDK_DMA_TypeDef            *) CMSDK_DMA_S_BASE)

#ifdef __cplusplus
}
#endif

#endif /* CMSDK_CM33_H */