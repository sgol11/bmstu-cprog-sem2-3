#include "../inc/sort.h"

int mysort(void *arr, size_t num, size_t size, int (*comparator)(const void *, const void *))
{
    int err_code = OK;
    int j = 0;

    if (arr == NULL || num <= 0)
        err_code = ERR_NO_DATA;

    if (err_code == OK)
    {
        void *moving_elem = NULL;
        void *cur_elem = NULL;
    
        for (size_t i = 1; i < num; i++)
        {
            j = i - 1;

            moving_elem = (char*)arr + i * size;
            cur_elem = (char*)arr + j * size;

            while (j >= 0 && comparator(cur_elem, moving_elem) > 0)
            {
                swap(cur_elem, moving_elem, size);
                j--;
            
                if (j >= 0)
                {
                    cur_elem = (char*)arr + j * size;
                    moving_elem = (char*)arr + (j + 1) * size;
                }
            }
        }
    }

    return err_code;
}

void swap(void *cur, void *next, int size)
{
    for (int i = 0; i < size; i++)
    {
        char tmp = *((char*)cur + i);
        *((char*)cur + i) = *((char*)next + i);
        *((char*)next + i) = tmp; 
    }
}

int compare_int(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}