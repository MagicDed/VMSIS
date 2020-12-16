// Форматировать строчку таким образом чтобы 3 число и последйщие числа удалялись если перед ними стояла точка

// The task is to remove all the numbers after the second one if there was a dot before it so .0123 become .01
#include "Header.h"
#include "Functionlist6.7.c"

int main()
{
    char x;                 // Для повтора
    char *RawLine;          // Строчка ввода
    char *Line;             // Форматированая строчка
    int Length;             // Длинна строк
    do
	{
		Length = StringLength(Length);                          // Ввод длинны строки
        RawLine = MemoryAllocation(Length);                     // Выделение памяти под первую строку
        Line = MemoryAllocation(Length);                        // Выделение памяти под вторую строку
        Input(RawLine, Length);                                 // Ввод сиволов в строку
        Line = Calculations(RawLine, Line, Length);             // Вычисления
        Output(Line);                                           // Вывод линии
        //free(RawLine);  free(Line);                             // AINT DAMN WORKING AAA
		printf("Do you want to repeat program? y/n\n");			// Повтор программы y/n
		rewind(stdin);											// Чистка буфера
		scanf_s("%c", &x);
	} while (x == 'y');
}