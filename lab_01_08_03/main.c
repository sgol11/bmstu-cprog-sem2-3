/**
Назначение программы: обмен местами четных
и нечетных битов в беззнаковом целом числе
длиной 4 байта
 */

#include <stdio.h>

#define SIZE_IN_BITS 4 * 8

unsigned swap_bits(unsigned num);
void print(int code, unsigned num);
void print_result(unsigned num);

int main(void)
{
    setbuf(stdout, NULL);
    unsigned number;
    int pc, error_code = 0;

    printf("Input number: ");
    pc = scanf("%u", &number);
    if (pc != 1)
        error_code = 1;
    else
        number = swap_bits(number);

    print(error_code, number);

    return error_code;
}

unsigned swap_bits(unsigned num)
{
    unsigned m1 = 0x55555555; // 01010101... в 2-й СС
    unsigned m2 = 0xAAAAAAAA; // 10101010... в 2-й СС
    return ((num & m1) << 1) | ((num & m2) >> 1);
}

void print(int code, unsigned num)
{
    switch (code)
    {
        case 0:
            print_result(num);
            break;
        case 1:
            printf("Error: input error\n");
            break;
        default:
            break;
    }
}

void print_result(unsigned num)
{
    printf("Result: ");
    for (int i = SIZE_IN_BITS - 1; i >= 0; --i)
    {
        printf("%d", num & (1 << i) ? 1 : 0);
    }
    printf("\n");
}
