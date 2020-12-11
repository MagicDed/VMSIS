#include "Header.h"

int StringLength(int Length)                                                     // Ввод длинны строки
{
    printf("What is the string lenght?: ");
    scanf_s("%d", &Length);
    return Length;
}

char* MemoryAllocation(int Length)                                              // Выделение памяти под строчку
{
    char *Memory;
    Memory = (char*)calloc(Length + 1, sizeof(char));
    return Memory;
}

void Input(char *RawLine, int Length)                                           // Ввод сиволов в строку
{
    printf("Write a string: ");
    printf("String: ", GetString(RawLine, Length));
    printf("%s", RawLine);
}

char* GetString(char *RawLine, int Length)                                      // Получение строчки
{
    rewind(stdin);
    int i = 0;
    while ((*(RawLine + i++) = getchar()) != '\n');
	*(RawLine + Length) = '\0';
    return RawLine;
}

char* Calculations(char *RawLine, char *Line, int Length)                       // Вычисления
{
    int t = 0;
    for(int i = 0; i < Length; i++)
    {
        *(Line + t) = *(RawLine + i);
        if(*(RawLine + i) == '.')
        {
            if((*(RawLine + i + 1) >= '0' && *(RawLine + i + 1) <= '9') && *(RawLine + i + 2) >= '0' && *(RawLine + i + 2) <= '9')
            {
                *(Line + t + 1) = *(RawLine + i + 1);
                *(Line + t + 2) = *(RawLine + i + 2);
                t += 3;
                i += 3;
                for(i; i < Length; i++)
                {
                    if(!(*(RawLine + i) >= '0' && *(RawLine + i) <= '9'))
                    {
                        i -= 1;
                        t -= 1;
                        break;
                    }
                }
            }
        }
        t += 1;
    }
    return Line; 
}

void Output(char *Line)                                                         // Вывод линии
{
    printf("\nFormatted line: %s\n", Line);
}
