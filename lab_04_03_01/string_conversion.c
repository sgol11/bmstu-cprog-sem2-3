#include "string_conversion.h"

int fill_new_str(words_array *words, char *new_str)
{
    int code = OK;
    size_t last_idx = words->num_of_words - 1;
    int count = 0;

    for (int i = last_idx; i >= 0; i--)
    {
        if (strcmp(words->str_words[i], words->str_words[last_idx]))
        {
            change_word(words->str_words[i]);
            if (count)
                strcat(new_str, " ");
            strcat(new_str, words->str_words[i]);
            count++;
        }
    }

    if (!count)
        code = EMPTY_RES_STR;

    return code;
}

void change_word(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        for (int j = i + 1; str[j]; j++)
        {
            if (str[i] == str[j])
            {
                delete(str, j);
                j--;
            }
        }
    }
}

void delete(char *str, int idx)
{
    for (int i = idx; str[i]; i++)
        str[i] = str[i + 1];
}