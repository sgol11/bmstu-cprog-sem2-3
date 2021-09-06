#include "process.h"

int process(FILE *f, int *result)
{
    int num, prev, count = 0;
    int correct_num = 1;
    int code = OK;

    while (!feof(f) && !ferror(f) && correct_num)
    {
        if (fscanf(f, "%d", &num) == 1)
        {
            if (count)
            {
                if (num * prev < 0 || (prev < 0 && num == 0) || (prev == 0 && num < 0))
                    *result += 1;
            }
            prev = num;
            count++;
        }
        else
            correct_num = 0;
    }

    if (count == 0)
        code = NO_NUMBERS;
    else if (count == 1)
        code = ONE_ELEMENT;

    return code;
}