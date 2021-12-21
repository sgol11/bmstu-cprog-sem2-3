#include "factoring_operations.h"

int polynomial_factoring(int num, node_t **head)
{
    int rc = OK;
    
    int divider = 2;

    while (num > 1) 
    {
        int pow = 0;

        while (num % divider == 0) 
        {
            pow++;
            num /= divider;
        }

        if (is_prime(divider))
        {
            node_t *new_node = create_node(pow);
            
            if (new_node)    
                push(new_node, head);
            else
                rc = ERR_MEMORY;
        }

        divider++;
    }

    if (num == 0)
        rc = ERR_ZERO_RES;
    
    return rc;
}

int is_prime(int num)
{
    int res = 1;

    if (num > 1)
    {
        for (int i = 2; i < num; i++)
            if (num % i == 0) 
                res = 0;
    }
    else 
        res = 0;

    return res;
}

int multiplication(node_t *head_1, node_t *head_2, node_t **res_head)
{
    int rc = OK;

    while (head_1 || head_2)
    {
        int data_1 = head_1 ? head_1->data : 0;
        int data_2 = head_2 ? head_2->data : 0;

        node_t *new_node = create_node(data_1 + data_2);

        if (new_node)    
            push(new_node, res_head);
        else
            rc = ERR_MEMORY;
        
        if (head_1)
            head_1 = head_1->next;
        if (head_2)
            head_2 = head_2->next;
    }

    return rc;
}

int squaring(node_t *head, node_t **res_head)
{
    int rc = OK;

    while (head)
    {
        node_t *new_node = create_node(head->data * 2);
            
        if (new_node)    
            push(new_node, res_head);
        else
            rc = ERR_MEMORY;
        
        head = head->next;
    }

    return rc;
}

int division(node_t *head_1, node_t *head_2, node_t **res_head)
{
    int rc = OK;

    node_t *simplified_fraction = NULL;

    while (head_1 || head_2)
    {
        int data_1 = head_1 ? head_1->data : 0;
        int data_2 = head_2 ? head_2->data : 0;

        node_t *new_node = create_node(data_1 - data_2);
            
        if (new_node)    
            push(new_node, &simplified_fraction);
        else
            rc = ERR_MEMORY;
        
        if (head_1)
            head_1 = head_1->next;
        if (head_2)
            head_2 = head_2->next;
    }

    int res = number_from_factoring(simplified_fraction);
    if (res == 0)
        rc = ERR_ZERO_RES;
    else
        polynomial_factoring(res, res_head);

    free_list(&simplified_fraction);

    return rc;
}

int number_from_factoring(node_t *head)
{
    int nominator = 1, denominator = 1, cur_prime_num = 2;
    
    while (head)
    {
        for (int i = 0; i < head->data; i++)
            nominator *= cur_prime_num;
        for (int i = head->data; i < 0; i++)
            denominator *= cur_prime_num;

        while (!is_prime(++cur_prime_num));

        head = head->next;
    }
    
    return nominator / denominator;
}