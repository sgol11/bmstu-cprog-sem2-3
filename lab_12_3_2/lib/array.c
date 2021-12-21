#include "array.h"

ARR_DLL void ARR_DECL fill_arr_with_prime_numbers(int *array, int size)
{
    int n = 2;

    for (int i = 0; i < size; i++)
    {
        while (!is_prime(n))
            n++;

        array[i] = n++;
    }
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

ARR_DLL int ARR_DECL arr_transfer(int *array_1, int *array_2, int size, int num)
{
    int j = 0;

    if (!array_2)
    {
        for (int i = 0; i < size; i++)
        {
            j++;
            if (array_1[i] % 2 == 0) 
                j++;
        }
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            array_2[j++] = array_1[i];

            if (array_1[i] % 2 == 0)
                array_2[j++] = num;
        }
    }

    return j;
}