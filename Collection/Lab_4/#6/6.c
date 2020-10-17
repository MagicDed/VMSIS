// В динамической матрице ищется максимальное минимальное и минимальное максимальное и меняет их местами

#include <stdio.h>
#include <stdlib.h>
// #include <iostream>

int main()
{
    int x, t, row, col;
    int co1, co2, co3, co4;
    int minmax = 0;
    int maxmin = 0;
    int **mas;
    do
    {
        // system("CLS");
        printf("How many lines? ");
        scanf_s("%d", &row);
        printf("how many numbers in the line? ");
        scanf_s("%d", &col);
        mas = (int**)malloc(row * sizeof(int*));
        for(int i = 0; i < row; i++)
        {
            mas[i] = (int*)malloc(col * sizeof(int));
        }
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                printf("Write a number: ");
                scanf_s("%d", &mas[i][j]);
            }
        }
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                printf("%d\t", mas[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(mas[i][j] < minmax)
                {
                    minmax = mas[i][j];
                }
                if(mas[i][j] > maxmin)
                {
                    maxmin = mas[i][j];
                }
            }
        }
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(mas[i][j] < 0 && mas[i][j] > minmax)
                {
                    co1 = i;
                    co2 = j;
                }
                if(mas[i][j] >= 0 && mas[i][j] < maxmin)
                {
                    co3 = i;
                    co4 = j;
                }
            }
        }
        t = mas[co1][co2];
        mas[co1][co2] = mas[co3][co4];
        mas[co3][co4] = t;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                printf("%d\t", mas[i][j]);
            }
            printf("\n");
        }
        printf("Maxmin: %d\nMinmax: %d\n", mas[co3][co4], mas[co1][co2]);
        printf("Do you want to repeat the program?\n1. Yes\n2. No\nAnswer: ");
        scanf_s("%d", &x);
    } while (x == 1);
    return 0;
}