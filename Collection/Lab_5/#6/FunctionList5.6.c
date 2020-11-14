#include "Header.h"

int** AllocateMemory(int** mas, int row, int col)                   // Функция выделения памяти
{
	mas = (int**)malloc(row * sizeof(int*));                        // Выделения памяти для указателей(кол-во линий)
	for (int i = 0; i < col; i++)                                   // Цикл для выделения памяти в каждый указатель
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

void Output(int** mas, int row, int col)                            // Функция вывода матрицы
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
    int minmax, maxmin;
    int t, co1, co2, co3, co4;
    minmax = *(*mas);
    maxmin = *(*mas);
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(*(*(mas + i) + j) < maxmin && *(*(mas + i) + j) < 0)
            {
                maxmin = *(*(mas + i) + j);
            }
            if(*(*(mas + i) + j) > minmax && *(*(mas + i) + j) >= 0)
            {
                minmax = *(*(mas + i) + j);
            }
        }
    }
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(*(*(mas + i) + j) > maxmin && *(*(mas + i) + j) < 0)
            {
                maxmin = *(*(mas + i) + j);
                co1 = i;
                co2 = j;
            }
            if(*(*(mas + i) + j) < minmax && *(*(mas + i) + j) >= 0)
            {
                minmax = *(*(mas + i) + j);
                co3 = i;
                co4 = j;
            }
        }
    }
    if(minmax < 0 || maxmin >= 0)
    {
        printf("There is no minmax or maxmin\n");
    }
    else
    {
        t = *(*(mas + co1) + co2);
        *(*(mas + co1) + co2) = *(*(mas + co3) + co4);
        *(*(mas + co3) + co4) = t;
        Output(mas, row, col);
        printf("Maxmin: %d\nMinmax: %d\n", maxmin, minmax);
    }
}