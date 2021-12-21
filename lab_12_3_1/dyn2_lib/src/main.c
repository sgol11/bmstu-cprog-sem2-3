#include "main.h"

#include "input.h"
#include "output.h"
#include "filter.h"
#include "sort.h"

typedef int(__cdecl *fn_number_of_elements_from_file_t)(char *);
typedef int(__cdecl *fn_fill_array_from_file_t)(char *, int *, int);
typedef int(__cdecl *fn_write_into_file_t)(char *, int *, int *);
typedef int(__cdecl *fn_key_t)(int *, int *, int **, int **);
typedef int(__cdecl *fn_mysort_t)(void *, size_t, size_t, int (*comparator)(const void *, const void *));

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);

    HMODULE hlib;
    fn_number_of_elements_from_file_t number_of_elements_from_file;
    fn_fill_array_from_file_t fill_array_from_file;
    fn_write_into_file_t write_into_file;
    fn_key_t key;
    fn_mysort_t mysort;

    int error_code = OK;

    hlib = LoadLibrary("dyn2.dll");
    if (!hlib)
        error_code = ERR_LIBRARY;

    int n = 0;
    int *init_arr = NULL;
    int *pb_res_arr = NULL, *pe_res_arr = NULL;
    int filter = 0;

    if (error_code == OK)
    {
        if (argc == 3)
            filter = 0;
        else if (argc == 4 && strcmp(argv[3], "f") == 0)
            filter = 1;
        else
            error_code = ERR_ARG;
    }

    if (error_code == OK)
    {
        number_of_elements_from_file = (fn_number_of_elements_from_file_t)
        GetProcAddress(hlib, "number_of_elements_from_file");

        if (!number_of_elements_from_file)
            error_code = ERR_LIBRARY;
        else
        {
            n = number_of_elements_from_file(argv[1]);
            if (n < 0)
                error_code = n;
        }
    }

    if (error_code == OK)
    {
        init_arr = calloc(n, sizeof(int));

        if (!init_arr)
            error_code = ERR_MEMORY;
        else
        {
            fill_array_from_file = (fn_fill_array_from_file_t)GetProcAddress(hlib, "fill_array_from_file");

            if (!fill_array_from_file)
                error_code = ERR_LIBRARY;
            else
                error_code = fill_array_from_file(argv[1], init_arr, n);
        }

        if (error_code == OK && filter)
        {
            key = (fn_key_t)GetProcAddress(hlib, "key");

            if (!key)
                error_code = ERR_LIBRARY;
            else
            {
                error_code = key(init_arr, init_arr + n, &pb_res_arr, &pe_res_arr);

                if (error_code == OK)
                {
                    mysort = (fn_mysort_t)GetProcAddress(hlib, "mysort");

                    if (!mysort)
                        error_code = ERR_LIBRARY;
                    else
                    {
                        error_code = mysort(pb_res_arr, pe_res_arr - pb_res_arr, sizeof(int), compare_int);

                        write_into_file = (fn_write_into_file_t)GetProcAddress(hlib, "write_into_file");

                        if (!write_into_file)
                            error_code = ERR_LIBRARY;
                        else
                            write_into_file(argv[2], pb_res_arr, pe_res_arr);
                    }
                }
            }
        }
        else if (error_code == OK)
        {
            mysort = (fn_mysort_t)GetProcAddress(hlib, "mysort");

            if (!mysort)
                error_code = ERR_LIBRARY;
            else
            {
                error_code = mysort(init_arr, n, sizeof(int), compare_int);

                write_into_file = (fn_write_into_file_t)GetProcAddress(hlib, "write_into_file");

                if (!write_into_file)
                    error_code = ERR_LIBRARY;
                else
                    write_into_file(argv[2], init_arr, init_arr + n);
            }
        }
    }

    free(init_arr);
    free(pb_res_arr);
    FreeLibrary(hlib);

    return error_code;
}