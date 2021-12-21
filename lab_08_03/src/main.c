#include "main.h"
#include "io.h"
#include "memory_work.h"
#include "delete.h"
#include "add.h"
#include "multi.h"

int main()
{
    setbuf(stdout, NULL);

    int error_code = OK, able_to_free_first = 0, 
    able_to_free_second = 0, able_to_free_res = 0;

    matrix_t first_matrix, second_matrix, res_matrix;
    int p, q;

    // INPUT
    
    error_code = input_matrix(&first_matrix);

    if (error_code != ERR_SIZE)
        able_to_free_first = 1;

    if (error_code == OK)
    {
        error_code = input_matrix(&second_matrix);

        if (error_code != ERR_SIZE)
            able_to_free_second = 1;
    }
    
    // DELETE

    if (error_code == OK)
        error_code = square_matrix_by_removing(&first_matrix);

    if (error_code == OK)
        error_code = square_matrix_by_removing(&second_matrix);

    // ADD

    if (error_code == OK)
        error_code = one_size_by_adding(&first_matrix, &second_matrix);

    if (error_code == OK)
        error_code = input_powers(&p, &q);

    // MULTIPLY

    if (error_code == OK)
    {
        error_code = calculate(&first_matrix, p, &second_matrix, q, &res_matrix);
        able_to_free_res = 1;

        if (error_code == OK)
            print_matrix(&res_matrix);
    }

    if (able_to_free_first)
        free_matrix(first_matrix.data, first_matrix.rows);
    if (able_to_free_second)
        free_matrix(second_matrix.data, second_matrix.rows);
    if (able_to_free_res)
        free_matrix(res_matrix.data, res_matrix.rows);
    
    return error_code;
}