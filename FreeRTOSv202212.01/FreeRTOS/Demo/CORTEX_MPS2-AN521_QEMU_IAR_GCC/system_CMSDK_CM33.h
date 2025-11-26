/* MPS2 CMSIS Library
*
* Copyright (c) 2006-2016 ARM Limited
* SPDX-License-Identifier: BSD-3-Clause
* All rights reserved.
* 
* Redistribution and use in source and binary forms, with or without 
* modification, are permitted provided that the following conditions are met:
* 
* 1. Redistributions of source code must retain the above copyright notice, 
* this list of conditions and the following disclaimer.
* 
* 2. Redistributions in binary form must reproduce the above copyright notice, 
* this list of conditions and the following disclaimer in the documentation 
* and/or other materials provided with the distribution.
* 
* 3. Neither the name of the copyright holder nor the names of its contributors 
* may be used to endorse or promote products derived from this software without 
* specific prior written permission.
* 
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE 
* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
* POSSIBILITY OF SUCH DAMAGE. 
*******************************************************************************
* @file     CMSDK_CM3.h
* @brief    CMSIS Core Peripheral Access Layer Header File for
*           CMSDK_CM3 Device
*
*******************************************************************************/


#ifndef CMSDK_CM33_H
#define CMSDK_CM33_H

