/*
 * 1 вариант (студенты), бинарный файл
 *
 * Вызов по ключу:
 * a) sb - сортировка в алфавитном порядке по фамилии
 *         (если одинаковые фамилии, то по имени);
 * b) fb - вывод информации о студентах, фамилии которых 
 *         начинаются с заданной подстроки, в другой файл;
 * c) db - удаление из файла студентов, чей средний балл
 *         меньше среднего балла по всему файлу.
 */

#include "main.h"

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);

    int error_code = OK;
    
    if (argc <= 1)
    {
        error_code = ERR_ARG;
    }
    else if (strcmp(argv[1], "sb") == 0 && argc == 3)
    {
        error_code = sort_students(argv[2]);
        if (error_code == OK)
            print_students(argv[2]);
    }
    else if (strcmp(argv[1], "fb") == 0 && argc == 5)
    {
        error_code = students_with_substr(argv[2], argv[3], argv[4]);
    }
    else if (strcmp(argv[1], "db") == 0 && argc == 3)
    {
        error_code = delete_students(argv[2]);
    }
    else
        error_code = ERR_ARG;
    
    return error_code;
}
