#include "memory_work.h"

void free_movie_list(node_t **head)
{
    node_t *next_node;

    while (*head)
    {
        next_node = (*head)->next;
        free_movie_node(head);
        *head = next_node;
    }
}

void free_movie_node(node_t **node)
{
    movie_t *movie = (*node)->data;
    free(movie->name);
    movie->name = NULL;
    free(movie);
    movie = NULL;
    free(*node);
    *node = NULL;
}

void free_int_list(node_t **head)
{
    node_t *next_node;

    while (*head)
    {
        next_node = (*head)->next;
        free_int_node(head);
        *head = next_node;
    }
}

void free_int_node(node_t **node)
{
    int *num = (*node)->data;
    free(num);
    num = NULL;
    free(*node);
    *node = NULL;
}