#include "Header.h"

int** AllocateMemory(int **mas, int N)                              // Функция выделения памяти
{
	mas = (int**)malloc(N * sizeof(int*));                          // Выделения памяти для указателей(кол-во линий)
	for (int i = 0; i < N; i++)                                     // Цикл для выделения памяти в каждый указатель
	{
		*(mas + i) = (int*)malloc(N * sizeof(int));                 // Выделения памяти для столбцов матрицы
	}
	return mas;
}

void Input(int **mas, int N)                                        // Функция ввода чисел в матрицу
{
	for (int i = 0; i < N; i++)                                     // Цикл ввода чисел
	{
		for (int j = 0; j < N; j++)
		{
			printf("Write a number: ");                             // Введите число
			scanf_s("%d", *(mas + i) + j);                          // Сканирует введеное число
		}
	}
}

void Output(int **mas, int N)                                       // Функция вывода матрицы
{
	for (int i = 0; i < N; i++)                                     // Цикл вывода матрицы
	{
		for (int j = 0; j < N; j++)
		{
			printf("%-4d\t", *(*(mas + i) + j));                    // Вывод чисел матриц
		}
		printf("\n");                                               // Чтобы была прямоугольной
	}
	printf("\n");
}

void Calculations(int **mas, int N)                      	        // Функция для вычисления нужных элементов для выполнения задачи
{
    int t;
    for(int i = 0; i < N; i++)                                      // Цикл сортировки по диагонали
    {
        for(int j = 1 + i; j < N; j++)                              // Пузырек
        {
            if(*(*(mas + i) + i) > *(*(mas + j) + j))               // Если текущее число больше следуйщего
            {
                t = *(*(mas + i) + i);                              // Мы запоминаем его
                *(*(mas + i) + i) = *(*(mas + j) + j);              // Свап
                *(*(mas + j) + j) = t;                              // Возращаем свапнутое число
            }
        }
    }
}