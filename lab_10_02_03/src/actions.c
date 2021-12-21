#include "actions.h"

int do_out(int num)
{
    int rc = OK;

    node_t *head = NULL;

    rc = polynomial_factoring(num, &head);
    if (rc == OK)
        print_polynomial_factoring(head);

    free_list(&head);

    return rc;
}

int do_mul(int num_1, int num_2)
{
    int rc = OK;

    node_t *head_1 = NULL, *head_2 = NULL, *head_res = NULL;

    rc = polynomial_factoring(num_1, &head_1);
    if (rc == OK) 
        rc = polynomial_factoring(num_2, &head_2);
        
    if (rc == OK)
        rc = multiplication(head_1, head_2, &head_res);
        
    if (rc == OK)
        print_polynomial_factoring(head_res);

    free_list(&head_1);
    free_list(&head_2);
    free_list(&head_res);

    return rc;
}

int do_sqr(int num)
{
    int rc = OK;

    node_t *head = NULL, *head_res = NULL;

    rc = polynomial_factoring(num, &head);

    if (rc == OK)
        rc = squaring(head, &head_res);

    if (rc == OK)
        print_polynomial_factoring(head_res);

    free_list(&head);
    free_list(&head_res);

    return rc;
}

int do_div(int num_1, int num_2)
{
    int rc = OK;

    node_t *head_1 = NULL, *head_2 = NULL, *head_res = NULL;

    rc = polynomial_factoring(num_1, &head_1);
    if (rc == OK) 
        rc = polynomial_factoring(num_2, &head_2);
        
    if (rc == OK)
        rc = division(head_1, head_2, &head_res);
        
    if (rc == OK)
        print_polynomial_factoring(head_res);

    free_list(&head_1);
    free_list(&head_2);
    free_list(&head_res);

    return rc;
}