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

void Input(int **mas, int row, int col)                             // Функция ввода чисел в матрицу
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

void Calculations(int **mas, int row, int col)                      	// Функция для вычисления нужных элементов для выполнения задачи
{
	int min;                                                    		// Минимальное
    int co1, co2;                                               		// Координаты
	min = mas[0][1];
        for(int i = 0; i < row; i++)                                	// Цикл находит максимальное на четном месте
        {
            for(int j = 1; j < col; j += 2)
            {
                if(min < *(*(mas + i) + j))                         	// Если число больше мин то
                {
                    min = *(*(mas + i) + j);                        	// Оно новое мин
                }
            }
        }
        for(int i = 0; i < row; i++)                                	// Цикл находит минимальное число на четном месте
        {
            for(int j = 1; j < col; j += 2)
            {
                if(*(*(mas + i) + j) < min && *(*(mas + i) + j) >= 0)	// Если число меньше минимального и больше нуля то
                {
                    min = *(*(mas + i) + j);                         	// Это число новое мин
                    co1 = i + 1;
                    co2 = j + 1;
                }
            }
        }
        printf("Min: %d\n", min);										// Вывод минимального
        printf("Row: %d\nCol: %d\n", co1, co2);							// И его координат
}