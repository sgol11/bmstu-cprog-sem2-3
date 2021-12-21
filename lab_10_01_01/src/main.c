/*
Данные: информация о фильмах (название, год выхода)

Вызов программы: 
./app.exe <input_file> <output_file> <action> [additional_values]

Возможные действия:
p - извлечение первого элемента из списка
i - вставка элемента перед указанным элементом списка (после "i" передаются значения
    вставляемого элемента и элемента, перед которым он вставляется)
r - удаление дубликатов
s - сортировка слиянием
*/

#include "main.h"
#include "errors.h"
#include "memory_work.h"
#include "structs.h"
#include "io.h"
#include "one_element.h"
#include "whole_list.h"
#include "sort_list.h"

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);

    int error_code = OK;

    node_t *head = NULL;

    error_code = read_file(argv[1], &head);

    if (argc == 4 && error_code == OK && strcmp(argv[3], "p") == 0)
    {
        pop_front(&head);

        write_list_into_file(argv[2], head);
    }
    else if (argc == 8 && error_code == OK && strcmp(argv[3], "i") == 0)
    {
        movie_t before_movie;
        before_movie.name = argv[6];
        before_movie.year = atoi(argv[7]);
        
        node_t *element = create_node(argv[4], atoi(argv[5]));
        node_t *before = find(head, &before_movie, comparator_movie);
        
        insert(&head, element, before);
        
        write_list_into_file(argv[2], head);
    }
    else if (argc == 4 && error_code == OK && strcmp(argv[3], "r") == 0)
    {
        remove_duplicates(&head, comparator_movie);

        write_list_into_file(argv[2], head);
    }
    else if (argc == 4 && error_code == OK && strcmp(argv[3], "s") == 0)
    {
        node_t *sorted_head = sort(head, comparator_movie);

        write_list_into_file(argv[2], sorted_head);
    }
    else
        error_code = ERR_ARG;

    free_movie_list(&head);

    return error_code;
}
