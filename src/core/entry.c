#include <arch/ops.h>
#include <neonix/kernel.h>
#include <lib/limine.h>
#include <lib/bool.h>

#include "requests.h"

void neonix_setup(void) {
    if(LIMINE_BASE_REVISION_SUPPORTED == false) {
        arch_die();
    }
    // we wont do anything for now
    for(;;);
    //arch_early_init();
}