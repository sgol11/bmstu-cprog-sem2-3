#include <stdio.h>
#include <string.h>

#define MAX_NUM_OF_WORDS 128
#define MAX_STLEN 256
#define MAX_WLEN 16

#define SEP "\n ,;:-.!?"

#define OK 0
#define BUFFER_OVERFLOW 1
#define LONG_WORD 2
#define NO_UNIQUE_WORDS 3
#define EMPTY_STR 4

typedef struct
{
    char *str_words[MAX_NUM_OF_WORDS];
    size_t num_of_words;
} words_array;

int read_line(char *str, int n);
void split_into_words(char *str, words_array *words, int word_len, int *ret_code);
char *my_strtok(char *str, const char *separators);
void unique_words(words_array *words_1, words_array *words_2, int *ret_code);
int count_duplicates(char *word1, words_array *words_of_line);
void print_error(int code);