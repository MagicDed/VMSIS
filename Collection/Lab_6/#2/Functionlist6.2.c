#include "Header.h"

int StringLength(int Length)                                                    // Ввод длинны строки
{
    printf("What is the string lenght?: ");                                     // Какая длинна строки?
    scanf_s("%d", &Length);                                                     // Присваивание значения к переменной
    return Length;                                                              // Возращает значение в main
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
    *(RawLine + i) = '\0';                                                      // Добавляется нуль символ в конце
    return RawLine;                                                             // Возращает RawLine
}

char* Calculations(char *RawLine, char *Line, int Length)                       // Вычисления
{
    int t = 0;                                                                  // Временная для записи чисел в первый массив по порядку
    for(int i = 0; i < Length; i++)                                             // Цикл прохода по массиву
    {
        if(*(RawLine + i) == ':')                                               // Если в символ является двоеточием
        {
            i++;                                                                // Мы смотрим на следуйщий символ
            for(i; i < Length; i++)
            {
                if(*(RawLine + i) == ':')                                       // Если символ является двоеточием
                {
                    break;                                                      // Выходим из цикла
                }
                *(Line + t) = *(RawLine + i);                                   // Если это не двоеточие значит записываем во вторую строку
                t++;                                                            // Идем на следуйщий символ во второй строке
            }
        }
    }
    return Line;                                                                // Возрат форматированой линии
}

void Output(char *Line)                                                         // Вывод линии
{
    if(!(*Line))                                                                // Если первый символ NULL (привет calloc)
    {
        printf("\nThere is no colums\n");                                       // Значит двоеточий небыло
    }
    else                                                                        // Если есть
    {
        printf("\nFormatted line: %s\n", Line);                                 // Выводим символы между двоеточиями
    }
}