#ifdef __cplusplus
extern "C" {
#endif


/* -------------------------  Interrupt Number Definition  ------------------------ */

typedef enum IRQn
{
/* -------------------  Processor Exceptions Numbers  ----------------------------- */
  NonMaskableInt_IRQn           = -14,     /*  2 Non Maskable Interrupt */
  HardFault_IRQn                = -13,     /*  3 HardFault Interrupt */
  MemoryManagement_IRQn         = -12,     /*  4 Memory Management Interrupt */
  BusFault_IRQn                 = -11,     /*  5 Bus Fault Interrupt */
  UsageFault_IRQn               = -10,     /*  6 Usage Fault Interrupt */
  SecureFault_IRQn              =  -9,     /*  7 Secure Fault Interrupt */
  SVCall_IRQn                   =  -5,     /* 11 SV Call Interrupt */
  DebugMonitor_IRQn             =  -4,     /* 12 Debug Monitor Interrupt */
  PendSV_IRQn                   =  -2,     /* 14 Pend SV Interrupt */
  SysTick_IRQn                  =  -1,     /* 15 System Tick Interrupt */

/* -------------------  Processor Interrupt Numbers  ------------------------------ */
    NONSEC_WATCHDOG_RESET_IRQn  = 0,    /* Non-Secure Watchdog Reset*/
    NONSEC_WATCHDOG_IRQn        = 1,    /* Non-Secure Watchdog Interrupt */
    S32K_TIMER_IRQn             = 2,    /* S32K Timer Interrupt */
    TIMER0_IRQn                 = 3,    /* TIMER 0 Interrupt */
    TIMER1_IRQn                 = 4,    /* TIMER 1 Interrupt */
    DUALTIMER_IRQn              = 5,    /* Dual Timer Interrupt */
    MHU0_IRQn                   = 6,    /* Message Handling Unit 0 */
    MHU1_IRQn                   = 7,    /* Message Handling Unit 1 */
    MPC_IRQn                    = 9,    /* MPC Combined (Secure) Interrupt */
    PPC_IRQn                    = 10,   /* PPC Combined (Secure) Interrupt */
    MSC_IRQn                    = 11,   /* MSC Combined (Secure) Interrput */
    BRIDGE_ERROR_IRQn           = 12,   /* Bridge Error Combined (Secure) Interrupt */
    INVALID_INSTR_CACHE_IRQn    = 13,   /* CPU Instruction Cache Invalidation */
    SYS_PPU_IRQn                = 15,   /* SYS PPU */
    CPU0_PPU_IRQn               = 16,   /* CPU0 PPU */
    CPU1_PPU_IRQn               = 17,   /* CPU1 PPU */
    CPU0_DBG_PPU_IRQn           = 18,   /* CPU0 DBG PPU */
    CPU1_DBG_PPU_IRQn           = 19,   /* CPU1 DBG PPU */
    CRYPT_PPU_IRQn              = 20,   /* CRYPT PPU */
    RAM0_PPU_IRQn               = 22,   /* RAM0 PPU */
    RAM1_PPU_IRQn               = 23,   /* RAM1 PPU */
    RAM2_PPU_IRQn               = 24,   /* RAM2 PPU */
    RAM3_PPU_IRQn               = 25,   /* RAM3 PPU */
    DEBUG_PPU_IRQn              = 26,   /* DEBUG PPU */
    CPU0_CTI_IRQn               = 28,   /* CPU0 CTI */
    CPU1_CTI_IRQn               = 29,   /* CPU1 CTI */
    CORDIOTXCOMB_IRQn           = 30,   /* CORDIO TX combined */
    CORDIORXCOMB_IRQn           = 31,   /* CORDIO RX combined */
    UARTRX0_IRQn                = 32,   /* UART 0 RX Interrupt */
    UARTTX0_IRQn                = 33,   /* UART 0 TX Interrupt */
    UARTRX1_IRQn                = 34,   /* UART 1 RX Interrupt */
    UARTTX1_IRQn                = 35,   /* UART 1 TX Interrupt */
    UARTRX2_IRQn                = 36,   /* UART 2 RX Interrupt */
    UARTTX2_IRQn                = 37,   /* UART 2 TX Interrupt */
    UARTRX3_IRQn                = 38,   /* UART 3 RX Interrupt */
    UARTTX3_IRQn                = 39,   /* UART 3 TX Interrupt */
    UARTRX4_IRQn                = 40,   /* UART 4 RX Interrupt */
    UARTTX4_IRQn                = 41,   /* UART 4 TX Interrupt */
    UART0_IRQn                  = 42,   /* UART 0 combined Interrupt */
    UART1_IRQn                  = 43,   /* UART 1 combined Interrupt */
    UART2_IRQn                  = 44,   /* UART 2 combined Interrupt */
    UART3_IRQn                  = 45,   /* UART 3 combined Interrupt */
    UART4_IRQn                  = 46,   /* UART 4 combined Interrupt */
    UARTOVF_IRQn                = 47,   /* UART Overflow (0, 1, 2, 3 & 4) */
    ETHERNET_IRQn               = 48,   /* Ethernet Interrupt */
    I2S_IRQn                    = 49,   /* Audio I2S Interrupt */
    TSC_IRQn                    = 50,   /* Touch Screen Interrupt */
    SPI0_IRQn                   = 51,   /* SPI 0 Interrupt */
    SPI1_IRQn                   = 52,   /* SPI 1 Interrupt */
    SPI2_IRQn                   = 53,   /* SPI 2 Interrupt */
    SPI3_IRQn                   = 54,   /* SPI 3 Interrupt */
    SPI4_IRQn                   = 55,   /* SPI 4 Interrupt */
    DMA0_ERROR_IRQn             = 56,   /* DMA 0 Error Interrupt */
    DMA0_TC_IRQn                = 57,   /* DMA 0 Terminal Count Interrupt */
    DMA0_IRQn                   = 58,   /* DMA 0 Combined Interrupt */
    DMA1_ERROR_IRQn             = 59,   /* DMA 1 Error Interrupt */
    DMA1_TC_IRQn                = 60,   /* DMA 1 Terminal Count Interrupt */
    DMA1_IRQn                   = 61,   /* DMA 1 Combined Interrupt */
    DMA2_ERROR_IRQn             = 62,   /* DMA 2 Error Interrupt */
    DMA2_TC_IRQn                = 63,   /* DMA 2 Terminal Count Interrupt */
    DMA2_IRQn                   = 64,   /* DMA 2 Combined Interrupt */
    DMA3_ERROR_IRQn             = 65,   /* DMA 3 Error Interrupt */
    DMA3_TC_IRQn                = 66,   /* DMA 3 Terminal Count Interrupt */
    DMA3_IRQn                   = 67,   /* DMA 3 Combined Interrupt */
    GPIO0_IRQn                  = 68,   /* GPIO 0 Combined Interrupt */
    GPIO1_IRQn                  = 69,   /* GPIO 1 Combined Interrupt */
    GPIO2_IRQn                  = 70,   /* GPIO 2 Combined Interrupt */
    GPIO3_IRQn                  = 71,   /* GPIO 3 Combined Interrupt */
    GPIO0_0_IRQn                = 72,   /* GPIO0 has 16 pins with IRQs */
    GPIO0_1_IRQn                = 73,
    GPIO0_2_IRQn                = 74,
    GPIO0_3_IRQn                = 75,
    GPIO0_4_IRQn                = 76,
    GPIO0_5_IRQn                = 77,
    GPIO0_6_IRQn                = 78,
    GPIO0_7_IRQn                = 79,
    GPIO0_8_IRQn                = 80,
    GPIO0_9_IRQn                = 81,
    GPIO0_10_IRQn               = 82,
    GPIO0_11_IRQn               = 83,
    GPIO0_12_IRQn               = 84,
    GPIO0_13_IRQn               = 85,
    GPIO0_14_IRQn               = 86,
    GPIO0_15_IRQn               = 87,
    GPIO1_0_IRQn                = 88,   /* GPIO1 has 16 pins with IRQs */
    GPIO1_1_IRQn                = 89,
    GPIO1_2_IRQn                = 90,
    GPIO1_3_IRQn                = 91,
    GPIO1_4_IRQn                = 92,
    GPIO1_5_IRQn                = 93,
    GPIO1_6_IRQn                = 94,
    GPIO1_7_IRQn                = 95,
    GPIO1_8_IRQn                = 96,
    GPIO1_9_IRQn                = 97,
    GPIO1_10_IRQn               = 98,
    GPIO1_11_IRQn               = 99,
    GPIO1_12_IRQn               = 100,
    GPIO1_13_IRQn               = 101,
    GPIO1_14_IRQn               = 102,
    GPIO1_15_IRQn               = 103,
    GPIO2_0_IRQn                = 104,   /* GPIO2 has 16 pins with IRQs */
    GPIO2_1_IRQn                = 105,
    GPIO2_2_IRQn                = 106,
    GPIO2_3_IRQn                = 107,
    GPIO2_4_IRQn                = 108,
    GPIO2_5_IRQn                = 109,
    GPIO2_6_IRQn                = 110,
    GPIO2_7_IRQn                = 111,
    GPIO2_8_IRQn                = 112,
    GPIO2_9_IRQn                = 113,
    GPIO2_10_IRQn               = 114,
    GPIO2_11_IRQn               = 115,
    GPIO2_12_IRQn               = 116,
    GPIO2_13_IRQn               = 117,
    GPIO2_14_IRQn               = 118,
    GPIO2_15_IRQn               = 119,
    GPIO3_0_IRQn                = 120,   /* GPIO3 has 4 pins with IRQs */
    GPIO3_1_IRQn                = 121,
    GPIO3_2_IRQn                = 122,
    GPIO3_3_IRQn                = 123,

} IRQn_Type;


/* ================================================================================ */
/* ================      Processor and Core Peripheral Section     ================ */
/* ================================================================================ */

/* -------  Start of section using anonymous unions and disabling warnings  ------- */
#if   defined (__CC_ARM)
  #pragma push
  #pragma anon_unions
#elif defined (__ICCARM__)
  #pragma language=extended
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wc11-extensions"
  #pragma clang diagnostic ignored "-Wreserved-id-macro"
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning 586
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif


/* --------  Configuration of Core Peripherals  ----------------------------------- */
#define __CM33_REV                0x0000U   /* Core revision r0p1 */
#define __SAUREGION_PRESENT       1U        /* SAU regions present */
#define __MPU_PRESENT             1U        /* MPU present */
#define __VTOR_PRESENT            1U        /* VTOR present */
#define __NVIC_PRIO_BITS          3U        /* Number of Bits used for Priority Levels */
#define __Vendor_SysTickConfig    0U        /* Set to 1 if different SysTick Config is used */
#define __FPU_PRESENT             1U        /* FPU present */
#define __DSP_PRESENT             1U        /* DSP extension present */

#include "core_cm33.h"                      /* Processor and core peripherals */
#include "system_ARMCM33.h"                 /* System Header */

/*------------- Universal Asynchronous Receiver Transmitter (UART) -----------*/

typedef struct
{
  __IO   uint32_t  DATA;                     /* Offset: 0x000 (R/W) Data Register    */
  __IO   uint32_t  STATE;                    /* Offset: 0x004 (R/W) Status Register  */
  __IO   uint32_t  CTRL;                     /* Offset: 0x008 (R/W) Control Register */
  union {
    __I    uint32_t  INTSTATUS;              /* Offset: 0x00C (R/ ) Interrupt Status Register */
    __O    uint32_t  INTCLEAR;               /* Offset: 0x00C ( /W) Interrupt Clear Register  */
    };
  __IO   uint32_t  BAUDDIV;                  /* Offset: 0x010 (R/W) Baudrate Divider Register */

} CMSDK_UART_TypeDef;

/* CMSDK_UART DATA Register Definitions */

#define CMSDK_UART_DATA_Pos               0                                             /* CMSDK_UART_DATA_Pos: DATA Position */
#define CMSDK_UART_DATA_Msk              (0xFFul << CMSDK_UART_DATA_Pos)                /* CMSDK_UART DATA: DATA Mask */

#define CMSDK_UART_STATE_RXOR_Pos         3                                             /* CMSDK_UART STATE: RXOR Position */
#define CMSDK_UART_STATE_RXOR_Msk         (0x1ul << CMSDK_UART_STATE_RXOR_Pos)          /* CMSDK_UART STATE: RXOR Mask */

#define CMSDK_UART_STATE_TXOR_Pos         2                                             /* CMSDK_UART STATE: TXOR Position */
#define CMSDK_UART_STATE_TXOR_Msk         (0x1ul << CMSDK_UART_STATE_TXOR_Pos)          /* CMSDK_UART STATE: TXOR Mask */

#define CMSDK_UART_STATE_RXBF_Pos         1                                             /* CMSDK_UART STATE: RXBF Position */
#define CMSDK_UART_STATE_RXBF_Msk         (0x1ul << CMSDK_UART_STATE_RXBF_Pos)          /* CMSDK_UART STATE: RXBF Mask */

#define CMSDK_UART_STATE_TXBF_Pos         0                                             /* CMSDK_UART STATE: TXBF Position */
#define CMSDK_UART_STATE_TXBF_Msk         (0x1ul << CMSDK_UART_STATE_TXBF_Pos )         /* CMSDK_UART STATE: TXBF Mask */

#define CMSDK_UART_CTRL_HSTM_Pos          6                                             /* CMSDK_UART CTRL: HSTM Position */
#define CMSDK_UART_CTRL_HSTM_Msk          (0x01ul << CMSDK_UART_CTRL_HSTM_Pos)          /* CMSDK_UART CTRL: HSTM Mask */

#define CMSDK_UART_CTRL_RXORIRQEN_Pos     5                                             /* CMSDK_UART CTRL: RXORIRQEN Position */
#define CMSDK_UART_CTRL_RXORIRQEN_Msk     (0x01ul << CMSDK_UART_CTRL_RXORIRQEN_Pos)     /* CMSDK_UART CTRL: RXORIRQEN Mask */

#define CMSDK_UART_CTRL_TXORIRQEN_Pos     4                                             /* CMSDK_UART CTRL: TXORIRQEN Position */
#define CMSDK_UART_CTRL_TXORIRQEN_Msk     (0x01ul << CMSDK_UART_CTRL_TXORIRQEN_Pos)     /* CMSDK_UART CTRL: TXORIRQEN Mask */

#define CMSDK_UART_CTRL_RXIRQEN_Pos       3                                             /* CMSDK_UART CTRL: RXIRQEN Position */
#define CMSDK_UART_CTRL_RXIRQEN_Msk       (0x01ul << CMSDK_UART_CTRL_RXIRQEN_Pos)       /* CMSDK_UART CTRL: RXIRQEN Mask */

#define CMSDK_UART_CTRL_TXIRQEN_Pos       2                                             /* CMSDK_UART CTRL: TXIRQEN Position */
#define CMSDK_UART_CTRL_TXIRQEN_Msk       (0x01ul << CMSDK_UART_CTRL_TXIRQEN_Pos)       /* CMSDK_UART CTRL: TXIRQEN Mask */

#define CMSDK_UART_CTRL_RXEN_Pos          1                                             /* CMSDK_UART CTRL: RXEN Position */
#define CMSDK_UART_CTRL_RXEN_Msk          (0x01ul << CMSDK_UART_CTRL_RXEN_Pos)          /* CMSDK_UART CTRL: RXEN Mask */

#define CMSDK_UART_CTRL_TXEN_Pos          0                                             /* CMSDK_UART CTRL: TXEN Position */
#define CMSDK_UART_CTRL_TXEN_Msk          (0x01ul << CMSDK_UART_CTRL_TXEN_Pos)          /* CMSDK_UART CTRL: TXEN Mask */

#define CMSDK_UART_INTSTATUS_RXORIRQ_Pos  3                                             /* CMSDK_UART CTRL: RXORIRQ Position */
#define CMSDK_UART_CTRL_RXORIRQ_Msk       (0x01ul << CMSDK_UART_INTSTATUS_RXORIRQ_Pos)  /* CMSDK_UART CTRL: RXORIRQ Mask */

#define CMSDK_UART_CTRL_TXORIRQ_Pos       2                                             /* CMSDK_UART CTRL: TXORIRQ Position */
#define CMSDK_UART_CTRL_TXORIRQ_Msk       (0x01ul << CMSDK_UART_CTRL_TXORIRQ_Pos)       /* CMSDK_UART CTRL: TXORIRQ Mask */

#define CMSDK_UART_CTRL_RXIRQ_Pos         1                                             /* CMSDK_UART CTRL: RXIRQ Position */
#define CMSDK_UART_CTRL_RXIRQ_Msk         (0x01ul << CMSDK_UART_CTRL_RXIRQ_Pos)         /* CMSDK_UART CTRL: RXIRQ Mask */

#define CMSDK_UART_CTRL_TXIRQ_Pos         0                                             /* CMSDK_UART CTRL: TXIRQ Position */
#define CMSDK_UART_CTRL_TXIRQ_Msk         (0x01ul << CMSDK_UART_CTRL_TXIRQ_Pos)         /* CMSDK_UART CTRL: TXIRQ Mask */

#define CMSDK_UART_BAUDDIV_Pos            0                                             /* CMSDK_UART BAUDDIV: BAUDDIV Position */
#define CMSDK_UART_BAUDDIV_Msk           (0xFFFFFul << CMSDK_UART_BAUDDIV_Pos)          /* CMSDK_UART BAUDDIV: BAUDDIV Mask */


/*----------------------------- Timer (TIMER) -------------------------------*/
typedef struct
{
  __IO   uint32_t  CTRL;                     /* Offset: 0x000 (R/W) Control Register */
  __IO   uint32_t  VALUE;                    /* Offset: 0x004 (R/W) Current Value Register */
  __IO   uint32_t  RELOAD;                   /* Offset: 0x008 (R/W) Reload Value Register */
  union {
    __I    uint32_t  INTSTATUS;              /* Offset: 0x00C (R/ ) Interrupt Status Register */
    __O    uint32_t  INTCLEAR;               /* Offset: 0x00C ( /W) Interrupt Clear Register */
    };

} CMSDK_TIMER_TypeDef;

/* CMSDK_TIMER CTRL Register Definitions */

#define CMSDK_TIMER_CTRL_IRQEN_Pos          3                                              /* CMSDK_TIMER CTRL: IRQEN Position */
#define CMSDK_TIMER_CTRL_IRQEN_Msk          (0x01ul << CMSDK_TIMER_CTRL_IRQEN_Pos)         /* CMSDK_TIMER CTRL: IRQEN Mask */

#define CMSDK_TIMER_CTRL_SELEXTCLK_Pos      2                                              /* CMSDK_TIMER CTRL: SELEXTCLK Position */
#define CMSDK_TIMER_CTRL_SELEXTCLK_Msk      (0x01ul << CMSDK_TIMER_CTRL_SELEXTCLK_Pos)     /* CMSDK_TIMER CTRL: SELEXTCLK Mask */

#define CMSDK_TIMER_CTRL_SELEXTEN_Pos       1                                              /* CMSDK_TIMER CTRL: SELEXTEN Position */
#define CMSDK_TIMER_CTRL_SELEXTEN_Msk       (0x01ul << CMSDK_TIMER_CTRL_SELEXTEN_Pos)      /* CMSDK_TIMER CTRL: SELEXTEN Mask */

#define CMSDK_TIMER_CTRL_EN_Pos             0                                              /* CMSDK_TIMER CTRL: EN Position */
#define CMSDK_TIMER_CTRL_EN_Msk             (0x01ul << CMSDK_TIMER_CTRL_EN_Pos)            /* CMSDK_TIMER CTRL: EN Mask */

#define CMSDK_TIMER_VAL_CURRENT_Pos         0                                              /* CMSDK_TIMER VALUE: CURRENT Position */
#define CMSDK_TIMER_VAL_CURRENT_Msk         (0xFFFFFFFFul << CMSDK_TIMER_VAL_CURRENT_Pos)  /* CMSDK_TIMER VALUE: CURRENT Mask */

#define CMSDK_TIMER_RELOAD_VAL_Pos          0                                              /* CMSDK_TIMER RELOAD: RELOAD Position */
#define CMSDK_TIMER_RELOAD_VAL_Msk          (0xFFFFFFFFul << CMSDK_TIMER_RELOAD_VAL_Pos)   /* CMSDK_TIMER RELOAD: RELOAD Mask */

#define CMSDK_TIMER_INTSTATUS_Pos           0                                              /* CMSDK_TIMER INTSTATUS: INTSTATUSPosition */
#define CMSDK_TIMER_INTSTATUS_Msk           (0x01ul << CMSDK_TIMER_INTSTATUS_Pos)          /* CMSDK_TIMER INTSTATUS: INTSTATUSMask */

#define CMSDK_TIMER_INTCLEAR_Pos            0                                              /* CMSDK_TIMER INTCLEAR: INTCLEAR Position */
#define CMSDK_TIMER_INTCLEAR_Msk            (0x01ul << CMSDK_TIMER_INTCLEAR_Pos)           /* CMSDK_TIMER INTCLEAR: INTCLEAR Mask */


/*------------- Timer (TIM) --------------------------------------------------*/
typedef struct
{
  __IO uint32_t Timer1Load;                  /* Offset: 0x000 (R/W) Timer 1 Load */
  __I  uint32_t Timer1Value;                 /* Offset: 0x004 (R/ ) Timer 1 Counter Current Value */
  __IO uint32_t Timer1Control;               /* Offset: 0x008 (R/W) Timer 1 Control */
  __O  uint32_t Timer1IntClr;                /* Offset: 0x00C ( /W) Timer 1 Interrupt Clear */
  __I  uint32_t Timer1RIS;                   /* Offset: 0x010 (R/ ) Timer 1 Raw Interrupt Status */
  __I  uint32_t Timer1MIS;                   /* Offset: 0x014 (R/ ) Timer 1 Masked Interrupt Status */
  __IO uint32_t Timer1BGLoad;                /* Offset: 0x018 (R/W) Background Load Register */
       uint32_t RESERVED0;
  __IO uint32_t Timer2Load;                  /* Offset: 0x020 (R/W) Timer 2 Load */
  __I  uint32_t Timer2Value;                 /* Offset: 0x024 (R/ ) Timer 2 Counter Current Value */
  __IO uint32_t Timer2Control;               /* Offset: 0x028 (R/W) Timer 2 Control */
  __O  uint32_t Timer2IntClr;                /* Offset: 0x02C ( /W) Timer 2 Interrupt Clear */
  __I  uint32_t Timer2RIS;                   /* Offset: 0x030 (R/ ) Timer 2 Raw Interrupt Status */
  __I  uint32_t Timer2MIS;                   /* Offset: 0x034 (R/ ) Timer 2 Masked Interrupt Status */
  __IO uint32_t Timer2BGLoad;                /* Offset: 0x038 (R/W) Background Load Register */
       uint32_t RESERVED1[945];
  __IO uint32_t ITCR;                        /* Offset: 0xF00 (R/W) Integration Test Control Register */
  __O  uint32_t ITOP;                        /* Offset: 0xF04 ( /W) Integration Test Output Set Register */
} CMSDK_DUALTIMER_BOTH_TypeDef;

#define CMSDK_DUALTIMER1_LOAD_Pos            0                                                /* CMSDK_DUALTIMER1 LOAD: LOAD Position */
#define CMSDK_DUALTIMER1_LOAD_Msk            (0xFFFFFFFFul << CMSDK_DUALTIMER1_LOAD_Pos)      /* CMSDK_DUALTIMER1 LOAD: LOAD Mask */

#define CMSDK_DUALTIMER1_VALUE_Pos           0                                                /* CMSDK_DUALTIMER1 VALUE: VALUE Position */
#define CMSDK_DUALTIMER1_VALUE_Msk           (0xFFFFFFFFul << CMSDK_DUALTIMER1_VALUE_Pos)     /* CMSDK_DUALTIMER1 VALUE: VALUE Mask */

#define CMSDK_DUALTIMER1_CTRL_EN_Pos         7                                                /* CMSDK_DUALTIMER1 CTRL_EN: CTRL Enable Position */
#define CMSDK_DUALTIMER1_CTRL_EN_Msk         (0x1ul << CMSDK_DUALTIMER1_CTRL_EN_Pos)          /* CMSDK_DUALTIMER1 CTRL_EN: CTRL Enable Mask */

#define CMSDK_DUALTIMER1_CTRL_MODE_Pos       6                                                /* CMSDK_DUALTIMER1 CTRL_MODE: CTRL MODE Position */
#define CMSDK_DUALTIMER1_CTRL_MODE_Msk       (0x1ul << CMSDK_DUALTIMER1_CTRL_MODE_Pos)        /* CMSDK_DUALTIMER1 CTRL_MODE: CTRL MODE Mask */

#define CMSDK_DUALTIMER1_CTRL_INTEN_Pos      5                                                /* CMSDK_DUALTIMER1 CTRL_INTEN: CTRL Int Enable Position */
#define CMSDK_DUALTIMER1_CTRL_INTEN_Msk      (0x1ul << CMSDK_DUALTIMER1_CTRL_INTEN_Pos)       /* CMSDK_DUALTIMER1 CTRL_INTEN: CTRL Int Enable Mask */

#define CMSDK_DUALTIMER1_CTRL_PRESCALE_Pos   2                                                /* CMSDK_DUALTIMER1 CTRL_PRESCALE: CTRL PRESCALE Position */
#define CMSDK_DUALTIMER1_CTRL_PRESCALE_Msk   (0x3ul << CMSDK_DUALTIMER1_CTRL_PRESCALE_Pos)    /* CMSDK_DUALTIMER1 CTRL_PRESCALE: CTRL PRESCALE Mask */

#define CMSDK_DUALTIMER1_CTRL_SIZE_Pos       1                                                /* CMSDK_DUALTIMER1 CTRL_SIZE: CTRL SIZE Position */
#define CMSDK_DUALTIMER1_CTRL_SIZE_Msk       (0x1ul << CMSDK_DUALTIMER1_CTRL_SIZE_Pos)        /* CMSDK_DUALTIMER1 CTRL_SIZE: CTRL SIZE Mask */

#define CMSDK_DUALTIMER1_CTRL_ONESHOOT_Pos   0                                                /* CMSDK_DUALTIMER1 CTRL_ONESHOOT: CTRL ONESHOOT Position */
#define CMSDK_DUALTIMER1_CTRL_ONESHOOT_Msk   (0x1ul << CMSDK_DUALTIMER1_CTRL_ONESHOOT_Pos)    /* CMSDK_DUALTIMER1 CTRL_ONESHOOT: CTRL ONESHOOT Mask */

#define CMSDK_DUALTIMER1_INTCLR_Pos          0                                                /* CMSDK_DUALTIMER1 INTCLR: INT Clear Position */
#define CMSDK_DUALTIMER1_INTCLR_Msk          (0x1ul << CMSDK_DUALTIMER1_INTCLR_Pos)           /* CMSDK_DUALTIMER1 INTCLR: INT Clear  Mask */

#define CMSDK_DUALTIMER1_RAWINTSTAT_Pos      0                                                /* CMSDK_DUALTIMER1 RAWINTSTAT: Raw Int Status Position */
#define CMSDK_DUALTIMER1_RAWINTSTAT_Msk      (0x1ul << CMSDK_DUALTIMER1_RAWINTSTAT_Pos)       /* CMSDK_DUALTIMER1 RAWINTSTAT: Raw Int Status Mask */

#define CMSDK_DUALTIMER1_MASKINTSTAT_Pos     0                                                /* CMSDK_DUALTIMER1 MASKINTSTAT: Mask Int Status Position */
#define CMSDK_DUALTIMER1_MASKINTSTAT_Msk     (0x1ul << CMSDK_DUALTIMER1_MASKINTSTAT_Pos)      /* CMSDK_DUALTIMER1 MASKINTSTAT: Mask Int Status Mask */

#define CMSDK_DUALTIMER1_BGLOAD_Pos          0                                                /* CMSDK_DUALTIMER1 BGLOAD: Background Load Position */
#define CMSDK_DUALTIMER1_BGLOAD_Msk          (0xFFFFFFFFul << CMSDK_DUALTIMER1_BGLOAD_Pos)    /* CMSDK_DUALTIMER1 BGLOAD: Background Load Mask */

#define CMSDK_DUALTIMER2_LOAD_Pos            0                                                /* CMSDK_DUALTIMER2 LOAD: LOAD Position */
#define CMSDK_DUALTIMER2_LOAD_Msk            (0xFFFFFFFFul << CMSDK_DUALTIMER2_LOAD_Pos)      /* CMSDK_DUALTIMER2 LOAD: LOAD Mask */

#define CMSDK_DUALTIMER2_VALUE_Pos           0                                                /* CMSDK_DUALTIMER2 VALUE: VALUE Position */
#define CMSDK_DUALTIMER2_VALUE_Msk           (0xFFFFFFFFul << CMSDK_DUALTIMER2_VALUE_Pos)     /* CMSDK_DUALTIMER2 VALUE: VALUE Mask */

#define CMSDK_DUALTIMER2_CTRL_EN_Pos         7                                                /* CMSDK_DUALTIMER2 CTRL_EN: CTRL Enable Position */
#define CMSDK_DUALTIMER2_CTRL_EN_Msk         (0x1ul << CMSDK_DUALTIMER2_CTRL_EN_Pos)          /* CMSDK_DUALTIMER2 CTRL_EN: CTRL Enable Mask */

#define CMSDK_DUALTIMER2_CTRL_MODE_Pos       6                                                /* CMSDK_DUALTIMER2 CTRL_MODE: CTRL MODE Position */
#define CMSDK_DUALTIMER2_CTRL_MODE_Msk       (0x1ul << CMSDK_DUALTIMER2_CTRL_MODE_Pos)        /* CMSDK_DUALTIMER2 CTRL_MODE: CTRL MODE Mask */

#define CMSDK_DUALTIMER2_CTRL_INTEN_Pos      5                                                /* CMSDK_DUALTIMER2 CTRL_INTEN: CTRL Int Enable Position */
#define CMSDK_DUALTIMER2_CTRL_INTEN_Msk      (0x1ul << CMSDK_DUALTIMER2_CTRL_INTEN_Pos)       /* CMSDK_DUALTIMER2 CTRL_INTEN: CTRL Int Enable Mask */

#define CMSDK_DUALTIMER2_CTRL_PRESCALE_Pos   2                                                /* CMSDK_DUALTIMER2 CTRL_PRESCALE: CTRL PRESCALE Position */
#define CMSDK_DUALTIMER2_CTRL_PRESCALE_Msk   (0x3ul << CMSDK_DUALTIMER2_CTRL_PRESCALE_Pos)    /* CMSDK_DUALTIMER2 CTRL_PRESCALE: CTRL PRESCALE Mask */

#define CMSDK_DUALTIMER2_CTRL_SIZE_Pos       1                                                /* CMSDK_DUALTIMER2 CTRL_SIZE: CTRL SIZE Position */
#define CMSDK_DUALTIMER2_CTRL_SIZE_Msk       (0x1ul << CMSDK_DUALTIMER2_CTRL_SIZE_Pos)        /* CMSDK_DUALTIMER2 CTRL_SIZE: CTRL SIZE Mask */

#define CMSDK_DUALTIMER2_CTRL_ONESHOOT_Pos   0                                                /* CMSDK_DUALTIMER2 CTRL_ONESHOOT: CTRL ONESHOOT Position */
#define CMSDK_DUALTIMER2_CTRL_ONESHOOT_Msk   (0x1ul << CMSDK_DUALTIMER2_CTRL_ONESHOOT_Pos)    /* CMSDK_DUALTIMER2 CTRL_ONESHOOT: CTRL ONESHOOT Mask */

#define CMSDK_DUALTIMER2_INTCLR_Pos          0                                                /* CMSDK_DUALTIMER2 INTCLR: INT Clear Position */
#define CMSDK_DUALTIMER2_INTCLR_Msk          (0x1ul << CMSDK_DUALTIMER2_INTCLR_Pos)           /* CMSDK_DUALTIMER2 INTCLR: INT Clear  Mask */

#define CMSDK_DUALTIMER2_RAWINTSTAT_Pos      0                                                /* CMSDK_DUALTIMER2 RAWINTSTAT: Raw Int Status Position */
#define CMSDK_DUALTIMER2_RAWINTSTAT_Msk      (0x1ul << CMSDK_DUALTIMER2_RAWINTSTAT_Pos)       /* CMSDK_DUALTIMER2 RAWINTSTAT: Raw Int Status Mask */

#define CMSDK_DUALTIMER2_MASKINTSTAT_Pos     0                                                /* CMSDK_DUALTIMER2 MASKINTSTAT: Mask Int Status Position */
#define CMSDK_DUALTIMER2_MASKINTSTAT_Msk     (0x1ul << CMSDK_DUALTIMER2_MASKINTSTAT_Pos)      /* CMSDK_DUALTIMER2 MASKINTSTAT: Mask Int Status Mask */

#define CMSDK_DUALTIMER2_BGLOAD_Pos          0                                                /* CMSDK_DUALTIMER2 BGLOAD: Background Load Position */
#define CMSDK_DUALTIMER2_BGLOAD_Msk          (0xFFFFFFFFul << CMSDK_DUALTIMER2_BGLOAD_Pos)    /* CMSDK_DUALTIMER2 BGLOAD: Background Load Mask */


typedef struct
{
  __IO uint32_t TimerLoad;                   /* Offset: 0x000 (R/W) Timer Load */
  __I  uint32_t TimerValue;                  /* Offset: 0x000 (R/W) Timer Counter Current Value */
  __IO uint32_t TimerControl;                /* Offset: 0x000 (R/W) Timer Control */
  __O  uint32_t TimerIntClr;                 /* Offset: 0x000 (R/W) Timer Interrupt Clear */
  __I  uint32_t TimerRIS;                    /* Offset: 0x000 (R/W) Timer Raw Interrupt Status */
  __I  uint32_t TimerMIS;                    /* Offset: 0x000 (R/W) Timer Masked Interrupt Status */
  __IO uint32_t TimerBGLoad;                 /* Offset: 0x000 (R/W) Background Load Register */
} CMSDK_DUALTIMER_SINGLE_TypeDef;

#define CMSDK_DUALTIMER_LOAD_Pos             0                                               /* CMSDK_DUALTIMER LOAD: LOAD Position */
#define CMSDK_DUALTIMER_LOAD_Msk             (0xFFFFFFFFul << CMSDK_DUALTIMER_LOAD_Pos)      /* CMSDK_DUALTIMER LOAD: LOAD Mask */

#define CMSDK_DUALTIMER_VALUE_Pos            0                                               /* CMSDK_DUALTIMER VALUE: VALUE Position */
#define CMSDK_DUALTIMER_VALUE_Msk            (0xFFFFFFFFul << CMSDK_DUALTIMER_VALUE_Pos)     /* CMSDK_DUALTIMER VALUE: VALUE Mask */

#define CMSDK_DUALTIMER_CTRL_EN_Pos          7                                               /* CMSDK_DUALTIMER CTRL_EN: CTRL Enable Position */
#define CMSDK_DUALTIMER_CTRL_EN_Msk          (0x1ul << CMSDK_DUALTIMER_CTRL_EN_Pos)          /* CMSDK_DUALTIMER CTRL_EN: CTRL Enable Mask */

#define CMSDK_DUALTIMER_CTRL_MODE_Pos        6                                               /* CMSDK_DUALTIMER CTRL_MODE: CTRL MODE Position */
#define CMSDK_DUALTIMER_CTRL_MODE_Msk        (0x1ul << CMSDK_DUALTIMER_CTRL_MODE_Pos)        /* CMSDK_DUALTIMER CTRL_MODE: CTRL MODE Mask */

#define CMSDK_DUALTIMER_CTRL_INTEN_Pos       5                                               /* CMSDK_DUALTIMER CTRL_INTEN: CTRL Int Enable Position */
#define CMSDK_DUALTIMER_CTRL_INTEN_Msk       (0x1ul << CMSDK_DUALTIMER_CTRL_INTEN_Pos)       /* CMSDK_DUALTIMER CTRL_INTEN: CTRL Int Enable Mask */

#define CMSDK_DUALTIMER_CTRL_PRESCALE_Pos    2                                               /* CMSDK_DUALTIMER CTRL_PRESCALE: CTRL PRESCALE Position */
#define CMSDK_DUALTIMER_CTRL_PRESCALE_Msk    (0x3ul << CMSDK_DUALTIMER_CTRL_PRESCALE_Pos)    /* CMSDK_DUALTIMER CTRL_PRESCALE: CTRL PRESCALE Mask */

#define CMSDK_DUALTIMER_CTRL_SIZE_Pos        1                                               /* CMSDK_DUALTIMER CTRL_SIZE: CTRL SIZE Position */
#define CMSDK_DUALTIMER_CTRL_SIZE_Msk        (0x1ul << CMSDK_DUALTIMER_CTRL_SIZE_Pos)        /* CMSDK_DUALTIMER CTRL_SIZE: CTRL SIZE Mask */

#define CMSDK_DUALTIMER_CTRL_ONESHOOT_Pos    0                                               /* CMSDK_DUALTIMER CTRL_ONESHOOT: CTRL ONESHOOT Position */
#define CMSDK_DUALTIMER_CTRL_ONESHOOT_Msk    (0x1ul << CMSDK_DUALTIMER_CTRL_ONESHOOT_Pos)    /* CMSDK_DUALTIMER CTRL_ONESHOOT: CTRL ONESHOOT Mask */

#define CMSDK_DUALTIMER_INTCLR_Pos           0                                               /* CMSDK_DUALTIMER INTCLR: INT Clear Position */
#define CMSDK_DUALTIMER_INTCLR_Msk           (0x1ul << CMSDK_DUALTIMER_INTCLR_Pos)           /* CMSDK_DUALTIMER INTCLR: INT Clear  Mask */

#define CMSDK_DUALTIMER_RAWINTSTAT_Pos       0                                               /* CMSDK_DUALTIMER RAWINTSTAT: Raw Int Status Position */
#define CMSDK_DUALTIMER_RAWINTSTAT_Msk       (0x1ul << CMSDK_DUALTIMER_RAWINTSTAT_Pos)       /* CMSDK_DUALTIMER RAWINTSTAT: Raw Int Status Mask */

#define CMSDK_DUALTIMER_MASKINTSTAT_Pos      0                                               /* CMSDK_DUALTIMER MASKINTSTAT: Mask Int Status Position */
#define CMSDK_DUALTIMER_MASKINTSTAT_Msk      (0x1ul << CMSDK_DUALTIMER_MASKINTSTAT_Pos)      /* CMSDK_DUALTIMER MASKINTSTAT: Mask Int Status Mask */

#define CMSDK_DUALTIMER_BGLOAD_Pos           0                                               /* CMSDK_DUALTIMER BGLOAD: Background Load Position */
#define CMSDK_DUALTIMER_BGLOAD_Msk           (0xFFFFFFFFul << CMSDK_DUALTIMER_BGLOAD_Pos)    /* CMSDK_DUALTIMER BGLOAD: Background Load Mask */


/*-------------------- General Purpose Input Output (GPIO) -------------------*/
typedef struct
{
  __IO   uint32_t  DATA;                     /* Offset: 0x000 (R/W) DATA Register */
  __IO   uint32_t  DATAOUT;                  /* Offset: 0x004 (R/W) Data Output Latch Register */
         uint32_t  RESERVED0[2];
  __IO   uint32_t  OUTENABLESET;             /* Offset: 0x010 (R/W) Output Enable Set Register */
  __IO   uint32_t  OUTENABLECLR;             /* Offset: 0x014 (R/W) Output Enable Clear Register */
  __IO   uint32_t  ALTFUNCSET;               /* Offset: 0x018 (R/W) Alternate Function Set Register */
  __IO   uint32_t  ALTFUNCCLR;               /* Offset: 0x01C (R/W) Alternate Function Clear Register */
  __IO   uint32_t  INTENSET;                 /* Offset: 0x020 (R/W) Interrupt Enable Set Register */
  __IO   uint32_t  INTENCLR;                 /* Offset: 0x024 (R/W) Interrupt Enable Clear Register */
  __IO   uint32_t  INTTYPESET;               /* Offset: 0x028 (R/W) Interrupt Type Set Register */
  __IO   uint32_t  INTTYPECLR;               /* Offset: 0x02C (R/W) Interrupt Type Clear Register */
  __IO   uint32_t  INTPOLSET;                /* Offset: 0x030 (R/W) Interrupt Polarity Set Register */
  __IO   uint32_t  INTPOLCLR;                /* Offset: 0x034 (R/W) Interrupt Polarity Clear Register */
  union {
    __I    uint32_t  INTSTATUS;              /* Offset: 0x038 (R/ ) Interrupt Status Register */
    __O    uint32_t  INTCLEAR;               /* Offset: 0x038 ( /W) Interrupt Clear Register */
    };
         uint32_t RESERVED1[241];
  __IO   uint32_t LB_MASKED[256];            /* Offset: 0x400 - 0x7FC Lower byte Masked Access Register (R/W) */
  __IO   uint32_t UB_MASKED[256];            /* Offset: 0x800 - 0xBFC Upper byte Masked Access Register (R/W) */
} CMSDK_GPIO_TypeDef;

#define CMSDK_GPIO_DATA_Pos            0                                          /* CMSDK_GPIO DATA: DATA Position */
#define CMSDK_GPIO_DATA_Msk            (0xFFFFul << CMSDK_GPIO_DATA_Pos)          /* CMSDK_GPIO DATA: DATA Mask */

#define CMSDK_GPIO_DATAOUT_Pos         0                                          /* CMSDK_GPIO DATAOUT: DATAOUT Position */
#define CMSDK_GPIO_DATAOUT_Msk         (0xFFFFul << CMSDK_GPIO_DATAOUT_Pos)       /* CMSDK_GPIO DATAOUT: DATAOUT Mask */

#define CMSDK_GPIO_OUTENSET_Pos        0                                          /* CMSDK_GPIO OUTEN: OUTEN Position */
#define CMSDK_GPIO_OUTENSET_Msk        (0xFFFFul << CMSDK_GPIO_OUTEN_Pos)         /* CMSDK_GPIO OUTEN: OUTEN Mask */

#define CMSDK_GPIO_OUTENCLR_Pos        0                                          /* CMSDK_GPIO OUTEN: OUTEN Position */
#define CMSDK_GPIO_OUTENCLR_Msk        (0xFFFFul << CMSDK_GPIO_OUTEN_Pos)         /* CMSDK_GPIO OUTEN: OUTEN Mask */

#define CMSDK_GPIO_ALTFUNCSET_Pos      0                                          /* CMSDK_GPIO ALTFUNC: ALTFUNC Position */
#define CMSDK_GPIO_ALTFUNCSET_Msk      (0xFFFFul << CMSDK_GPIO_ALTFUNC_Pos)       /* CMSDK_GPIO ALTFUNC: ALTFUNC Mask */

#define CMSDK_GPIO_ALTFUNCCLR_Pos      0                                          /* CMSDK_GPIO ALTFUNC: ALTFUNC Position */
#define CMSDK_GPIO_ALTFUNCCLR_Msk      (0xFFFFul << CMSDK_GPIO_ALTFUNC_Pos)       /* CMSDK_GPIO ALTFUNC: ALTFUNC Mask */

#define CMSDK_GPIO_INTENSET_Pos        0                                          /* CMSDK_GPIO INTEN: INTEN Position */
#define CMSDK_GPIO_INTENSET_Msk        (0xFFFFul << CMSDK_GPIO_INTEN_Pos)         /* CMSDK_GPIO INTEN: INTEN Mask */

#define CMSDK_GPIO_INTENCLR_Pos        0                                          /* CMSDK_GPIO INTEN: INTEN Position */
#define CMSDK_GPIO_INTENCLR_Msk        (0xFFFFul << CMSDK_GPIO_INTEN_Pos)         /* CMSDK_GPIO INTEN: INTEN Mask */

#define CMSDK_GPIO_INTTYPESET_Pos      0                                          /* CMSDK_GPIO INTTYPE: INTTYPE Position */
#define CMSDK_GPIO_INTTYPESET_Msk      (0xFFFFul << CMSDK_GPIO_INTTYPE_Pos)       /* CMSDK_GPIO INTTYPE: INTTYPE Mask */

#define CMSDK_GPIO_INTTYPECLR_Pos      0                                          /* CMSDK_GPIO INTTYPE: INTTYPE Position */
#define CMSDK_GPIO_INTTYPECLR_Msk      (0xFFFFul << CMSDK_GPIO_INTTYPE_Pos)       /* CMSDK_GPIO INTTYPE: INTTYPE Mask */

#define CMSDK_GPIO_INTPOLSET_Pos       0                                          /* CMSDK_GPIO INTPOL: INTPOL Position */
#define CMSDK_GPIO_INTPOLSET_Msk       (0xFFFFul << CMSDK_GPIO_INTPOL_Pos)        /* CMSDK_GPIO INTPOL: INTPOL Mask */

#define CMSDK_GPIO_INTPOLCLR_Pos       0                                          /* CMSDK_GPIO INTPOL: INTPOL Position */
#define CMSDK_GPIO_INTPOLCLR_Msk       (0xFFFFul << CMSDK_GPIO_INTPOL_Pos)        /* CMSDK_GPIO INTPOL: INTPOL Mask */

#define CMSDK_GPIO_INTSTATUS_Pos       0                                          /* CMSDK_GPIO INTSTATUS: INTSTATUS Position */
#define CMSDK_GPIO_INTSTATUS_Msk       (0xFFul << CMSDK_GPIO_INTSTATUS_Pos)       /* CMSDK_GPIO INTSTATUS: INTSTATUS Mask */

#define CMSDK_GPIO_INTCLEAR_Pos        0                                          /* CMSDK_GPIO INTCLEAR: INTCLEAR Position */
#define CMSDK_GPIO_INTCLEAR_Msk        (0xFFul << CMSDK_GPIO_INTCLEAR_Pos)        /* CMSDK_GPIO INTCLEAR: INTCLEAR Mask */

#define CMSDK_GPIO_MASKLOWBYTE_Pos     0                                          /* CMSDK_GPIO MASKLOWBYTE: MASKLOWBYTE Position */
#define CMSDK_GPIO_MASKLOWBYTE_Msk     (0x00FFul << CMSDK_GPIO_MASKLOWBYTE_Pos)   /* CMSDK_GPIO MASKLOWBYTE: MASKLOWBYTE Mask */

#define CMSDK_GPIO_MASKHIGHBYTE_Pos    0                                          /* CMSDK_GPIO MASKHIGHBYTE: MASKHIGHBYTE Position */
#define CMSDK_GPIO_MASKHIGHBYTE_Msk    (0xFF00ul << CMSDK_GPIO_MASKHIGHBYTE_Pos)  /* CMSDK_GPIO MASKHIGHBYTE: MASKHIGHBYTE Mask */

/*------------- System Control (SYSCON) --------------------------------------*/
typedef struct
{
  __I  uint32_t SYS_VERSION;             /* Offset: 0x000 (R/ ) System Version register [cite: 3329] */
  __I  uint32_t SYS_CONFIG;              /* Offset: 0x004 (R/ ) System Hardware Configuration [cite: 3329] */
       uint32_t RESERVED0[1010];         /* Offset: 0x008 - 0xFCC */

  /* PID Registers: From 0xFD0 to 0xFEC [cite: 3330, 3331] */
  __I  uint32_t PID4;                    /* Offset: 0xFD0 */
  __I  uint32_t PID5;                    /* Offset: 0xFD4 */
  __I  uint32_t PID6;                    /* Offset: 0xFD8 */
  __I  uint32_t PID7;                    /* Offset: 0xFDC */
  __I  uint32_t PID0;                    /* Offset: 0xFE0 */
  __I  uint32_t PID1;                    /* Offset: 0xFE4 */
  __I  uint32_t PID2;                    /* Offset: 0xFE8 */
  __I  uint32_t PID3;                    /* Offset: 0xFEC */

  /* CID Registers: From 0xFF0 to 0xFFC [cite: 3331] */
  __I  uint32_t CID0;                    /* Offset: 0xFF0 */
  __I  uint32_t CID1;                    /* Offset: 0xFF4 */
  __I  uint32_t CID2;                    /* Offset: 0xFF8 */
  __I  uint32_t CID3;                    /* Offset: 0xFFC */
} SSE200_SYSINFO_TypeDef;

typedef struct
{
  __I  uint32_t SECDBGSTAT;              /* Offset: 0x000 (R/ ) Secure Debug Configuration Status */
  __O  uint32_t SECDBGSET;               /* Offset: 0x004 ( /W) Secure Debug Configuration Set */
  __O  uint32_t SECDBGCLR;               /* Offset: 0x008 ( /W) Secure Debug Configuration Clear */
  __IO uint32_t SCSECCTRL;               /* Offset: 0x00C (R/W) System Control Security Control */
  __IO uint32_t FCLK_DIV;                /* Offset: 0x010 (R/W) Fast Clock Divider Configuration */
  __IO uint32_t SYSCLK_DIV;              /* Offset: 0x014 (R/W) System Clock Divider Configuration */
  __IO uint32_t CLOCK_FORCE;             /* Offset: 0x018 (R/W) Clock Force */
       uint32_t RESERVED0[57];           /* Offset: 0x01C - 0x0FC Reserved */
  __IO uint32_t RESET_SYNDROME;          /* Offset: 0x100 (R/W) Reset Syndrome */
  __IO uint32_t RESET_MASK;              /* Offset: 0x104 (R/W) Reset Mask */
  __O  uint32_t SWRESET;                 /* Offset: 0x108 ( /W) Software Reset */
  __IO uint32_t GRETREG;                 /* Offset: 0x10C (R/W) General Purpose Retention */
  __IO uint32_t INITSVRTOR0;             /* Offset: 0x110 (R/W) Initial Secure Reset Vector for CPU 0 */
  __IO uint32_t INITSVRTOR1;             /* Offset: 0x114 (R/W) Initial Secure Reset Vector for CPU 1 */
  __IO uint32_t CPUWAIT;                 /* Offset: 0x118 (R/W) CPU Boot wait control */
  __IO uint32_t NMI_ENABLE;              /* Offset: 0x11C (R/W) NMI Enable Register */
  __IO uint32_t WICCTRL;                 /* Offset: 0x120 (R/W) WIC Control */
  __IO uint32_t EWCTRL;                  /* Offset: 0x124 (R/W) External Wakeup Control */
       uint32_t RESERVED1[54];
  __IO uint32_t PDCM_PD_SYS_SENSE;       /* Offset: 0x200 (R/W) Power Domain Sensitivity */
  
} SSE200_SYSCTRL_TypeDef;

/* Base address - Only SECURE */
#define SSE200_SYSINFO_NS_BASE  (0x40020000UL)
#define SSE200_SYSCTRL_S_BASE   (0x50021000UL)

/* RESET_SYNDROME Register (Offset: 0x100) */

#define SSE200_SYSCTRL_RST_SWRESETREQ_Pos       9                                                       /* Software Reset Request */
#define SSE200_SYSCTRL_RST_SWRESETREQ_Msk       (0x1ul << SSE200_SYSCTRL_RST_SWRESETREQ_Pos)

#define SSE200_SYSCTRL_RST_RESETREQ_Pos         8                                                       /* External Reset Request */
#define SSE200_SYSCTRL_RST_RESETREQ_Msk         (0x1ul << SSE200_SYSCTRL_RST_RESETREQ_Pos)

#define SSE200_SYSCTRL_RST_LOCKUP1_Pos          7                                                       /* CPU 1 Lock-up Status */
#define SSE200_SYSCTRL_RST_LOCKUP1_Msk          (0x1ul << SSE200_SYSCTRL_RST_LOCKUP1_Pos)

#define SSE200_SYSCTRL_RST_LOCKUP0_Pos          6                                                       /* CPU 0 Lock-up Status */
#define SSE200_SYSCTRL_RST_LOCKUP0_Msk          (0x1ul << SSE200_SYSCTRL_RST_LOCKUP0_Pos)

#define SSE200_SYSCTRL_RST_SYSRSTREQ1_Pos       5                                                       /* CPU 1 System Reset Request */
#define SSE200_SYSCTRL_RST_SYSRSTREQ1_Msk       (0x1ul << SSE200_SYSCTRL_RST_SYSRSTREQ1_Pos)

#define SSE200_SYSCTRL_RST_SYSRSTREQ0_Pos       4                                                       /* CPU 0 System Reset Request */
#define SSE200_SYSCTRL_RST_SYSRSTREQ0_Msk       (0x1ul << SSE200_SYSCTRL_RST_SYSRSTREQ0_Pos)

#define SSE200_SYSCTRL_RST_S32KWD_Pos           3                                                       /* Watchdog on S32KCLK */
#define SSE200_SYSCTRL_RST_S32KWD_Msk           (0x1ul << SSE200_SYSCTRL_RST_S32KWD_Pos)

#define SSE200_SYSCTRL_RST_SWD_Pos              2                                                       /* Secure Watchdog */
#define SSE200_SYSCTRL_RST_SWD_Msk              (0x1ul << SSE200_SYSCTRL_RST_SWD_Pos)

#define SSE200_SYSCTRL_RST_NSWD_Pos             1                                                       /* Non-secure Watchdog */
#define SSE200_SYSCTRL_RST_NSWD_Msk             (0x1ul << SSE200_SYSCTRL_RST_NSWD_Pos)

#define SSE200_SYSCTRL_RST_POR_Pos              0                                                       /* Power-on Reset */
#define SSE200_SYSCTRL_RST_POR_Msk              (0x1ul << SSE200_SYSCTRL_RST_POR_Pos)

/* RESET_MASK Register (Offset: 0x104) */
/* Table 3-75 RESET_MASK register (Page 3-132) */

#define SSE200_SYSCTRL_MASK_SYSRSTREQ1_Pos      5                                                       /* Enable Merging CPU 1 System Reset Request */
#define SSE200_SYSCTRL_MASK_SYSRSTREQ1_Msk      (0x1ul << SSE200_SYSCTRL_MASK_SYSRSTREQ1_Pos)

#define SSE200_SYSCTRL_MASK_SYSRSTREQ0_Pos      4                                                       /* Enable Merging CPU 0 System Reset Request */
#define SSE200_SYSCTRL_MASK_SYSRSTREQ0_Msk      (0x1ul << SSE200_SYSCTRL_MASK_SYSRSTREQ0_Pos)

#define SSE200_SYSCTRL_MASK_NSWD_Pos            1                                                       /* Enable NON-SECURE WATCHDOG Reset */
#define SSE200_SYSCTRL_MASK_NSWD_Msk            (0x1ul << SSE200_SYSCTRL_MASK_NSWD_Pos)

/* PL080 DMA Controller definitions */
typedef struct {
    __I  uint32_t IntStatus;       /* 0x000 Interrupt Status */
    __I  uint32_t IntTCStatus;     /* 0x004 Interrupt Terminal Count Status */
    __IO uint32_t IntTCClear;      /* 0x008 Interrupt Terminal Count Clear */
    __I  uint32_t IntErrorStatus;  /* 0x00C Interrupt Error Status */
    __IO uint32_t IntErrorClear;   /* 0x010 Interrupt Error Clear */
    __I  uint32_t RawIntTCStatus;  /* 0x014 Raw Interrupt Terminal Count Status */
    __I  uint32_t RawIntErrorStatus; /* 0x018 Raw Interrupt Error Status */
    __IO uint32_t EnbldChns;       /* 0x01C Enabled Channels */
    __IO uint32_t SoftBReq;        /* 0x020 Software Burst Request */
    __IO uint32_t SoftSReq;        /* 0x024 Software Single Request */
    __IO uint32_t SoftLBReq;       /* 0x028 Software Last Burst Request */
    __IO uint32_t SoftLSReq;       /* 0x02C Software Last Single Request */
    __IO uint32_t Configuration;   /* 0x030 Configuration Register */
    __IO uint32_t Sync;            /* 0x034 Synchronization Register */
    /* ... Các thanh ghi Channel (Offset 0x100 trở đi) ... */
} CMSDK_DMA_TypeDef;

#define CMSDK_DMA0_BASE_S   (0x50202000UL) // Secure
#define CMSDK_DMA0_BASE_NS  (0x40202000UL) // Non-secure


/*------------------- Watchdog ----------------------------------------------*/
/* Table 3-22 Summary of Watchdog registers*/
typedef struct
{

  __IO    uint32_t  LOAD;                   /* Offset: 0x000 (R/W) Watchdog Load Register */
  __I     uint32_t  VALUE;                  /* Offset: 0x004 (R/ ) Watchdog Value Register */
  __IO    uint32_t  CTRL;                   /* Offset: 0x008 (R/W) Watchdog Control Register */
  __O     uint32_t  INTCLR;                 /* Offset: 0x00C ( /W) Watchdog Clear Interrupt Register */
  __I     uint32_t  RAWINTSTAT;             /* Offset: 0x010 (R/ ) Watchdog Raw Interrupt Status Register */
  __I     uint32_t  MASKINTSTAT;            /* Offset: 0x014 (R/ ) Watchdog Interrupt Status Register */
        uint32_t  RESERVED0[762];
  __IO    uint32_t  LOCK;                   /* Offset: 0xC00 (R/W) Watchdog Lock Register */
        uint32_t  RESERVED1[191];
  __IO    uint32_t  ITCR;                   /* Offset: 0xF00 (R/W) Watchdog Integration Test Control Register */
  __O     uint32_t  ITOP;                   /* Offset: 0xF04 ( /W) Watchdog Integration Test Output Set Register */
}CMSDK_WATCHDOG_TypeDef;

#define CMSDK_Watchdog_LOAD_Pos               0                                              /* CMSDK_Watchdog LOAD: LOAD Position */
#define CMSDK_Watchdog_LOAD_Msk              (0xFFFFFFFFul << CMSDK_Watchdog_LOAD_Pos)       /* CMSDK_Watchdog LOAD: LOAD Mask */

#define CMSDK_Watchdog_VALUE_Pos              0                                              /* CMSDK_Watchdog VALUE: VALUE Position */
#define CMSDK_Watchdog_VALUE_Msk             (0xFFFFFFFFul << CMSDK_Watchdog_VALUE_Pos)      /* CMSDK_Watchdog VALUE: VALUE Mask */

#define CMSDK_Watchdog_CTRL_RESEN_Pos         1                                              /* CMSDK_Watchdog CTRL_RESEN: Enable Reset Output Position */
#define CMSDK_Watchdog_CTRL_RESEN_Msk        (0x1ul << CMSDK_Watchdog_CTRL_RESEN_Pos)        /* CMSDK_Watchdog CTRL_RESEN: Enable Reset Output Mask */

#define CMSDK_Watchdog_CTRL_INTEN_Pos         0                                              /* CMSDK_Watchdog CTRL_INTEN: Int Enable Position */
#define CMSDK_Watchdog_CTRL_INTEN_Msk        (0x1ul << CMSDK_Watchdog_CTRL_INTEN_Pos)        /* CMSDK_Watchdog CTRL_INTEN: Int Enable Mask */

#define CMSDK_Watchdog_INTCLR_Pos             0                                              /* CMSDK_Watchdog INTCLR: Int Clear Position */
#define CMSDK_Watchdog_INTCLR_Msk            (0x1ul << CMSDK_Watchdog_INTCLR_Pos)            /* CMSDK_Watchdog INTCLR: Int Clear Mask */

#define CMSDK_Watchdog_RAWINTSTAT_Pos         0                                              /* CMSDK_Watchdog RAWINTSTAT: Raw Int Status Position */
#define CMSDK_Watchdog_RAWINTSTAT_Msk        (0x1ul << CMSDK_Watchdog_RAWINTSTAT_Pos)        /* CMSDK_Watchdog RAWINTSTAT: Raw Int Status Mask */

#define CMSDK_Watchdog_MASKINTSTAT_Pos        0                                              /* CMSDK_Watchdog MASKINTSTAT: Mask Int Status Position */
#define CMSDK_Watchdog_MASKINTSTAT_Msk       (0x1ul << CMSDK_Watchdog_MASKINTSTAT_Pos)       /* CMSDK_Watchdog MASKINTSTAT: Mask Int Status Mask */

#define CMSDK_Watchdog_LOCK_Pos               0                                              /* CMSDK_Watchdog LOCK: LOCK Position */
#define CMSDK_Watchdog_LOCK_Msk              (0x1ul << CMSDK_Watchdog_LOCK_Pos)              /* CMSDK_Watchdog LOCK: LOCK Mask */

#define CMSDK_Watchdog_INTEGTESTEN_Pos        0                                              /* CMSDK_Watchdog INTEGTESTEN: Integration Test Enable Position */
#define CMSDK_Watchdog_INTEGTESTEN_Msk       (0x1ul << CMSDK_Watchdog_INTEGTESTEN_Pos)       /* CMSDK_Watchdog INTEGTESTEN: Integration Test Enable Mask */

#define CMSDK_Watchdog_INTEGTESTOUTSET_Pos    1                                              /* CMSDK_Watchdog INTEGTESTOUTSET: Integration Test Output Set Position */
#define CMSDK_Watchdog_INTEGTESTOUTSET_Msk   (0x1ul << CMSDK_Watchdog_INTEGTESTOUTSET_Pos)   /* CMSDK_Watchdog INTEGTESTOUTSET: Integration Test Output Set Mask */

/* 1. Non-Secure Watchdog [cite: 2565] */
#define CMSDK_WATCHDOG_NS_BASE   (0x40081000UL)
#define CMSDK_WATCHDOG_NS        ((CMSDK_WATCHDOG_TypeDef *) CMSDK_WATCHDOG_NS_BASE)

/* 2. Secure Watchdog [cite: 2565] */
#define CMSDK_WATCHDOG_S_BASE    (0x50081000UL)
#define CMSDK_WATCHDOG_S         ((CMSDK_WATCHDOG_TypeDef *) CMSDK_WATCHDOG_S_BASE)

/* 3. S32K Watchdog (Secure Only, System Control Element) [cite: 3321] */
#define CMSDK_S32K_WATCHDOG_BASE (0x5002E000UL)
#define CMSDK_S32K_WATCHDOG      ((CMSDK_WATCHDOG_TypeDef *) CMSDK_S32K_WATCHDOG_BASE)


/* --------  End of section using anonymous unions and disabling warnings  -------- */
#if   defined (__CC_ARM)
  #pragma pop
#elif defined (__ICCARM__)
  /* leave anonymous unions enabled */
#elif (defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050))
  #pragma clang diagnostic pop
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning restore
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif


/* ================================================================================ */
/* ================              Peripheral memory map             ================ */
/* ================================================================================ */

/* --------------------------  Memory Map Regions  ---------------------------- */
/* Dẫn chứng: Figure 3-1 SSE-200 top-level memory map [cite: 2461] */
#define CMSDK_FLASH_BASE        (0x00000000UL) /* Code Memory (NS) */
#define CMSDK_FLASH_S_BASE      (0x10000000UL) /* Code Memory (S) */
#define CMSDK_SRAM_BASE         (0x20000000UL) /* SRAM (NS) */
#define CMSDK_SRAM_S_BASE       (0x30000000UL) /* SRAM (S) */

/* Base Element Peripheral Regions (Timers, Watchdogs) */
/* Dẫn chứng: Table 3-4 Base peripheral regions  */
#define CMSDK_BASE_PERIPH_NS_BASE  (0x40000000UL)
#define CMSDK_BASE_PERIPH_S_BASE   (0x50000000UL)

/* Expansion 1 Regions (GPIO, UART, DMA) */
/* Dẫn chứng: Table 3-1, ID 19 (NS) và ID 26 (S) [cite: 2498] */
#define CMSDK_EXPANSION1_NS_BASE   (0x40100000UL)
#define CMSDK_EXPANSION1_S_BASE    (0x50100000UL)

/* System Control Regions */
/* Dẫn chứng: Table 3-5 System control regions [cite: 3302] */
#define CMSDK_SYS_INFO_NS_BASE     (0x40020000UL)
#define CMSDK_SYS_INFO_S_BASE      (0x50020000UL)

/* ================================================================================ */
/* ================             Peripheral Addresses               ================ */
/* ================================================================================ */

/* -------------------------  Base Element Peripherals  --------------------------- */
/* Table 3-4  */

/* Timer 0 */
#define CMSDK_TIMER0_NS_BASE    (0x40000000UL)
#define CMSDK_TIMER0_S_BASE     (0x50000000UL)

/* Timer 1 */
#define CMSDK_TIMER1_NS_BASE    (0x40001000UL)
#define CMSDK_TIMER1_S_BASE     (0x50001000UL)

/* Dual Timer */
#define CMSDK_DUALTIMER_NS_BASE (0x40002000UL)
#define CMSDK_DUALTIMER_S_BASE  (0x50002000UL)

/* Message Handling Units (MHU) */
#define CMSDK_MHU0_NS_BASE      (0x40003000UL)
#define CMSDK_MHU0_S_BASE       (0x50003000UL)
#define CMSDK_MHU1_NS_BASE      (0x40004000UL) /* Cảnh báo: UART cũ nằm ở đây */
#define CMSDK_MHU1_S_BASE       (0x50004000UL)

/* Watchdogs */
#define CMSDK_WATCHDOG_NS_BASE  (0x40081000UL) /* Non-secure Watchdog */
#define CMSDK_WATCHDOG_S_BASE   (0x50081000UL) /* Secure Watchdog */

/* -----------------------  System Control Peripherals  --------------------------- */
/* able 3-5 [cite: 3302] */

#define SSE200_SYSINFO_NS_BASE  (0x40020000UL) /* System Info (NS) */
#define SSE200_SYSINFO_S_BASE   (0x50020000UL) /* System Info (S) */

#define SSE200_SYSCTRL_S_BASE   (0x50021000UL) /* System Control (Secure Only) */

/* S32K Timers (Slow Clock) */
#define CMSDK_S32K_TIMER_NS_BASE (0x4002F000UL)
#define CMSDK_S32K_TIMER_S_BASE  (0x5002F000UL)
#define CMSDK_S32K_WATCHDOG_BASE (0x5002E000UL) /* Secure Only */

/* -----------------------  Expansion 1 Peripherals (AN521) ----------------------- */
/* Các ngoại vi này nằm trong vùng Expansion 1 (0x4010_0000 - 0x4FFF_FFFF) */

/* GPIO - Dựa trên cấu hình chuẩn AN521 */
#define CMSDK_GPIO0_NS_BASE     (0x40100000UL)
#define CMSDK_GPIO0_S_BASE      (0x50100000UL)
#define CMSDK_GPIO1_NS_BASE     (0x40101000UL)
#define CMSDK_GPIO1_S_BASE      (0x50101000UL)
#define CMSDK_GPIO2_NS_BASE     (0x40102000UL)
#define CMSDK_GPIO2_S_BASE      (0x50102000UL)
#define CMSDK_GPIO3_NS_BASE     (0x40103000UL)
#define CMSDK_GPIO3_S_BASE      (0x50103000UL)

/* UART - AN521 */
#define CMSDK_UART0_NS_BASE     (0x40200000UL) 
#define CMSDK_UART0_S_BASE      (0x50200000UL)
#define CMSDK_UART1_NS_BASE     (0x40201000UL)
#define CMSDK_UART1_S_BASE      (0x50201000UL)
#define CMSDK_UART2_NS_BASE     (0x40202000UL)
#define CMSDK_UART2_S_BASE      (0x50202000UL)
#define CMSDK_UART3_NS_BASE     (0x40203000UL)
#define CMSDK_UART3_S_BASE      (0x50203000UL)
#define CMSDK_UART4_NS_BASE     (0x40204000UL)
#define CMSDK_UART4_S_BASE      (0x50204000UL)

/* DMA Controller (PL080) - Thay thế PL230 */
/* Code cũ: #define CMSDK_PL230_BASE (CMSDK_APB_BASE + 0xF000UL) -> SAI */
#define CMSDK_DMA_NS_BASE       (0x40028000UL) /* AN521 DMA Address */
#define CMSDK_DMA_S_BASE        (0x50028000UL)


/* ================================================================================ */
/* ================             Peripheral declaration             ================ */
/* ================================================================================ */

/* -------------------------  Base Element Peripherals  --------------------------- */

/* Timers (CMSDK APB Timer) */
#define CMSDK_TIMER0_NS         ((CMSDK_TIMER_TypeDef          *) CMSDK_TIMER0_NS_BASE)
#define CMSDK_TIMER0_S          ((CMSDK_TIMER_TypeDef          *) CMSDK_TIMER0_S_BASE)

#define CMSDK_TIMER1_NS         ((CMSDK_TIMER_TypeDef          *) CMSDK_TIMER1_NS_BASE)
#define CMSDK_TIMER1_S          ((CMSDK_TIMER_TypeDef          *) CMSDK_TIMER1_S_BASE)

/* Dual Timer (CMSDK Dual Timer) */
#define CMSDK_DUALTIMER_NS      ((CMSDK_DUALTIMER_BOTH_TypeDef *) CMSDK_DUALTIMER_NS_BASE)
#define CMSDK_DUALTIMER_S       ((CMSDK_DUALTIMER_BOTH_TypeDef *) CMSDK_DUALTIMER_S_BASE)

/* Watchdogs (CMSDK Watchdog) */
/* Lưu ý: Watchdog có 3 instance riêng biệt */
#define CMSDK_WATCHDOG_NS       ((CMSDK_WATCHDOG_TypeDef       *) CMSDK_WATCHDOG_NS_BASE)
#define CMSDK_WATCHDOG_S        ((CMSDK_WATCHDOG_TypeDef       *) CMSDK_WATCHDOG_S_BASE)
#define CMSDK_S32K_WATCHDOG     ((CMSDK_WATCHDOG_TypeDef       *) CMSDK_S32K_WATCHDOG_BASE)

/* -----------------------  System Control Peripherals  --------------------------- */

/* System Information (Access both NS and S) */
#define SSE200_SYSINFO_NS       ((SSE200_SYSINFO_TypeDef       *) SSE200_SYSINFO_NS_BASE)
#define SSE200_SYSINFO_S        ((SSE200_SYSINFO_TypeDef       *) SSE200_SYSINFO_S_BASE)

/* System Control (Only Secure) */
#define SSE200_SYSCTRL_S        ((SSE200_SYSCTRL_TypeDef       *) SSE200_SYSCTRL_S_BASE)

/* -----------------------  Expansion Peripherals (AN521) ----------------------- */

/* GPIO (CMSDK AHB GPIO) */
#define CMSDK_GPIO0_NS          ((CMSDK_GPIO_TypeDef           *) CMSDK_GPIO0_NS_BASE)
#define CMSDK_GPIO0_S           ((CMSDK_GPIO_TypeDef           *) CMSDK_GPIO0_S_BASE)

#define CMSDK_GPIO1_NS          ((CMSDK_GPIO_TypeDef           *) CMSDK_GPIO1_NS_BASE)
#define CMSDK_GPIO1_S           ((CMSDK_GPIO_TypeDef           *) CMSDK_GPIO1_S_BASE)

#define CMSDK_GPIO2_NS          ((CMSDK_GPIO_TypeDef           *) CMSDK_GPIO2_NS_BASE)
#define CMSDK_GPIO2_S           ((CMSDK_GPIO_TypeDef           *) CMSDK_GPIO2_S_BASE)

#define CMSDK_GPIO3_NS          ((CMSDK_GPIO_TypeDef           *) CMSDK_GPIO3_NS_BASE)
#define CMSDK_GPIO3_S           ((CMSDK_GPIO_TypeDef           *) CMSDK_GPIO3_S_BASE)

/* UART (CMSDK APB UART) */
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

/* DMA Controller (PL080) */
#define CMSDK_DMA_NS            ((CMSDK_DMA_TypeDef            *) CMSDK_DMA_NS_BASE)
#define CMSDK_DMA_S             ((CMSDK_DMA_TypeDef            *) CMSDK_DMA_S_BASE)


#ifdef __cplusplus
}
#endif

#endif 