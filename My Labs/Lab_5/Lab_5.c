// Матрица с динамическим массивом в которой нужно отсортировать числа по убыванию, но оставлять отрицательные числа на своих местах (через функции)

#include "Header.h"
#include "FunctionListLab5.4.c"

int main()
{
	int row, col;
	char x;
	int **mas = 0;
	do
	{
		// system("CLS");
		printf("How many lines? ");
		scanf_s("%d", &row);
		printf("How many numbers in the line? ");
		scanf_s("%d", &col);
		mas = AllocateMemory(mas, row, col);
		Input(mas, row, col);
		Output(mas, row, col);
		Calculations(mas, row, col);
		Output(mas, row, col);
		printf("Do you want to repeat program? y/n\n");
		rewind(stdin);
		scanf_s("%c", &x);
	} while (x == 'y');
	return 0;
}
