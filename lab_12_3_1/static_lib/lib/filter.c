#include "filter.h"

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    int err_code = OK;

    int num_dst = 0;
    const int *last_neg = pe_src;

    if (pb_src == NULL || pe_src == NULL || pe_src - pb_src <= 0)
        err_code = ERR_NO_DATA;

    if (err_code == OK)
    {
        find_last_neg(pb_src, pe_src, &last_neg);
        num_dst = last_neg - pb_src;
        
        if (num_dst == 0)
            err_code = ERR_NO_RES_DATA;
        else
        {
            *pb_dst = calloc(num_dst, sizeof(int));

            if (!*pb_dst)
                err_code = ERR_MEMORY;
            else
            {
                copy_to_last_neg(pb_src, last_neg, *pb_dst);
                *pe_dst = *pb_dst + num_dst;
            }
        }
    }

    return err_code;
}

void find_last_neg(const int *pb_src, const int *pe_src, const int **last_neg)
{
    const int *p_src = pb_src;

    while (p_src < pe_src)
    {
        if (*p_src < 0)
            *last_neg = p_src;
        p_src++;
    }
}

void copy_to_last_neg(const int *pb_src, const int *last_neg, int *arr)
{
    const int *p_src = pb_src;

    while (p_src < last_neg)
        *arr++ = *p_src++;
}