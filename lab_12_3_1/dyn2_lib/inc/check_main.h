#ifndef __C_MAIN__H__
#define __C_MAIN__H__

#include <check.h>

#include "main.h"
#include "input.h"
#include "filter.h"
#include "sort.h"
#include "output.h"

#define FAIL -10

Suite* check_elem_num(void);
Suite* check_fill_arr(void);
Suite* check_filter(void);
Suite* check_mysort(void);
Suite* check_output(void);

#endif