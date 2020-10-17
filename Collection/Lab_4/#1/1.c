#include <stdio.h>
#include <stdlib.h>
// #include <iostream>

int main()
{
    int x, N, max;
    int co1, co2;
    int **mas;
    do
    {
        // system("CLS");
        printf("What's the size of the matrix cube? ");
        scanf_s("%d", &N);
        mas = (int**)malloc(N * sizeof(int*));
        for(int i = 0; i < N; i++)
        {
            mas[i] = (int*)malloc(N * sizeof(int));
        }
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                printf("Write a number: ");
                scanf_s("%d", &mas[i][j]);
            }
        }
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                printf("%d\t", mas[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        max = mas[0][0];
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(max < mas[i][j])
                {
                    max = mas[i][j];
                    co1 = i;
                    co2 = j;
                }
            }
        }
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(!(co1 == i || co2 == j))
                {
                    printf("%d\t", mas[i][j]);
                }
            }
            printf("\n");
        }
        printf("Max: %d\n", max);
        printf("Do you want to repeat the program?\n1. Yes\n2. No\nAnswer: ");
        scanf_s("%d", &x);
    } while (x == 1);
    return 0;
}