#include "Header.h"

int** AllocateMemory(int **mas, int row, int col)                   // Функция выделения памяти
{
	mas = (int**)malloc(row * sizeof(int*));                        // Выделения памяти для указателей(кол-во линий)
	for (int i = 0; i < row; i++)                                   // Цикл для выделения памяти в каждый указатель
	{
		*(mas + i) = (int*)malloc(col * sizeof(int));               // Выделения памяти для столбцов матрицы
	}
	return mas;
}

void Input(int** mas, int row, int col)                             // Функция ввода чисел в матрицу
{
	for (int i = 0; i < row; i++)                                   // Цикл ввода чисел
	{
		for (int j = 0; j < col; j++)
		{
			printf("Write a number: ");                             // Введите число
			scanf_s("%d", *(mas + i) + j);                          // Сканирует введеное число
		}
	}
}

void Output(int **mas, int row, int col)                            // Функция вывода матрицы
{
	for (int i = 0; i < row; i++)                                   // Цикл вывода матрицы
	{
		for (int j = 0; j < col; j++)
		{
			printf("%-4d\t", *(*(mas + i) + j));                    // Вывод чисел матриц
		}
		printf("\n");                                               // Чтобы была прямоугольной
	}
	printf("\n");
}

void Calculations(int **mas, int row, int col)                      // Функция для вычисления нужных элементов для выполнения задачи
{
    int t;                                                                              // Переменная для свапа
    for(int j = 0; j < col; j++)
    {
        for(int k = 0; k < row; k++)                                                    // Первое число для пузырька
        {
            for(int i = 1 + k; i < row; i++)                                            // Второе число для пузырька
            {
                if(*(*(mas + k) + j) > 0)                                               // Если число больше нуля
                {
                    do                                                                  // Происходит скип до тех пор пока не будет отрецательное
                    {
                        k += 1;
                        i += 1;
                    } while(*(*(mas + k) + j) > 0 && i < row);                        
                }
                if(*(*(mas + k) + j) < 0 && !(i == row) && *(*(mas + i) + j) < 0)       // Если число меньше нуля
                {
                    if(*(*(mas + i) + j) > *(*(mas + k) + j))                           // Если первое число больше второго
                    {
                        t = *(*(mas + k) + j);                                          // Первое число запоминаем
                        *(*(mas + k) + j) = *(*(mas + i) + j);                          // На его место пишем второе число
                        *(*(mas + i) + j) = t;                                          // Вместо второго пишем первое
					}
                }
            }
        }
    }
}