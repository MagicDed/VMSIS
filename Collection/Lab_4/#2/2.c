#include <stdio.h>
#include <stdlib.h>
// #include <iostream>

int main()
{
    int x, row, col;
    int min = 0;
    int co1, co2;
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
        for(int i = 0; i < row; i++)
        {
            for(int j = 1; j < col; j++)
            {
                if(min < mas[i][j])
                {
                    min = mas[i][j];
                }
                j = j + 1;
            }
        }
        for(int i = 0; i < row; i++)
        {
            for(int j = 1; j < col; j++)
            {
                if(mas[i][j] < min && mas[i][j] >= 0)
                {
                    min = mas[i][j];
                }
                j = j + 1;
            }
        }
        printf("Min: %d\n", min);
        printf("Do you want to repeat the program?\n1. Yes\n2. No\nAnswer: ");
        scanf_s("%d", &x);
    } while (x == 1);
    return 0;
}