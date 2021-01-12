#include "Header.h"

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

void Calculations(char *Line)
{
    int i = 0;
    char *Word;
    Word = (char*)calloc(1, sizeof(char));
    do
    {
        if (*(Line + i) >= 'a' && *(Line + i) <= 'z')
        {
            int t = i;
            do
            {
                t++;
            } while (*(Line + t) != ' ' || *(Line + t) != '\0');
            Word = (char*)realloc(Word, sizeof(char) * t - i);
            int k = 0;
            do
            {
                *(Word + k++) = *(Line + i++);
            } while (t != k);
        }
        else
        {
            i++
        }
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

