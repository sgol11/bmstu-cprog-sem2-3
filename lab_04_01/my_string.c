#include "my_string.h"

// первое вхождение в строку символа из указанного множества
const char *my_strpbrk(const char *str, const char *sym)
{
    const char *res = NULL;
    int flag = 1;

    for (int i = 0; str[i] && flag; i++)
    {
        for (int j = 0; sym[j] && flag; j++)
        {
            if (str[i] == sym[j])
            {
                res = (char*)str + i;
                flag = 0;
            }
        }
    }

    return res;
}

// максимальная длина начального участка строки, содержащего только указанные символы
size_t my_strspn(const char *str, const char *sym)
{
    size_t len = 0, flag = 1;

    for (int i = 0; str[i] && flag; i++)
    {
        flag = 0;
        for (int j = 0; sym[j] && !flag; j++)
        {
            if (str[i] == sym[j])
            {
                len++;
                flag = 1;
            }
        }
    }

    return len;
}

// максимальная длина начального участка строки, не содержащего указанные символы
size_t my_strcspn(const char *str, const char *sym)
{
    size_t len = 0, flag = 1;

    for (int i = 0; str[i] && flag; i++)
    {
        for (int j = 0; sym[j] && flag; j++)
        {
            if (str[i] == sym[j])
                flag = 0;
        }
        if (flag)
            len++;
    }

    return len;
}

// первое вхождение символа в строку
const char *my_strchr(const char *str, int ch)
{
    while (*str && *str != ch)
        str++;

    return (*str || ch == '\0') ? str : NULL;
}

// последнее вхождение символа в строку
const char *my_strrchr(const char *str, int ch)
{
    const char *cur_sym = my_strchr(str, ch);
    const char *prev_sym = cur_sym;

    while (cur_sym != NULL && ch != '\0')
    {
        prev_sym = cur_sym;
        cur_sym = my_strchr(prev_sym + 1, ch);
    }

    return prev_sym;
}