// Найти n!

#include "Header.h"
#include "Functionlist8.8.c"

int main()
{
    char x;                 // Для повтора
    int Length;             // Кол-во наиболее часто встречающихся слов
    do
    {
        Length = StringLength();                                // Ввод длинны строки
        Calculations(Length);
        printf("Do you want to repeat program? y/n\n");			// Повтор программы y/n
        rewind(stdin);											// Чистка буфера
        scanf_s("%c", &x);
    } while (x == 'y');
    return 0;
}