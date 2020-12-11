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

char* GetString(char *RawLine, int Length)                                      // Получение строчки
{
    rewind(stdin);                                                              // Чистит буфер
    int i = 0;
    while ((*(RawLine + i++) = getchar()) != '\n');                             // Получать и записывать начение до нажатия Enter
	*(RawLine + Length) = '\0';                                                 // Поставить нуль символ в конец
    return RawLine;                                                             // Возращает значение в Input функцию
}

char* Calculations(char *RawLine, char *Line, int Length)                       // Вычисления
{
    int t = 0;                                                                  // Переменная для записи чисел во вторую строчку
    for(int i = 0; i < Length; i++)                                             // Цикл проходящий по всей его длинне
    {
        *(Line + t) = *(RawLine + i);                                           // Запись символов из первой строчки во вторую
        t += 1;                                                                 // Переход на следуйщий элемент на второй строчке
        if(*(RawLine + i) == '.')                                               // Если есть точка
        {
            if((*(RawLine + i + 1) >= '0' && *(RawLine + i + 1) <= '9') && *(RawLine + i + 2) >= '0' && *(RawLine + i + 2) <= '9')  // И есть две цифры перед ней
            {
                *(Line + t) = *(RawLine + i + 1);                               // Записываем число из первого строчки во вторую
                *(Line + t + 1) = *(RawLine + i + 2);                           // Записываем число из первого строчки во вторую
                t += 2;                                                         // Выравниваем позиции в строчках
                i += 3;                                                         // Выравниваем позиции в строчках
                for(i; i < Length; i++)                                         // Цикл пропуска
                {
                    if(!(*(RawLine + i) >= '0' && *(RawLine + i) <= '9'))       // Если символ не число
                    {
                        i -= 1;                                                 // Перемещаемся на букву
                        break;                                                  // Выход из цикла
                    }
                }
            }
        }
    }
    return Line;                                                                // Возрат форматированой линии
}

void Output(char *Line)                                                         // Вывод линии
{
    printf("\nFormatted line: %s\n", Line);                                     // Вывод
}
