#ifndef __STRUCTS_H__
#define __STRUCTS_H__

typedef struct node node_t;

struct node
{
    void *data;
    node_t *next;
};

typedef struct
{
    char *name;
    int year;
} movie_t;

#endif