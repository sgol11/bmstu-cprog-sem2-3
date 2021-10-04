#include "../inc/output.h"

int write_into_file(char *file_name, int *pb, int *pe)
{
    int err_code = OK;

    FILE *file = fopen(file_name, "w");

    print_array(file, pb, pe);
    fclose(file);
    
    return err_code;
}

void print_array(FILE *file, int *pb, int *pe)
{
    int *p = pb;

    while (p < pe)
    {
        fprintf(file, "%d ", *p);
        p++;
    }
}

void free_arr(int **pb, int **pe)
{
    free(*pb);
    *pb = NULL;
    *pe = NULL;
}