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
    Memory = (char*)calloc(Length * 2 + 1, sizeof(char));                       // Выделение памяти плюс для \0 символа
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
    *(RawLine + i - 1) = '\0';                                                  // Добавляется нуль символ в конце
    return RawLine;                                                             // Возращает RawLine
}

void Calculations(char *RawLine, char *Line, int Length)                        // Вычисления
{
    int t = 0;
    for(int i = 0; i < Length;)                                                 // Цикл прохода по строке
    {
        if(*(RawLine + i) == '\0')                                              // Если стоит ноль символ то выходим из цикла
        {
            break;
        }
        if(*(RawLine + i) == '*')                                               // Если звездочка
        {
            i++;                                                                // то пропускаем
        }
        else                                                                    // В ином случае пишем одно значение дважды во вторую строку
        {
            *(Line + t++) = *(RawLine + i);
            *(Line + t++) = *(RawLine + i);
            i++;
        }
    }
    free(RawLine);
    Line = (char*)realloc(Line, sizeof(char) * t + 1), *(Line + t) = '\0';      // Уменьшение строчки до нужных размеров + нуль символ
}

void Output(char *Line)                                                         // Вывод линии
{
    if(!(*Line))                                                                // Если первый символ NULL (привет calloc)
    {
        printf("\nThere is no symbols except *\n");                             // Значит двоеточий небыло
    }
    else                                                                        // Если есть
    {
        printf("\nFormatted line: %s\n", Line);                                 // Выводим символы между двоеточиями
    }
    free(Line);
}