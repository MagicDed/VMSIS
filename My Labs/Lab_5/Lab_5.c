// Матрица с динамическим массивом в которой нужно отсортировать числа по убыванию, но оставлять отрицательные числа на своих местах (через функции)

#include <stdio.h>
#include <stdlib.h>
// #include <iostream>          // Для VS

void AllocateMemory(int, int, int);
void Input(int , int, int);
void Output(int , int, int);
int Proccess(int , int);

int main()
{
    int row, col, t;
    char x;
    int **mas;
    do
    {
        printf("How many lines? ");
        scanf_s("%d", &row);
        printf("How many numbers in the line? ");
        scanf_s("%d", &col);
        AllocateMemory(**mas, row, col);
        Input(**mas, row, col);
        Output(**mas, row, col);
        printf("Do you want to repeat program? y/n\n");
        rewind(stdin);
        scanf_s("%c", &x);
    } while (x == 'y');
    return 0;
}

void AllocateMemory(int **mas, int row, int col)
{
    mas = (int**)malloc(row * sizeof(int*));
    for(int i = 0; i < col; i++)
    {
        *(mas + i) = (int*)malloc(col * sizeof(int));
    }
}

void Input(int **mas, int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("Write a number: ");
            scanf_s("%d", *(*(mas + i) + j));
        }
    }
}

void Output(int **mas, int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("%-4d\n", *(*(mas + i) + j));
        }
    }
}