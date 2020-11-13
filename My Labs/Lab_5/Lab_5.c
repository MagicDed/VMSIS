// Матрица с динамическим массивом в которой нужно отсортировать числа по убыванию, но оставлять отрицательные числа на своих местах (через функции)

#include <stdio.h>
#include <stdlib.h>
// #include <iostream>          // Для VS

int** AllocateMemory(int**, int, int);
void Input(int**, int, int);
void Output(int**, int, int);
void Calculations(int**, int, int);

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

int** AllocateMemory(int** mas, int row, int col)
{
	mas = (int**)malloc(row * sizeof(int*));
	for (int i = 0; i < col; i++)
	{
		*(mas + i) = (int*)malloc(col * sizeof(int));
	}
	return mas;
}

void Input(int** mas, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("Write a number: ");
			scanf_s("%d", *(mas + i) + j);
		}
	}
}

void Output(int** mas, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%-4d\t", *(*(mas + i) + j));
		}
		printf("\n");
	}
	printf("\n");
}
void Calculations(int **mas, int row, int col)
{
    int t;
    for (int i = 0; i < row; i++)
    {
        for (int k = 0; k < col; k++)
        {
            for (int j = 1 + k; j < col; j++)
            {
                if (*(*(mas + i) + k) < 0)
                {
                    do
                    {
                        k += 1;
                        j += 1;
                    } while (*(*(mas + i) + k) < 0);
                }
                if (*(*(mas + i) + k) < *(*(mas + i) + j))
                {
                    t = *(*(mas + i) + k);
                    *(*(mas + i) + k) = *(*(mas + i) + j);
                    *(*(mas + i) + j) = t;
                }
            }
        }
    }
}