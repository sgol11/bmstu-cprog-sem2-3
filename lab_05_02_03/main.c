/* Проверить, выполняется ли правило трех сигм для вещественных
 * чисел из файла.
 *
 * Правило трех сигм:
 * вероятность того, что случайная величина отклонится от своего 
 * математического ожидания более чем на три среднеквадратических 
 * отклонения, практически равна нулю
 */

#include "main.h"

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);

    int error_code = OK;
    int result = 1;

    FILE *file = fopen(argv[1], "r");

    if (!file)
        error_code = ERR_NO_FILE;
    else
    {
        fseek(file, 0, SEEK_END);
        if (ftell(file) == 0)
            error_code = ERR_NO_DATA;
        rewind(file);
    }

    if (error_code == OK)
    {
        error_code = three_sigma_rule(file, &result);

        if (error_code == OK)
            printf("%d\n", result);
    }
    
    if (error_code != ERR_NO_FILE)
        fclose(file);

    return error_code;
}
