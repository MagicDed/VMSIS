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
    int minmax, maxmin;                                                         // Минмакс и максмин
    int t, co1, co2, co3, co4;                                                  // Координаты и временная
    minmax = *(*mas);                                                           // Минмакс = первому эдементу в матрице
    maxmin = *(*mas);                                                           // Максмин = первому эдементу в матрице
    for(int i = 0; i < row; i++)                                                // Цикл находит самое маленькое и самое большое число
    {
        for(int j = 0; j < col; j++)
        {
            if(*(*(mas + i) + j) < maxmin && *(*(mas + i) + j) < 0)             // Находит самое минимальное меньше нуля
            {
                maxmin = *(*(mas + i) + j);                                     // Присваивает число к переменной
            }
            if(*(*(mas + i) + j) > minmax && *(*(mas + i) + j) >= 0)            // Находит самое большое которое больше или равно нулю
            {
                minmax = *(*(mas + i) + j);                                     // Присваивает число к переменной
            }
        }
    }
    for(int i = 0; i < row; i++)                                                // Находит максмин и минмакс
    {
        for(int j = 0; j < col; j++)
        {
            if(*(*(mas + i) + j) > maxmin && *(*(mas + i) + j) < 0)             // Находит максимальное число до нуля
            {
                maxmin = *(*(mas + i) + j);                                     // Присваивает число к переменной и запоминает координаты
                co1 = i;
                co2 = j;
            }
            if(*(*(mas + i) + j) < minmax && *(*(mas + i) + j) >= 0)            // Находит минимальное число до отрицательных чисел
            {
                minmax = *(*(mas + i) + j);                                     // Присваивает число к переменной и запоминает координаты
                co3 = i;
                co4 = j;
            }
        }
    }
    if(minmax < 0 || maxmin >= 0)                                               // Если какое то из переменных не верно
    {
        printf("There is no minmax or maxmin\n");                               // То тут нет максмин и минмакс
    }
    else                                                                        // В другом случае
    {
        t = *(*(mas + co1) + co2);                                              // Максмин и минмакс меняется местами
        *(*(mas + co1) + co2) = *(*(mas + co3) + co4);
        *(*(mas + co3) + co4) = t;
        Output(mas, row, col);                                                  // Вывод матрицы
        printf("Maxmin: %d\nMinmax: %d\n", maxmin, minmax);                     // Вывод максмин и минмакс
    }
}