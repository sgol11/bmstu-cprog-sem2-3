#ifndef __MAIN__H__
#define __MAIN__H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 0
#define ERR_MEMORY -1
#define ERR_SIZE -2
#define ERR_ELEMENT -3
#define ERR_POW -4

typedef struct 
{
    int rows;
    int columns;
    int **data;
} matrix_t;

#endif