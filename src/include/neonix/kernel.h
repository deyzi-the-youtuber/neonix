#ifndef __NEONIX_KERNEL_H
#define __NEONIX_KERNEL_H

#include <neonix/types.h>
#include <lib/common.h>
#include <lib/limine.h>

struct boot_information {
    struct limine_framebuffer_response * const framebuffer;
    struct limine_memmap_response * const memmap;
    struct limine_paging_mode_request * const paging;
    size_t total_mem;
} boot_information = {
    NULL,
    NULL,
    NULL,
    0
};

#endif