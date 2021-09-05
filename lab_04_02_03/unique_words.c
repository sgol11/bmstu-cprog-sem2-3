#include "unique_words.h"

void unique_words(words_array *words_1, words_array *words_2, int *ret_code)
{
    size_t sum_size = words_1->num_of_words + words_2->num_of_words;
    int count = 0, number = 0, idx = 0;
    char *first_word;

    for (int i = 0; i < sum_size; i++)
    {
        count = 0;
        idx = (i < words_1->num_of_words) ? i : i - words_1->num_of_words;
        first_word = (i < words_1->num_of_words) ? words_1->str_words[idx] : words_2->str_words[idx];

        count += count_duplicates(first_word, words_1);
        count += count_duplicates(first_word, words_2);
        
        if (count == 1)
        {
            if (!number)
                printf("Result: ");
            printf("%s ", first_word);
            number++;
        }
    }

    if (number == 0)
        *ret_code = NO_UNIQUE_WORDS;
}

int count_duplicates(char *word1, words_array *words_of_line)
{
    int count = 0;
    for (int i = 0; i < words_of_line->num_of_words; i++)
    {
        if (!strcmp(word1, words_of_line->str_words[i]))
            count++;
    }
    return count;
}