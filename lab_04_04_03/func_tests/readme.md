# Тесты для лабораторной работы №04

## Входные данные
Строка

## Выходные данные
YES или NO

## Позитивные тесты:
- 01 - в строке только номер (YES)
- 02 - пробелы в начале и конце (YES)
- 03 - символы табуляции в начале и конце (YES)
- 04 - длинный код страны (YES)
- 05 - нет кода страны: формат (DDD)-DDD-DD-DD (YES)
- 06 - непробельные символы сразу перед номером (NO)
- 07 - непробельные символы сразу после номера (NO)
- 08 - нет "+": формат X(DDD)-DDD-DD-DD (NO)
- 09 - нет круглых скобок: формат +XDDD-DDD-DD-DD (NO)
- 10 - нет тире после круглых скобок: формат +X(DDD)DDD-DD-DD (NO)
- 11 - незавершенный номер: формат +X(DDD)-DDD-DD (NO)
- 12 - в коде оператора не 3 цифры: формат +X(DDDD)-DDD-DD-DD (NO)
- 13 - в одной из частей после круглых скобок неверное количество цифр: формат +X(DDD)-DD-DD-DD (NO)
- 14 - в непустой строке нет номера (NO)
- 15 - пустая строка (NO)

## Негативные тесты:
- 01 - переполнение буфера