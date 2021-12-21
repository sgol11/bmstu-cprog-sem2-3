#include "main.h"
#include "errors.h"
#include "read_from_file.h"
#include "choose_products.h"
#include "print_chosen_products.h"
#include "memory_management.h"

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);

    int error_code = OK;
    
    product_t *init_arr = NULL;
    product_t *res_arr = NULL;

    int n = 0, new_n = 0;
    double p = 0;
    
    if (argc <= 2)
        error_code = ERR_ARG;
    else if ((p = atof(argv[2])) <= 0)
        error_code = ERR_ARG;

    if (error_code == OK)
    {
        error_code = read_file(argv[1], &n, &init_arr);
        
        if (error_code == OK)
        {
            new_n = choose_products(init_arr, &res_arr, n, p);

            if (new_n != ERR_MEMORY)
            {
                print_products(res_arr, new_n);
                free_structs_arr(&res_arr, new_n);
            }
            else
                error_code = new_n;
        }
        
        free_structs_arr(&init_arr, n);
    }

    // printf("%d\n", error_code);

    return error_code;
}
