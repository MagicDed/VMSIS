// В тексте найти N наиболее часто встречающихся слов

#include "Header.h"
#include "Functionlist7.2.c"

int main()
{
    char x;                 // Для повтора
    char *Line;             // Строчка ввода
    int Length;             // Кол-во наиболее часто встречающихся слов
    do
    {
        Line = PointerMemoryAllocation();                       // Ячейка памяти под указатель
        InputWithDynamicMemoryAllocation(Line);                 // Ввод текста с динамическим выделением памяти
        Calculations(Line);                                     // Вычисления
        printf("Do you want to repeat program? y/n\n");			// Повтор программы y/n
        rewind(stdin);											// Чистка буфера
        scanf_s("%c", &x);
    } while (x == 'y');
    return 0;
}