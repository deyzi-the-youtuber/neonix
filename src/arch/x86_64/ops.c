#include <arch/ops.h>
#include <neonix/compiler.h>

void _noreturn arch_die(void) {
    asm volatile("cli");
    asm volatile("hlt");
    unreachable;
}