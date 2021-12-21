#ifndef __TRANSLATION__H__
#define __TRANSLATION__H__

#include <stdarg.h>
#include <limits.h>

#include "main.h"
#include "constants.h"

int number_length(int num, int foundation);
void num_to_str(int decimal, char *str, char *alphabet, int foundation);
void reverse(char *str, int first_idx, int len);
void swap(char *str, int idx1, int idx2);

#endif