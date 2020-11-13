// В матрице найти найти минимальное число на четном месте

#include "Header.h"
#include "FunctionList5.2.c"

int main()
{
    int x, row, col;                                            // Для повторения проги(x) Колво линий(row) Колво столбцов(col)
    int **mas = 0;                                              // Двухмерный массив
    do
    {
        // system("CLS");                                       // Для VS
        printf("How many lines? ");                                 // Ввод кол-ва линий
        scanf_s("%d", &row);
        printf("how many numbers in the line? ");                   // Ввод колва столбцов
        scanf_s("%d", &col);
        mas = AllocateMemory(mas, row, col);                        // Выделения памяти
        Input(mas, row, col);                                       // Ввод чисел в матрицу
        Output(mas, row, col);                                      // Вывод матрицы
        Calculations(mas, row, col);                                // Вычисления
        printf("Do you want to repeat program? y/n\n");			    // Повтор программы y/n
		rewind(stdin);											    // Чистка буфера
		scanf_s("%c", &x);
	} while (x == 'y');											    // если x = y то идет повтор программы
	return 0;
}