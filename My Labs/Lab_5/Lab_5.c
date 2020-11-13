// Матрица с динамическим массивом в которой нужно отсортировать числа по убыванию, но оставлять отрицательные числа на своих местах (через функции)

#include "Header.h"
#include "FunctionList5.4.c"

int main()
{
	int row, col;										// Кол-во строчек и столбцов 
	char x;												// Переменная для повторения программы
	int **mas = 0;										// Двухмерный массив
	do
	{
		// system("CLS");
		printf("How many lines? ");								// Ввод кол-ва строчек
		scanf_s("%d", &row);
		printf("How many numbers in the line? ");				// Ввод кол-ва столбцов
		scanf_s("%d", &col);
		mas = AllocateMemory(mas, row, col);					// Выделение памяти
		Input(mas, row, col);									// Ввод чисел в матрицу
		Output(mas, row, col);									// Вывод матрицы
		Calculations(mas, row, col);							// Вычисления в матрице
		Output(mas, row, col);									// Вывод матрицы
		printf("Do you want to repeat program? y/n\n");			// Повтор программы y/n
		rewind(stdin);											// Чистка буфера
		scanf_s("%c", &x);
	} while (x == 'y');											// если x = y то идет повтор программы
	return 0;
}
