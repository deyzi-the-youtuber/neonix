#ifndef __BOOTLOADER_REQUESTS_H
#define __BOOTLOADER_REQUESTS_H

#include <lib/limine.h>

/*
    This file should only be used ONCE. The only file that should include this is entry.c
*/

static volatile LIMINE_ATTRIBUTE_REQUEST LIMINE_BASE_REVISION(3);
static volatile LIMINE_ATTRIBUTE_REQUESTS_START LIMINE_REQUESTS_START_MARKER;
static volatile LIMINE_ATTRIBUTE_REQUESTS_END LIMINE_REQUESTS_END_MARKER;

static volatile LIMINE_ATTRIBUTE_REQUEST struct limine_framebuffer_request framebuffer_request = {
    .id = LIMINE_FRAMEBUFFER_REQUEST,
    .revision = 0
};

static volatile LIMINE_ATTRIBUTE_REQUEST struct limine_paging_mode_request paging_request = {
    .id = LIMINE_PAGING_MODE_REQUEST,
    .mode = LIMINE_PAGING_MODE_X86_64_4LVL
};

#endif