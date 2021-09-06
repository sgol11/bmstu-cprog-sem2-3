/* Определить, сколько раз в последовательности целых чисел 
 * меняется знак (0 считается положительным числом).
 *
 * Ввод до первого некорректного значения
 */

#include "main.h"

int main(void)
{
    int error_code = OK;
    int result = 0;

    error_code = process(stdin, &result);
    if (error_code == OK)
        fprintf(stdout, "%d\n", result);

    print_error(error_code);
    return error_code;
}

void print_error(int code)
{
    switch (code)
    {
        case NO_NUMBERS:
            printf("Error: no correct numbers in sequence\n");
            break;
        case ONE_ELEMENT:
            printf("Error: one element in sequence\n");
            break;
        default:
            break;
    }
}
