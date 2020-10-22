#include <stdio.h>

int main()
{
    int *mas;
    int x;
    scanf_s("%d", &x);
    mas = (int*)malloc(x * x * sizeof(int));
    for (int i = 0; i < x * x; i++)
    {
        printf("Write a number: ");
        scanf("%d", &mas[i]);
    }
    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < x; j++)
        {
            printf("%d\t", mas[i * x + j]);
        }
        printf("\n");     
    }
    return 0;
}