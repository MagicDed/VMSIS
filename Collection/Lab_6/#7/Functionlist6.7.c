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
    *(RawLine + i) = '\0';                                                      // Добавляется нуль символ в конце
    return RawLine;                                                             // Возращает RawLine
}

void Calculations(char *RawLine, char *Line, int Length)                        // Вычисления
{
    int t = 0;
    for(int i = 0; i < Length;)
    {
        if(*(RawLine + i) == '\0')                                              // Если стоит ноль символ то выходим из цикла
        {
            break;
        }
        *(Line + t++) = *(RawLine + i++);                                       // Записываем символ во вторую строку плюс переходим на следуйщий элемент массива
        if(*(RawLine + i - 1) == '.')                                           // Если мы записали точку
        {
            if((*(RawLine + i) >= '0' && *(RawLine + i) <= '9') && *(RawLine + i + 1) >= '0' && *(RawLine + i + 1) <= '9')  // И перед ней две цифры
            {
                *(Line + t++) = *(RawLine + i++);                               // Мы записываем эти два числа
                *(Line + t++) = *(RawLine + i++);
                for(i; i < Length;)                                             // Цикл пропуска
                {
                    if(!(*(RawLine + i) >= '0' && *(RawLine + i) <= '9'))       // Если символ не число
                    {
                        break;                                                  // Выход из цикла
                    }
                    else                                                        // Если число то смотрим на следуйщий элемент
                    {
                        i++;
                    }
                }
            }
        }
    }
    free(RawLine);
    Line = (char*)realloc(Line, sizeof(char) * t + 1), *(Line + t) = '\0';      // Уменьшение строчки до нужных размеров + нуль символ
}

void Output(char *Line)                                                         // Вывод линии
{
    printf("\nFormatted line: %s\n", Line);                                     // Вывод
    free(Line);
}
