#include "number_operations.h"

int number_length(int num, int foundation)
{
    int len = 0;
    unsigned int positive = num;

    if (num < 0)
    {
        if (foundation == DEC_FOUNDATION)
        {
            positive *= -1;
            len++;
        }
        else
            positive += UINT_MAX + 1;
    }
    else if (num == 0)
        len++;

    while (positive > 0)
    {
        positive /= foundation;
        len++;
    }

    return len;
}

void num_to_str(int decimal, char *str, char *alphabet, int foundation)
{
    int len = 0, first_reverse_idx = 0;
    unsigned int positive = decimal;

    if (decimal == 0)
        str[len++] = '0';
    else
    {
        if (decimal < 0)
        {
            if (foundation == DEC_FOUNDATION)
            {
                str[len++] = '-';
                first_reverse_idx = 1;
                positive *= -1;
            }
            else
                positive += UINT_MAX + 1;
        }
        
        while (positive > 0)
        {
            str[len++] = alphabet[positive % foundation];
            positive /= foundation;
        }
        
        reverse(str, first_reverse_idx, len);
    }

    str[len] = '\0';
}

void reverse(char *str, int first_idx, int len)
{
    int upper_bound = (first_idx == 0) ? len / 2 : len / 2 + 1;

    for (int i = first_idx; i < upper_bound; i++)
    {
        swap(str, i, len - i - 1 + first_idx);
    }
}

void swap(char *str, int idx1, int idx2)
{
    char tmp = str[idx1];
    str[idx1] = str[idx2];
    str[idx2] = tmp;    
}