// В квадратной матрице идет сортировка чисел по главной диагонали по возрастанию

#include <stdio.h>
#include <stdlib.h>
// #include <iostream>          // Для VS

int main()
{
    int x, t, N;                            // Повтор программы(x) Временная(t) Размер матрицы(N)
    int **mas;                              // Указатель на матрицу
    do
    {
        // system("CLS");                                       // Для VS
        printf("What's the size of the matrix cube? ");                             // Вывод текста (какой размер матрицы)
        scanf_s("%d", &N);                                                          // Присваивание числа
        mas = (int**)malloc(N * sizeof(int*));                                      // Выделение памяти под строчки
        for(int i = 0; i < N; i++)                                                  // Цикл для выделения памяти под столбцы
        {
            mas[i] = (int*)malloc(N * sizeof(int));                                     // Выделение памяти под столбцы
        }
        for(int i = 0; i < N; i++)                                                  // Цикл для ввода цифр в матрицу
        {
            for(int j = 0; j < N; j++)
            {
                printf("Write a number: ");                                                 // Вывод надписи(введите число)
                scanf_s("%d", &mas[i][j]);                                                  // Присваивание числа к матрице
            }
        }
        for(int i = 0; i < N; i++)                                                  // Цикл вывода массива
        {
            for(int j = 0; j < N; j++)
            {
                printf("%d\t", mas[i][j]);                                                  // Выводит массив
            }
            printf("\n");                                                               // Переход на новую линию
        }
        printf("\n");
        for(int i = 0; i < N; i++)                                                  // Цикл сортировки по диагонали
        {
            for(int j = 1 + i; j < N; j++)                                              // Пузырек
            {
                if(mas[i][i] > mas[j][j])                                                   // Если текущее число больше следуйщего
                {
                    t = mas[i][i];                                                              // Мы запоминаем его
                    mas[i][i] = mas[j][j];                                                      // Свап
                    mas[j][j] = t;                                                              // Возращаем свапнутое число
                }
            }
        }
        for(int i = 0; i < N; i++)                                                  // Цикл вывода массива
        {
            for(int j = 0; j < N; j++)
            {
                printf("%d\t", mas[i][j]);                                                  // Выводит массив
            }
            printf("\n");                                                               // Переход на новую линию
        }
        printf("Do you want to repeat the program?\n1. Yes\n2. No\nAnswer: ");          // Вывод повтора программы да/нет
        scanf_s("%d", &x);                                                              // Если 1
    } while (x == 1);                                                               // То повторяем
    return 0;
}