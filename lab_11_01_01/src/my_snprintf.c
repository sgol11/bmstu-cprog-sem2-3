#include "my_snprintf.h"

int my_snprintf(char *restrict buf, size_t num, const char *restrict format, ...)
{
    if (num > 0) 
        num--;

    va_list argptr;
    va_start(argptr, format);
    
    size_t actual_len = 0;

    char ch;
    char *str;
    int dec;

    while (*format)
    {
        if (*format == '%')
        {
            format++;

            switch (*format)
            {
                case 'c':
                    ch = va_arg(argptr, int);
                    c_processing(buf, num, &format, ch, &actual_len);
                    break;
                case 'd':
                    dec = va_arg(argptr, int);
                    num_processing(buf, num, &format, dec, &actual_len, DEC_ALPHABET, DEC_FOUNDATION);
                    break;
                case 'x':
                    dec = va_arg(argptr, int);
                    num_processing(buf, num, &format, dec, &actual_len, HEX_ALPHABET, HEX_FOUNDATION);
                    break;
                case 's':
                    str = va_arg(argptr, char *);
                    s_processing(buf, num, &format, str, &actual_len);
                    break;
                default:
                    break;
            }
        }
        else
        {
            if (actual_len < num)
                buf[actual_len] = *format;

            actual_len++;
            format++;
        }
    }

    va_end(argptr);

    if (buf && actual_len < num)
        buf[actual_len] = '\0';
    else if (buf)
        buf[num] = '\0';

    return actual_len;
}

void c_processing(char *restrict buf, size_t num, const char *restrict *format, char ch, size_t *actual_len)
{
    if (buf && *actual_len < num)
        buf[*actual_len] = ch;

    (*actual_len)++;

    (*format)++;
}

void num_processing(char *restrict buf, size_t num, const char *restrict *format, int decimal, size_t *actual_len,
char *alphabet, int foundation)
{
    int length = number_length(decimal, foundation);

    char *str_num = NULL;
    str_num = malloc((length + 1) * sizeof(char));

    num_to_str(decimal, str_num, alphabet, foundation);

    for (int i = 0; i < length; i++)
    {
        if (buf && *actual_len < num)
            buf[*actual_len] = str_num[i];

        (*actual_len)++;
    }
                
    (*format)++;

    free(str_num);
}

void s_processing(char *restrict buf, size_t num, const char *restrict *format, char *str, size_t *actual_len)
{
    if (str == NULL)
    {
        for (int i = 0; i < NULL_STR_LEN; i++)
        {
            if (buf && *actual_len < num)
                buf[(*actual_len)] = NULL_STR[i];

            (*actual_len)++;
        }
    }
    else
    {
        while (*str != '\0')
        {
            if (buf && *actual_len < num)
                buf[*actual_len] = *str;

            str++;
            (*actual_len)++;
        }
    }

    (*format)++;
}