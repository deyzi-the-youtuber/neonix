ARCH ?= x86_64
CROSS_COMPILER ?= x86_64-elf-

CC = $(CROSS_COMPILER)gcc
CXX = $(CROSS_COMPILER)g++
LD = $(CROSS_COMPILER)ld

LD_FLAGS = \
	-z max-page-size=0x1000 \
	-T $(CURDIR)/arch/$(ARCH)/$(ARCH).ld

CC_FLAGS = \
	-I ./include/ \
	-ffreestanding \
	-Wall \
	-Wextra \
	-Werror \
	-mcmodel=large \
	-mno-red-zone \
	-std=gnu99 \
	-mno-mmx \
	-mno-sse \
	-O0 \
	-g

CXX_FLAGS = $(CC_FLAGS)

# All source files
C_ALL_SOURCE := $(shell find . -type f -name '*.c')
ASM_ALL_SOURCE := $(shell find . -type f -name '*.S')
# Architecture specific files
C_ARCH_SOURCE := $(filter ./arch/$(ARCH)/%.c, $(C_ALL_SOURCE))
ASM_ARCH_SOURCE := $(filter ./arch/$(ARCH)/%.S, $(ASM_ALL_SOURCE))
# Common source files (not architecture specific)
C_COMMON_SOURCE := $(filter-out ./arch/%, $(filter-out ./arch/$(ARCH)/%.c, $(C_ALL_SOURCE)))
# All source files needed to compile for architecture
C_SOURCE := $(C_COMMON_SOURCE) $(C_ARCH_SOURCE)
ASM_SOURCE := $(ASM_ARCH_SOURCE)

C_OBJECTS := $(patsubst %.c, %.o, $(C_SOURCE))
ASM_OBJECTS := $(patsubst %.S, %.o, $(ASM_SOURCE))

OUT := lunaris

.PHONY: $(OUT)
all: $(OUT)

$(OUT): $(C_OBJECTS) $(ASM_OBJECTS)
	$(LD) $(LD_FLAGS) $^ -o $(OUT)

%.o: %.S
	$(CC) $(CC_FLAGS) $(CC_FLAGS_USER) -c $< -o $@

%.o: %.c
	$(CC) $(CC_FLAGS) $(CC_FLAGS_USER) -c $< -o $@

clean:
	@rm -f $(C_OBJECTS) $(ASM_OBJECTS) $(OUT)
