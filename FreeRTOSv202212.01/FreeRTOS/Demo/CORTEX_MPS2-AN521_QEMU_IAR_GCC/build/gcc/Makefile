OUTPUT_DIR := ./output
IMAGE := RTOSDemo.out

# ===========================================================================
# 1. CẤU HÌNH ĐƯỜNG DẪN (PATHS)
# ===========================================================================

# Thư mục gốc của FreeRTOS (Đi ngược lên 4 cấp từ build/gcc)
FREERTOS_ROOT = ./../../../../

# Thư mục gốc của Project (Chứa main.c, startup_gcc.c...)
# Đi ngược lên 2 cấp từ build/gcc
PROJECT_ROOT = ../..

# Toolchain
CC = arm-none-eabi-gcc
LD = arm-none-eabi-gcc
SIZE = arm-none-eabi-size
MAKE = make

# ===========================================================================
# 2. CỜ BIÊN DỊCH (COMPILER FLAGS) - Cortex-M33 / AN521
# ===========================================================================

# Cấu hình CPU & FPU (Cortex-M33 có FPU)
CPU_FLAGS = -mthumb -mcpu=cortex-m33 -mfloat-abi=hard -mfpu=fpv5-sp-d16

# Các cờ C chung
CFLAGS += $(CPU_FLAGS)
CFLAGS += -DPROJ_MPS2_AN521 -D__ARM_CORTEX_M33
CFLAGS += -Wall -Wextra -g3 -O0
CFLAGS += -ffunction-sections -fdata-sections
CFLAGS += -nostartfiles -ffreestanding
CFLAGS += -MMD -MP -MF"$(@:%.o=%.d)" -MT $@

# [QUAN TRỌNG] Đường dẫn Include
# 1. Thư mục build hiện tại (.) chứa FreeRTOSConfig.h
# 2. Thư mục gốc project (..) chứa system_CMSDK_CM33.h, CMSDK_CM33.h
# 3. Thư mục CMSIS chứa các file header của ARM (core_cm33.h, cmsis_version.h...)
INCLUDE_DIRS += -I. -I$(PROJECT_ROOT) -I$(PROJECT_ROOT)/CMSIS

# Cờ Linker
LDFLAGS = $(CPU_FLAGS) -Xlinker --gc-sections -specs=nano.specs -specs=nosys.specs

# ===========================================================================
# 3. FREERTOS KERNEL & PORT
# ===========================================================================
KERNEL_DIR = $(FREERTOS_ROOT)/Source

# [QUAN TRỌNG] Đường dẫn Port cho M33 Non-TrustZone (NTZ)
# Dựa trên kết quả ls -R của bạn, file port.c nằm trong thư mục con "non_secure"
PORT_DIR = $(KERNEL_DIR)/portable/GCC/ARM_CM33_NTZ/non_secure

INCLUDE_DIRS += -I$(KERNEL_DIR)/include \
				-I$(PORT_DIR)

# VPATH giúp make tìm thấy file nguồn ở các thư mục khác
VPATH += $(KERNEL_DIR) $(PORT_DIR) $(KERNEL_DIR)/portable/MemMang

# Danh sách file nguồn Kernel
SOURCE_FILES += $(PROJECT_ROOT)/system_CMSDK_CM33.c
SOURCE_FILES += $(KERNEL_DIR)/tasks.c
SOURCE_FILES += $(KERNEL_DIR)/list.c
SOURCE_FILES += $(KERNEL_DIR)/queue.c
SOURCE_FILES += $(KERNEL_DIR)/timers.c
SOURCE_FILES += $(KERNEL_DIR)/event_groups.c
SOURCE_FILES += $(KERNEL_DIR)/stream_buffer.c
SOURCE_FILES += $(KERNEL_DIR)/portable/MemMang/heap_4.c
SOURCE_FILES += $(PORT_DIR)/port.c
SOURCE_FILES += $(PORT_DIR)/portasm.c

# ===========================================================================
# 4. DEMO & APPLICATION SOURCES
# ===========================================================================
DEMO_ROOT = $(FREERTOS_ROOT)/Demo
COMMON_DEMO_FILES = $(DEMO_ROOT)/Common/Minimal

INCLUDE_DIRS += -I$(DEMO_ROOT)/Common/include
VPATH += $(COMMON_DEMO_FILES)

# Thêm thư mục gốc project vào VPATH để tìm main.c
VPATH += $(PROJECT_ROOT)

# File ứng dụng chính
SOURCE_FILES += $(PROJECT_ROOT)/main.c

# File khởi động và driver (Nằm ở thư mục gốc project)
SOURCE_FILES += $(PROJECT_ROOT)/startup_gcc.c
SOURCE_FILES += $(PROJECT_ROOT)/printf-stdarg.c

# ===========================================================================
# 5. XỬ LÝ OUTPUT & BUILD RULES
# ===========================================================================

# Gộp tất cả đường dẫn include vào CFLAGS
CFLAGS += $(INCLUDE_DIRS)

# Tạo danh sách file object (.o)
OBJS = $(SOURCE_FILES:%.c=%.o)
OBJS_NO_PATH = $(notdir $(OBJS))
OBJS_OUTPUT = $(OBJS_NO_PATH:%.o=$(OUTPUT_DIR)/%.o)

# Quy tắc dependency
DEP_FILES := $(SOURCE_FILES:%.c=$(OUTPUT_DIR)/%.d)
DEP_FILES_NO_PATH = $(notdir $(DEP_FILES))
DEP_OUTPUT = $(DEP_FILES_NO_PATH:%.d=$(OUTPUT_DIR)/%.d)

# --- Rule Chính: Build tất cả ---
all: $(OUTPUT_DIR)/$(IMAGE)

# --- Rule: Compile .c -> .o ---
$(OUTPUT_DIR)/%.o : %.c Makefile
	@mkdir -p $(OUTPUT_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# --- Rule: Link .o -> .out ---
# Sử dụng file linker mps2_an521.ld nằm cùng thư mục với Makefile
$(OUTPUT_DIR)/$(IMAGE): ./mps2_an521.ld $(OBJS_OUTPUT) Makefile
	@echo ""
	@echo "--- Linking for Cortex-M33 (MPS2-AN521) ---"
	$(LD) $(OBJS_OUTPUT) $(LDFLAGS) -T ./mps2_an521.ld \
		-Xlinker -Map=$(OUTPUT_DIR)/RTOSDemo.map \
		-o $(OUTPUT_DIR)/$(IMAGE)
	@echo ""
	@echo "--- Build Size Information ---"
	$(SIZE) $(OUTPUT_DIR)/$(IMAGE)

# --- Rule: Clean ---
clean:
	rm -rf $(OUTPUT_DIR)

.PHONY: all clean