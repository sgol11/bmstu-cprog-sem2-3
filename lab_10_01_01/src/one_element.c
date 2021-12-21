#include "one_element.h"

node_t *find(node_t *head, const void *data, int (*comparator)(const void *, const void *))
{
    node_t *cur_node = head;
    const int *search_info = data;
    int exit = 0;

    while (!exit && cur_node)
    {
        if (comparator(cur_node->data, search_info) == 0)
            exit = 1;
        
        if (!exit)
            cur_node = cur_node->next;
    }

    return cur_node;
}

void *pop_front(node_t **head)
{
    if (head == NULL || *head == NULL)
        return NULL;

    node_t *old_head = *head;
    void *old_head_data = old_head->data;
    *head = (*head)->next;

    free(old_head);
    
    return old_head_data;
}

void *pop_back(node_t **head)
{
    if (head == NULL || *head == NULL)
        return NULL;
    
    node_t *cur_node = *head;
    void *old_head_data = NULL;

    if (cur_node->next == NULL)
    {
        old_head_data = cur_node->data;

        free(cur_node);
        *head = NULL;
    }
    else
    {   
        while (cur_node->next->next)
            cur_node = cur_node->next;

        old_head_data = cur_node->next->data;
        
        free(cur_node->next);
        cur_node->next = NULL;
    }

    return old_head_data;
}

void insert(node_t **head, node_t *elem, node_t *before) 
{
    node_t *cur_node = *head;
    
    if ((*head == NULL && before == NULL) || *head == before)
    {
        elem->next = before;
        *head = elem;
    }
    
    int exit = 0;
    while (cur_node && !exit)
    {
        if (cur_node->next == before)
        {
            elem->next = before;
            cur_node->next = elem;
            exit = 1;
        }
        cur_node = cur_node->next;
    }
}   

int comparator_int(const void *first_element, const void *second_element)
{
    const int *a = first_element;
    const int *b = second_element;

    return *a - *b;
}

int comparator_movie(const void *first_element, const void *second_element)
{
    int res = 0;
    
    movie_t *first_movie = (movie_t*)first_element;
    movie_t *second_movie = (movie_t*)second_element;

    if (strcmp(first_movie->name, second_movie->name) > 0)
        res = 1;
    else if (strcmp(first_movie->name, second_movie->name) < 0)
        res = -1;

    if (res == 0 && first_movie->year > second_movie->year)
        res = 1;
    else if (res == 0 && first_movie->year < second_movie->year)
        res = -1;

    return res;
}