#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL, "Russian");
    int *a; // указатель на массив
    int n;
    int *stes = 0;
    int k = 0;
    printf("Введите кол-во строк(столбцов): ");
    scanf_s("%d", &n);
    a = (int*)malloc(n * n * sizeof(int)); // Выделение памяти
    for (int i = 0; i < n; i++) // цикл по строкам
    {
        for (int j = 0; j < n; j++) // цикл по столбцам
        {
            printf("a[%d][%d] = ", i, j); // Ввод элементов массива
            scanf_s("%d", (a + i * n + j));
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%5d",*(a+i*n+j));
            if (i == j)
            {
                k++;
            }
        printf("\n");
    }
    stes = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                stes[i] = a[i*n+j];
            }
        }
    }
free(a);
getchar(); getchar();
return 0;
}