#ifndef __MY_SNPRINTF__H__
#define __MY_SNPRINTF__H__

#include <stdarg.h>

#include "main.h"
#include "number_operations.h"
#include "constants.h"

int my_snprintf(char *restrict buf, size_t num, const char *restrict format, ...);
void c_processing(char *restrict buf, size_t num, const char *restrict *format, char ch, size_t *actual_len);
void num_processing(char *restrict buf, size_t num, const char *restrict *format, int decimal, size_t *actual_len,
char *alphabet, int foundation);
void s_processing(char *restrict buf, size_t num, const char *restrict *format, char *str, size_t *actual_len);

#endif