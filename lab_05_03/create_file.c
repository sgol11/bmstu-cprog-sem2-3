#include "create_file.h"

int create_file(char *file_name, int n)
{
    int code = OK;

    FILE *file = fopen(file_name, "wb");

    for (int i = 0; i < n; i++)
    {
        int num = rand() % 100 - 100;
        fwrite(&num, sizeof(int), 1, file);
    }

    fclose(file);

    if (n == 0)
        code = NO_NUMBERS;

    return code;
}