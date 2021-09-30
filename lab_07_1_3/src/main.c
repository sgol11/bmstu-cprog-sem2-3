#include "../inc/main.h"
#include "../inc/input.h"
#include "../inc/filter.h"
#include "../inc/sort.h"
#include "../inc/output.h"

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);

    int error_code = OK;

    int n = 0;
    int *init_arr = NULL;
    int *pb_res_arr = NULL, *pe_res_arr = NULL;
    int filter = 0;
    
    if (argc == 3)
        filter = 0;
    else if (argc == 4 && strcmp(argv[3], "f") == 0)
        filter = 1;
    else
        error_code = ERR_ARG;

    if (error_code == OK)
    {
        n = number_of_elements(argv[1]);
        if (n < 0)
            error_code = n;
    }

    if (error_code == OK)
    {
        init_arr = calloc(n, sizeof(int));

        if (!init_arr)
            error_code = ERR_MEMORY;
        else
            error_code = fill_array(argv[1], init_arr, n);
    }

    if (error_code == OK && filter)
    {
        error_code = key(init_arr, init_arr + n, &pb_res_arr, &pe_res_arr);
        if (error_code == OK)
        {
            error_code = mysort(pb_res_arr, pe_res_arr - pb_res_arr, sizeof(int), compare_int);
            write_into_file(argv[2], pb_res_arr, pe_res_arr);
        }   
    }
    else if (error_code == OK)
    {
        error_code = mysort(init_arr, n, sizeof(int), compare_int);
        write_into_file(argv[2], init_arr, init_arr + n); 
    }

    free_init_arr(&init_arr);
    free_new_arr(&pb_res_arr, &pe_res_arr);
    
    return error_code;
}
