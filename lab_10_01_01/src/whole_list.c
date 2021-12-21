#include "whole_list.h"

void remove_duplicates(node_t **head, int (*comparator)(const void*, const void*))
{
    node_t *cur_node = *head;
    node_t *next_node = NULL;

    while (cur_node)
    {
        next_node = cur_node->next;

        if (next_node && comparator(cur_node->data, next_node->data) == 0)
        {
            cur_node->next = next_node->next;
            free(next_node);
        }
        else
            cur_node = cur_node->next;
    }
}