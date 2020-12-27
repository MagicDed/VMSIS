#include "Header.h"

int StringLength()                                              // Ввод длинны строки
{
    int Length;
    printf("How many common words do you need?: ");                     // Какая длинна строки?
    scanf_s("%d", &Length);                                             // Присваивание значения к переменной
    return Length;                                                      // Возращает значение в main
}

char *PointerMemoryAllocation()
{
    char *Memory;
    Memory = (char *)calloc(1, sizeof(char));
    return Memory;
}

void InputWithDynamicMemoryAllocation(char *Line)
{
    int t = 1;
    int i = 0;
    printf("Write a text: ");
    rewind(stdin);
    do
    {
        t++;
        *(Line + i++) = getchar();
        Line = realloc(Line, sizeof(char) * t);
    } while (*(Line + i - 1) != '\n');
    *(Line + i - 1) = '\0';
    printf("%s", Line);
}