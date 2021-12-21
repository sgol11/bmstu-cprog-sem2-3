#include "sort_list.h"

node_t *sort(node_t *head, int (*comparator)(const void *, const void *))
{
    if (!comparator)
        return NULL;
    
    node_t *new_head = NULL;

    if (head == NULL || head->next == NULL)
        new_head = head;
    else
    {
        node_t *first_half = NULL;
        node_t *second_half = NULL;
        node_t *back = NULL;

        front_back_split(head, &back);

        first_half = sort(head, comparator);
        second_half = sort(back, comparator);

        new_head = sorted_merge(&first_half, &second_half, comparator);
    }

    return new_head;
}

void front_back_split(node_t *head, node_t **back)
{
    if (head && back)
    {
        node_t *half_back = head;

        while (head->next && head->next->next)
        {
            half_back = half_back->next;
            head = head->next->next;
        }

        *back = half_back->next;
        half_back->next = NULL;
    }
}

node_t *sorted_merge(node_t **head_a, node_t **head_b, int (*comparator)(const void *, const void *))
{
    if (head_a == NULL || head_b == NULL || comparator == NULL)
        return NULL;
        
    node_t *first_list = *head_a;
    node_t *second_list = *head_b;
    
    node_t *res_head = NULL;
    node_t *res_list = NULL;
    
    if (first_list || second_list)
    {
        if (first_list && (!second_list || comparator(first_list->data, second_list->data) < 0))
            create_res_list(&res_list, &res_head, &first_list);
        else
            create_res_list(&res_list, &res_head, &second_list);
    }

    while (first_list && second_list)
    {
        if (comparator(first_list->data, second_list->data) < 0)
            move_elem_to_res_list(&res_list, &first_list);
        else
            move_elem_to_res_list(&res_list, &second_list);
    }

    while (first_list)
        move_elem_to_res_list(&res_list, &first_list);

    while (second_list)
        move_elem_to_res_list(&res_list, &second_list);

    res_list = NULL;
    
    *head_a = NULL;
    *head_b = NULL;

    return res_head;
}

void create_res_list(node_t **res_list, node_t **res_head, node_t **src_list)
{
    *res_head = *src_list;
    *res_list = *res_head;
    *src_list = (*src_list)->next;
}

void move_elem_to_res_list(node_t **res_list, node_t **src_list)
{
    (*res_list)->next = *src_list;
    *res_list = (*res_list)->next;
    *src_list = (*src_list)->next;
}