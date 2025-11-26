#include <stdint.h>

/* Định nghĩa cứng địa chỉ các thanh ghi quan trọng của Cortex-M33 */
#define SCB_CPACR   (*(volatile uint32_t *)0xE000ED88) /* Coprocessor Access Control */
#define SCB_VTOR    (*(volatile uint32_t *)0xE000ED08) /* Vector Table Offset */
#define SCB_MSPLIM  (*(volatile uint32_t *)0xE0001820) /* Main Stack Pointer Limit */
#define SCB_PSPLIM  (*(volatile uint32_t *)0xE0001824) /* Process Stack Pointer Limit */

uint32_t SystemCoreClock = 25000000;

void SystemInit(void)
{
    /* 1. BẬT FPU (Floating Point Unit) - QUAN TRỌNG NHẤT */
    /* Set bit 20-23 (CP10 và CP11) lên 11 (Full Access) */
    SCB_CPACR |= ((3UL << 20U) | (3UL << 22U));

    /* 2. Cập nhật Vector Table về vùng Secure Flash (0x10000000) */
    SCB_VTOR = 0x10000000;

    /* 3. Tắt giới hạn Stack (Tránh lỗi Stack Overflow giả khi khởi động) */
    /* Mặc định MSPLIM = 0. Nếu Stack Pointer của bạn > 0 thì không sao,
       nhưng set về 0 cho chắc chắn an toàn */
    __asm volatile ("msr msplim, %0" : : "r" (0));
    __asm volatile ("msr psplim, %0" : : "r" (0));
}

void SystemCoreClockUpdate(void)
{
    SystemCoreClock = 25000000;
}