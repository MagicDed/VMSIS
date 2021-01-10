#include "Header.h"

char *PointerMemoryAllocation()                                 // Выделяет память под указатель
{
    char *Memory;
    Memory = (char *)calloc(1, sizeof(char));
    return Memory;
}

void InputWithDynamicMemoryAllocation(char *Line)               // Выделяет динамично память по длинне текста
{
    int t = 1;
    int i = 0;
    printf("Write a text: ");
    rewind(stdin);
    do
    {
        t++;
        *(Line + i++) = getchar();                              // Вписывает букву в массив
        Line = (char*)realloc(Line, sizeof(char) * t);          // Увеличивает массив на один char
    } while (*(Line + i - 1) != '\n');                          // До тех пор пока не нажмешь ентер
    Line = (char*)realloc(Line, sizeof(char) * i);
    *(Line + i - 1) = '\0';                                     // Вместо \n записывает \0
}

int StringLength(char *Line)                                    // Находит длинну текста
{
    int i = 0;
    int t = 0;
    do                                                          // Считать до тех пор
    {
        t++;
    } while (*(Line + i++) != '\0');                            // Пока не увидит нуль символ
    return t;
}

void Calculations(char *Line, int Length)
{
    int i = 0;
    int t = 0;
    int s = 0;                                                                  // Считает предложения
    char *NumberString;                                                         // Доп массив
    NumberString = (char*)calloc(Length, sizeof(char));
    do                                                                          // Записывает точки и цифры во второй массив
    {
        if(*(Line + i) >= '0' && *(Line + i) <= '9')
        {
            *(NumberString + t++) = *(Line + i);
        }
        if(*(Line + i) == '.' || *(Line + i) == '!' ||*(Line + i) == '?')
        {
            *(NumberString + t++) = *(Line + i);
        }
        i++;
    } while (*(Line + i) != '\0');                                              // До нуль символа
    free(Line);
    NumberString = (char*)realloc(NumberString, sizeof(char) + t + 1);
    *(NumberString + t + 1) = '\0';                                             // Ставит нуль символ в строке
    for (int k = 0; *(NumberString + k) != '\0'; k++)
    {
        if (*(NumberString + k) >= '0' && *(NumberString + k) <= '9')           // Если цифра
        {
            int sum = 0;                                                        // Считается сумма
            do
            {
                sum += *(NumberString + k++)  - '0';                            // Считается сумма в предложении
            } while (*(NumberString + k) >= '0' && *(NumberString + k) <= '9'); // Пока не увидит точку или что то тип этого
            printf("Sum of the numbers in %d sentence is %d\n", s + 1, sum);
        }
        s++;                                                                    // Считает предложения
    }
}