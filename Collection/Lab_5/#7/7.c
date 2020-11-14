// В квадратной матрице идет сортировка чисел по главной диагонали по возрастанию

#include "Header.h"
#include "FunctionList5.7.c"

int main()
{
    int N;
    char x;                                                     // Для повторения проги(x)
    int **mas = 0;                                              // Двухмерный массив
    do
    {
        // system("CLS");                                       // Для VS
        printf("What's the size of the matrix cube? ");         // Ввод кол-ва линий
        scanf_s("%d", &N);
        mas = AllocateMemory(mas, N);                           // Выделения памяти
        Input(mas, N);                                          // Ввод чисел в матрицу
        Output(mas, N);                                         // Вывод матрицы
        Calculations(mas, N);                                   // Вычисления
        Output(mas, N);                                         // Вывод матрицы
        printf("Do you want to repeat program? y/n\n");			// Повтор программы y/n
		rewind(stdin);											// Чистка буфера
		scanf_s("%c", &x);
	} while (x == 'y');											// если x = y то идет повтор программы
	return 0;
}