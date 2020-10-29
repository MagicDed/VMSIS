// В матрице найти седловую точку

#include <stdio.h>
#include <stdlib.h>
// #include <iostream>                  // Для VS

int main()
{
    int x, t, N, max;                   // Повтор программы(x) Временная(t) Размер матрицы(N) Макс число(max) 
    int dot;                            // Седловая точка
    int *mas;                           // Указатель на матрицу
    do
    {
        // system("CLS");                                                           // Для VS
        printf("What's the size of the matrix cube? ");                             // Вывод текста (какой размер матрицы)
        scanf_s("%d", &N);                                                          // Присваивание числа
        mas = (int*)malloc(N * N * sizeof(int));                                    // Выделение памяти под строчки
        for(int i = 0; i < N; i++)                                                  // Цикл для ввода цифр в матрицу
        {
            for(int j = 0; j < N; j++)
            {
                printf("Write a number: ");                                                 // Вывод надписи(введите число)
                scanf_s("%d", &mas[i * N + j]);                                             // Присваивание числа к матрице
            }
        }
        for(int i = 0; i < N; i++)                                                  // Цикл вывода массива
        {
            for(int j = 0; j < N; j++)
            {
                printf("%d\t", mas[i * N + j]);                                             // Выводит массив
            }
            printf("\n");                                                               // Переход на новую линию
        }
        for(int i = 0; i < N; i++)                                                  // Cканирование линии
        {
            max = mas[i * N];                                                           // Первое число в линии и есть максимальное
            for(int j = 0; j < N; j++)                                                  // Ишем максимальное число в линии
            {
                if(mas[i * N + j] > max)                                                    // Если число больше макс то
                {
                    max = mas[i * N + j];                                                       // То оно новое макс
                    t = j;                                                                      // Запоминаем его место
                }
            }
            for(int k = 0; k < N; k++)                                                  // Цикл чтобы узнать является ли макс минимальным числом в столбце
            {
                if(max < mas[k * N + t] && (!i == k))                                       // Если меньше и не равен самому себе то
                {
                    dot = max;                                                                  // Дот = макс
                }
                if(max > mas[k * N + t] && (!i == k))                                       // Если больше и не равен самому себе то
                {
                    break;                                                                      // То выход из цикла
                } 
            }
        }
        if(!dot)                                                                    // Если точки нет
        {
            printf("There is no sedlovaya dot\n");                                        // Значит нету
        }
        else                                                                        // Если есть
        {
            printf("Sedlovaya dot: %d\n", dot);                                         // Вывод максимального числа
        }
        printf("Do you want to repeat the program?\n1. Yes\n2. No\nAnswer: ");      // Вывод повтора программы да/нет
        scanf_s("%d", &x);                                                          // Если 1
    } while (x == 1);                                                           // То повторяем
    return 0;
}