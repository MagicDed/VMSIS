#include "Header.h"
#include "Functionlist6.7.c"

int main()
{
    char x;
    char *RawLine;
    char *Line;
    int Length;
    do
	{
		Length = StringLength(Length);
        RawLine = MemoryAllocation(Length);
        Line = MemoryAllocation(Length);
        Input(RawLine, Length);
        Line = Calculations(RawLine, Line, Length);
        Output(Line);
		printf("Do you want to repeat program? y/n\n");			// Повтор программы y/n
		rewind(stdin);											// Чистка буфера
		scanf_s("%c", &x);
	} while (x == 'y');
}