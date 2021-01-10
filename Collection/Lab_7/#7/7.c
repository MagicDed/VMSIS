// Найти сумму чисел в предложении

#include "Header.h"
#include "Functionlist7.7.c"

int main()
{
    char x;                 // Для повтора
    char *Line;             // Строчка ввода
    int Length;             // Кол-во наиболее часто встречающихся слов
    do
    {
        Line = PointerMemoryAllocation();
        InputWithDynamicMemoryAllocation(Line);
        Length = StringLength(Line);
        Calculations(Line, Length);
        printf("Do you want to repeat program? y/n\n");			// Повтор программы y/n
        rewind(stdin);											// Чистка буфера
        scanf_s("%c", &x);
    } while (x == 'y');
    return 0;
}