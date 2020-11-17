#include "Header.h"

int** AllocateMemory(int** mas, int row, int col)                   // Функция выделения памяти
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
    int t;                                                          // Переменная для свапа
    for (int i = 0; i < row; i++)                                   // Цикл для сортировки пузырьком
    {
        for (int k = 0; k < col; k++)
        {
            for (int j = 1 + k; j < col; j++)                       // Цикл сравнивания k со всемы оставшемися числами
            {
                if (*(*(mas + i) + k) < 0)                          // Если число меньше нуля то его скипаем
                {
                    do
                    {
                        k += 1;
                        j += 1;
                    } while (*(*(mas + i) + k) < 0);                // До тех пор пока число не будет положительным
                }
                if (*(*(mas + i) + k) < *(*(mas + i) + j))          // Если число k меньше числа j то мы их меняем местами
                {
                    t = *(*(mas + i) + k);
                    *(*(mas + i) + k) = *(*(mas + i) + j);
                    *(*(mas + i) + j) = t;
                }
            }
        }
    }
}