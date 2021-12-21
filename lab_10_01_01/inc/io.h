#ifndef __IO_H__
#define __IO_H__

#include "main.h"
#include "errors.h"
#include "structs.h"
#include "my_functions.h"

int read_file(char *file_name, node_t **head);
int read_structs(FILE *f, node_t **head);
int read_movie_info(FILE *f, char **tmp_name, int *tmp_price);
node_t *create_node(char *name, int year);
int write_list_into_file(char *file_name, node_t *head);

#endif