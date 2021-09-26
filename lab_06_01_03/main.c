#include "main.h"
#include "read_from_file.h"
#include "choose_products.h"
#include "print_chosen_products.h"

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);

    int error_code = OK;

    int n = 0, new_n = 0;
    double p = 0;
    product init_arr[MAX_ARR_SIZE];
    product res_arr[MAX_ARR_SIZE];
    
    if (argc <= 2)
    {
        error_code = ERR_ARG;
    }
    else
    {
        p = atof(argv[2]);
        if (p <= 0)
            error_code = ERR_ARG;
    }

    if (error_code == OK)
    {
        error_code = read_file(argv[1], init_arr, &n);

        if (error_code == OK)
        {
            new_n = choose_products(init_arr, res_arr, n, p);
            print_products(res_arr, new_n);
        }
    }
    
    return error_code;
}
