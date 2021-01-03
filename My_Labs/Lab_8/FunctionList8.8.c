#include "Header.h"

int StringLength()                                              // Ввод длинны строки
{
    int Length;
    printf("How many common words do you need?: ");                     // Какая длинна строки?
    scanf_s("%d", &Length);                                             // Присваивание значения к переменной
    return Length;                                                      // Возращает значение в main
}