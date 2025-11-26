/* Linker Script cho MPS2-AN521 (Cortex-M33) - SECURE ONLY */
ENTRY(Reset_Handler)

_Min_Heap_Size  = 0x200;
_Min_Stack_Size = 0x400;

MEMORY
{
    /* ĐỔI TỪ 0x00000000 SANG 0x10000000 (Secure Flash) */
    FLASH (rx)  : ORIGIN = 0x10000000, LENGTH = 4M
    
    /* ĐỔI TỪ 0x20000000 SANG 0x30000000 (Secure RAM) */
    RAM   (rwx) : ORIGIN = 0x30000000, LENGTH = 4M
}

_estack = ORIGIN(RAM) + LENGTH(RAM);

SECTIONS
{
    /* ... (Giữ nguyên nội dung các section bên trong) ... */
    /* Chỉ thay đổi phần MEMORY ở trên thôi */
    .isr_vector :
    {
        . = ALIGN(0x100); /* Giữ nguyên ALIGN 0x100 bạn đã sửa */
        KEEP(*(.isr_vector))
        . = ALIGN(4);
    } > FLASH
    
    /* ... (Copy y nguyên các đoạn .text, .data, .bss, .heap cũ vào) ... */
    
    .text :
    {
        . = ALIGN(4);
        *(.text)
        *(.text*)
        *(.rodata)
        *(.rodata*)
        *(.glue_7)
        *(.glue_7t)
        *(.eh_frame)
        KEEP (*(.init))
        KEEP (*(.fini))
        . = ALIGN(4);
        _etext = .;
    } > FLASH

    _sidata = LOADADDR(.data);

    .data :
    {
        . = ALIGN(4);
        _sdata = .;
        *(.data)
        *(.data*)
        . = ALIGN(4);
        _edata = .;
    } > RAM AT > FLASH

    .bss :
    {
        . = ALIGN(4);
        _sbss = .;
        __bss_start__ = _sbss;
        *(.bss)
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        _ebss = .;
        __bss_end__ = _ebss;
    } > RAM

    ._user_heap_stack :
    {
        . = ALIGN(8);
        PROVIDE ( end = . );
        PROVIDE ( _end = . );
        . = . + _Min_Heap_Size;
        . = . + _Min_Stack_Size;
        . = ALIGN(8);
    } > RAM

    /DISCARD/ :
    {
        libc.a ( * )
        libm.a ( * )
        libgcc.a ( * )
    }
    .ARM.attributes 0 : { *(.ARM.attributes) }
}