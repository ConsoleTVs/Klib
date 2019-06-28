#ifndef KLIB_UTILS_H
#define KLIB_UTILS_H

#include <stdio.h>
#include <stddef.h>

// Cross platform terminal window size.
void get_window_size(size_t *const rows, size_t *const cols);

// Cross platform red printing for errors.
int red_printf(const char *format, ...);

#endif
