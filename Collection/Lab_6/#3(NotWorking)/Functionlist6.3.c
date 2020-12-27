#include "Header.h"

int StringLength(int Length)                                                    // Ввод длинны строки
{
    int length;
    printf("What is the string lenght?: ");                                     // Какая длинна строки?
    scanf_s("%d", &length);                                                     // Присваивание значения к переменной
    return length;                                                              // Возращает значение в main
}

char* MemoryAllocation(int Length)                                              // Выделение памяти под строчку
{
    char *Memory;                                                               // Переменная для выделения памяти
    Memory = (char*)calloc(Length + 1, sizeof(char));                           // Выделение памяти плюс для \0 символа
    return Memory;                                                              // Возращает значение в main
}

void Input(char *RawLine, int Length)                                           // Ввод сиволов в строку
{
    printf("Write a string: ");                                                 // Введите строчку
    printf("String: ", GetString(RawLine, Length));                             // Строчка, Получение строчки
    printf("%s", RawLine);                                                      // Вывод написаной строчки, обрезаной если она больше
}

char* GetString(char *RawLine, int Length)                                      // Вводит вписаную строку в массив
{
    rewind(stdin);
    int i = 0;
    do
    {
        *(RawLine + i++) = getchar();                                           // Добавлять цифры в массив и повышать i на один до тех пор пока
    } while ((*(RawLine + i - 1) != '\n') && (i < Length));                     // Символ будет являтся \n И будет меньше Length
    if(*(RawLine + i - 1) == '\n')
    {
        *(RawLine + i - 1) = '\0';                                              // Добавляется нуль символ в конце
    }
    else
    {
        *(RawLine + i) = '\0';
    }
    return RawLine;                                                             // Возращает RawLine
}

void Calculations(char *RawLine, char *Line, int Length)                        // Вычисления
{
    int t = 0;
    int a, b, co1, co2;
    int sum = 0;
    for(int i = 0; i < Length; i++)                                             // Цикл прохода по массиву
    {
        if(*(RawLine + i - 1) == '\0')                                              // Если стоит ноль символ то выходим из цикла
        {
            break;
        }
        if(!(*(RawLine + i) == ' '))
        {
            a = i;
            for(i; i < Length; i++)
            {
                b = i;
                if(*(RawLine + i) == ' ' || *(RawLine + i) == '\0')
                {
                    b = i;
                    break;
                }
            }
        }
        if (sum < (b - a))
        {
            sum = b - a;
            co1 = b; co2 = a;
        }
    }
    for(int i = 0; i < Length; i++)                                             // Цикл прохода по массиву
    {
        if(*(RawLine + i - 1) == '\0')                                              // Если стоит ноль символ то выходим из цикла
        {
            break;
        }
        if(!(*(RawLine + i) == ' '))
        {
            a = i;
            for(i; i < Length; i++)
            {
                if(*(RawLine + i) == ' ' || *(RawLine + i) == '\0')
                {
                    b = i;
                    break;
                }
            }
        }
        if (sum > (b - a))
        {
            sum = b - a;
            co1 = b; co2 = a;
        }
    }
    for(co2; co2 < co1; co2++)
    {
        *(Line + t++) = *(RawLine + co2);
    }
    free(RawLine);
    Line = (char*)realloc(Line, sizeof(char) * sum + 1), *(Line + sum) = '\0';  // Уменьшение строчки до нужных размеров + нуль символ
}

void Output(char *Line)                                                         // Вывод линии
{
    if(!(*Line))                                                                // Если первый символ NULL (привет calloc)
    {
        printf("\nThere is no words\n");                                        // Значит двоеточий небыло
    }
    else                                                                        // Если есть
    {
        printf("\nThe shortest word is: %s\n", Line);                           // Выводим символы между двоеточиями
    }
    free(Line);
}