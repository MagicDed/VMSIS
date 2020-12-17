// Форматировать строчку таким образом чтобы 3 число и последйщие числа удалялись если перед ними стояла точка

#include "Header.h"
#include "Functionlist6.7.c"

int main()
{
    char x;                 // Для повтора
    char *RawLine;          // Строчка ввода
    char *Line;             // Форматированая строчка
    int Length = NULL;      // Длинна строк
    do
	{
		Length = StringLength(Length);                          // Ввод длинны строки
        RawLine = MemoryAllocation(Length);                     // Выделение памяти под первую строку
        Line = MemoryAllocation(Length);                        // Выделение памяти под вторую строку
        Input(RawLine, Length);                                 // Ввод сиволов в строку
        Line = Calculations(RawLine, Line, Length);             // Вычисления
        Output(Line);                                           // Вывод линии
		printf("Do you want to repeat program? y/n\n");			// Повтор программы y/n
		rewind(stdin);											// Чистка буфера
		scanf_s("%c", &x);
	} while (x == 'y');
}