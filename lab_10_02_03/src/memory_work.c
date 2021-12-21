#include "memory_work.h"

node_t *create_node(int data)
{
    node_t *node = NULL;

    node = malloc(sizeof(node_t));

    if (node)
    {
        node->data = data;
        node->next = NULL;
    }

    return node;
}

void free_list(node_t **head)
{
    node_t *next_node;

    while (*head)
    {
        next_node = (*head)->next;
        free(*head);
        *head = next_node;
    }
}

void push(node_t *element, node_t **head)
{
    if (*head == NULL)
        *head = element;
    else
    {
        node_t *cur_node = *head;

        while (cur_node->next)
            cur_node = cur_node->next;
            
        cur_node->next = element;
    }
}