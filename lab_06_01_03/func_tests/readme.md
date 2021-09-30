# Тесты для лабораторной работы №06

## Входные данные
Аргументы командной строки:
- массив символов file_name - имя текстового файла;
- вещественное p - цена, с которой сравниваются цены продуктов в файле.

Содержимое текстового файла:
- целочисленное n - количество продуктов (в первой строке файла);
- массив символов name и целочисленное price - название и цена каждого продукта,
  объединенные в структуру product.

## Выходные данные
Массив символов name и целочисленное price - название и цена каждого продукта,
который стоит меньше, чем p.

## Позитивные тесты:
- 01 - нет продуктов с ценой ниже p;
- 02 - все продукты имеют цену ниже p;
- 03 - некоторые из продуктов имеют цену ниже p;
- 04 - p - целое;
- 05 - p - вещественное;
- 06 - p задается в экспоненциальной форме;
- 07 - в файле 15 продуктов.

## Негативные тесты:
- 01 - аргументов командной строки меньше, чем требуется;
- 02 - p не число (например, буква);
- 03 - p <= 0;
- 04 - файл не существует;
- 05 - в первой строке файла не число (например, буква);
- 06 - в первой строке файла отрицательное число;
- 07 - в первой строке файла число больше 15 (максимальный размер массива структур);
- 08 - длина какого-либо названия продукта превышает 25 символов;
- 09 - вместо цены какого-либо продукта не число (например, буква);
- 10 - цена какого-либо продукта <= 0.