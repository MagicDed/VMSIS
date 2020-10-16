#include <stdio.h>
#include <stdlib.h>
// #include <iostream>

int main()
{
    
	int row, col, x, t;
	int **ptr;
    do
    {
        // system("CLS");
        printf("How many lines? ");
	    scanf_s("%d", &row);
        printf("How many numbers in the line? ");
        scanf_s("%d", &col);
	    ptr = (int**)malloc(row * sizeof(int*));
        for(int i = 0; i < row; i++)
        {
            ptr[i] = (int*)malloc(col * sizeof(int));
        }
	    for (int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                printf("Write a number: ");
	    	    scanf_s("%d", &ptr[i][j]);
            }
        }
        for (int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                printf("%d\t", ptr[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        for(int i = 0; i < row; i++)
        {
            for(int k = 0; k < col; k++)
            {
                for(int j = 1 + k; j < col; j++)
                {
                    if(ptr[i][k] < 0)
                    {
                        do
                        {
                            k = k + 1;
                            j = j + 1;
                        } while(ptr[i][k] < 0);
                    }
                    if(ptr[i][k] < ptr[i][j])
                    {
                        t = ptr[i][k];
                        ptr[i][k] = ptr[i][j];
                        ptr[i][j] = t;
                    }
                }
            }
        }
        for (int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                printf("%d\t", ptr[i][j]);
            }
            printf("\n");
        }
        printf("Repeat program? \n1. Yes \n2. No\n");
        printf("Answer: ");
        scanf("%d", &x);
    } while (x == 1);
    return 0;
}