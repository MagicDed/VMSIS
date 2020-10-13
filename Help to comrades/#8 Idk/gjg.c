// В введеной матрице 5 на 5 считаются числа пирамидкой с левого края

#include <stdio.h>
#define N 5

int main()
{
    int mm[N][N];                   // Матрица
    int max;                        // Переменная для записи максимального значения
    for(int i = 0; i < N; i++)                      // Два цикла чтобы написать матрицу
    {
        for(int j = 0; j < N; j++)
        {
            printf("Write a number: ");                     // Выводит надпись
            scanf_s("%d", &mm[i][j]);                       // Сканирует введеное число после надписи
        }
    }
    for(int i = 0; i < N; i++)                      // Два цикла чтобы вывести матрицу
    {
        for(int j = 0; j < N; j++)
        {
            printf("%d\t",mm[i][j]);                        // Выводит матрицу 
        }
        printf("\n");                                   // Чтобы выводились значения в строчки, а не в одну строку
    }
    max = mm[0][0];                                 // Приравниваем Первое число матрицы как максимальное
    for(int i = 0; i < N; i++)
    {
        if(i < 3)                                       // Если строка ниже середины массива то
        {
            for(int j = 0; j < i + 1; j++)                  // Проходимся по строчке до значения равной цифре строки +1
            {
                if(max < mm[i][j])                              // Если число больше Макс то
                {
                    max = mm[i][j];                                 // Оно является новым Максом
                }
            }
        }
        else                                            // Если строка и есть середина или выше то
        {
            for(int j = 0; j < N - i; j++)                  // Проходимся по строчке до значения N - i
            {
               if(max < mm[i][j])                               // Если число больше Макс то
                {
                    max = mm[i][j];                                 // Оно является новым Максом
                } 
            }
        }
    }
    printf("Max: %d", max);                         // Выводит максимальное число
    return 0;
}