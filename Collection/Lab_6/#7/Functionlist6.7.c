#include "Header.h"

int StringLength(int Length)
{
    printf("What is the string lenght?: ");
    scanf_s("%d", &Length);
    return Length;
}

char* MemoryAllocation(int Length)
{
    char *Memory;
    Memory = (char*)calloc(Length + 1, sizeof(char));
    return Memory;
}

void Input(char *RawLine, int Length)
{
    printf("Write a string: ");
    printf("String: ", GetString(RawLine, Length));
    printf("%s", RawLine);
}

char* GetString(char *RawLine, int Length)
{
    rewind(stdin);
    int i = 0;
    while ((*(RawLine + i++) = getchar()) != '\n');
	*(RawLine + --i) = '\0';
    return RawLine;
}

char* Calculations(char *RawLine, char *Line, int Length)
{
    int t = 0;
    for(int i = 0; i < Length; i++)
    {
        if(*(RawLine + i) == '.')
        {
            *(Line + t) = *(RawLine + i);
            t += 1;
            if((*(RawLine + i + 1) >= '0' && *(RawLine + i + 1) <= '9') && *(RawLine + i + 2) >= '0' && *(RawLine + i + 2) <= '9')
            {
                *(Line + t) = *(RawLine + i + 1);
                *(Line + t + 1) = *(RawLine + i + 2);
                t += 2;
                for(int j = i + 3; j < Length; j++)
                {
                    i = j;
                    if(!(*(RawLine + j) >= '0' && *(RawLine + j) <= '9'))
                    {
                        break;
                    }
                }
            }
        }
        *(Line + t) = *(RawLine + i);
        t += 1;
    }
    return Line;
}

void Output(char *Line)
{
    printf("\nFormatted line: %s\n", Line);
}
