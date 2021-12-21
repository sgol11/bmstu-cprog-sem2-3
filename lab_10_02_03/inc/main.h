#ifndef __MAIN_H__
#define __MAIN_H__

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node node_t;

struct node
{
    int data;
    node_t *next;
};

#endif