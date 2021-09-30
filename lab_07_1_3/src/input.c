#include "../inc/input.h"

int number_of_elements(char *file_name)
{
    int num = 0, x = 0;
    FILE *file = fopen(file_name, "r");

    if (!file)
        num = ERR_NO_FILE;
    else
    {
        while (!feof(file) && !ferror(file) && fscanf(file, "%d", &x) == 1)
            num++;

        if (num == 0)
            num = ERR_NO_DATA;
        
        fclose(file);
    }

    return num;
}

int fill_array(char *file_name, int *arr, int num)
{
    int err_code = OK;

    FILE *file = fopen(file_name, "r");

    if (!file)
        err_code = ERR_NO_FILE;
    else
    {
        for (int i = 0; i < num; i++)
        {
            if (feof(file) || ferror(file) || fscanf(file, "%d", arr + i) != 1)
                err_code = ERR_INPUT;
        }
        fclose(file);
    }

    return err_code;
}

void free_init_arr(int **arr)
{
    free(*arr);
    *arr = NULL;
}