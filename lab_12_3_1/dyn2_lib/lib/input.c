#include "input.h"

INPUT_DLL int INPUT_DECL number_of_elements_from_file(char *file_name)
{
    int num = 0, cur_elem = 0;

    FILE *file = fopen(file_name, "r");

    if (!file)
        num = ERR_NO_FILE;
    else
    {
        while (!feof(file) && !ferror(file) && fscanf(file, "%d", &cur_elem) == 1)
            num++;

        if (num == 0)
            num = ERR_NO_DATA;

        fclose(file);
    }

    return num;
}

INPUT_DLL int INPUT_DECL fill_array_from_file(char *file_name, int *arr, int num)
{
    int err_code = OK;

    FILE *file = fopen(file_name, "r");

    if (!file)
        err_code = ERR_NO_FILE;
    else
    {
        for (int i = 0; i < num && err_code == OK; i++)
        {
            if (feof(file) || ferror(file) || fscanf(file, "%d", arr + i) != 1)
                err_code = ERR_INPUT;
        }
        fclose(file);
    }

    return err_code;
}