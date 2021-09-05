/**
Назначение программы: нахождение произведения
цифр трехзначного числа
 */

#include <stdio.h>

int digits_multiply(int num);

int main(void)
{
    setbuf(stdout, NULL);
    int number;

    printf("Input number: ");
    scanf("%d", &number);

    int multiply = digits_multiply(number);

    printf("Multiply of digits = %d", multiply);

    return 0;
}

int digits_multiply(int num)
{
    if (num < 0)
        num *= -1;
    
    int a, b, c;
    a = num / 100;
    b = num / 10 % 10;
    c = num % 10;
    
    return a * b * c;
}
