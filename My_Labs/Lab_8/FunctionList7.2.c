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

void InputWithDynamicMemoryAllocation(char *Line)               // Comes in with one char size of memory
{
    int t = 1;
    int i = 0;
    printf("Write a text: ");
    rewind(stdin);
    do
    {
        t++;
        *(Line + i++) = getchar();                              // Puts the symbol in the array
        Line = (char*)realloc(Line, sizeof(char) * t);          // Makes the array bigger by one char size of memory to allow you to put another character in it
    } while (*(Line + i - 1) != '\n');                          // Until you press enter
    Line = (char*)realloc(Line, sizeof(char) * i);
    *(Line + i - 1) = '\0';
}

void Calculations(char *Line, int Length)
{
    int i = 0;
    int k = 0;
    int t = 0;
    int Repeated = 1;
    char *Word;
    char FirstLetter;
    int start, end;
    SmallCase(Line);
    i = SpaceSkip(Line, i);
    if(*(Line + i) >= 'a' && *(Line + i) <= 'z')
    {
        FirstLetter = *(Line + i);
        start = i;
        do
        {
            i++;
        } while (*(Line + i) != ' ');
        end = i;
        Word = (char*)calloc(end - start + 1, sizeof(char));
    }
    do
    {
        i = SpaceSkip(Line, i);
        if(*(Line + i) == FirstLetter)
        {
            for(k = start; k < end; k++)
            {
                if (*(Line + i) != *(Line + k))
                {
                    break;
                }
                if(end - 1 == k)
                {
                    Repeated += 1;
                }
            }
        }
        do
        {
            i++;
        } while (*(Line + i) != ' ' && *(Line + i) != '\0' );
    } while (*(Line + i) != '\0');
}

void SmallCase(char *Line)
{
    int i = 0;
    do
    {
        if (*(Line + i) >= 'A' && *(Line + i) <= 'Z')
        {
            *(Line + i) += 32;
        }
        if(*(Line + i) == '.' || *(Line + i) == '!' || *(Line + i) == '?' || *(Line + i) == ',')
        {
            *(Line + i) = ' ';
        }
        i++;
    } while (*(Line + i) != '\0');
}

int SpaceSkip(char *Line, int i)
{
    do
    {
        if (*(Line + i) == ' ')
        {
            i++;
        }
    } while (*(Line + i) == ' ');
    return i;
}

