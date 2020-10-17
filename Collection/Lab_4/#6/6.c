// В динамической матрице ищется максимальное минимальное и минимальное максимальное и меняет их местами

#include <stdio.h>
#include <stdlib.h>
// #include <iostream>                  // Для VS

int main()
{
    int x, t, row, col;
    int co1, co2, co3, co4;
    int minmax = 0;
    int maxmin = 0;
    int **mas;
    do
    {
        // system("CLS");                                           // Для VS
        printf("How many lines? ");                                             // Вывод текста (сколько строк)
        scanf_s("%d", &row);                                                    // Присваивание числа
        printf("how many numbers in the line? ");                               // Вывод текста (сколько столбцов)
        scanf_s("%d", &col);                                                    // Присваивание числа
        mas = (int**)malloc(row * sizeof(int*));                                // Выделение памяти под строчки
        for(int i = 0; i < row; i++)                                            // Цикл для выделения памяти под столбцы
        {
            mas[i] = (int*)malloc(col * sizeof(int));                               // Выделение памяти под столбцы
        }
        for(int i = 0; i < row; i++)                                            // Цикл для ввода цифр в матрицу
        {
            for(int j = 0; j < col; j++)
            {
                printf("Write a number: ");                                             // Вывод надписи(введите число)
                scanf_s("%d", &mas[i][j]);                                              // Присваивание числа к матрице
            }
        }
        for(int i = 0; i < row; i++)                                            // Цикл вывода массива
        {
            for(int j = 0; j < col; j++)
            {
                printf("%d\t", mas[i][j]);                                              // Выводит массив
            }
            printf("\n");                                                           // Переход на новую линию
        }
        printf("\n");
        for(int i = 0; i < row; i++)                                            // Цикл нахождения минмакс и минмакс
        {
            for(int j = 0; j < col; j++)
            {
                if(mas[i][j] < minmax)                                                  // Ищем самое минимальное
                {
                    minmax = mas[i][j];                                                     // Если меньше то оно новое минимальное
                }
                if(mas[i][j] > maxmin)                                                  // Ищем самое максимальное
                {
                    maxmin = mas[i][j];                                                     // Если меньше то оно новое максимальное
                }
            }
        }
        for(int i = 0; i < row; i++)                                            // Цикл нахождения минмакс и минмакс 
        {
            for(int j = 0; j < col; j++)
            {
                if(mas[i][j] < 0 && mas[i][j] > minmax)                                 // Если число меньше минмакс и меньше нуля
                {
                    co1 = i;                                                                // Запоминаем ее координаты
                    co2 = j;                                                                // Запоминаем ее координаты
                }
                if(mas[i][j] >= 0 && mas[i][j] < maxmin)                                // Если число меньше максмин и меньше нуля
                {
                    co3 = i;                                                                // Запоминаем ее координаты
                    co4 = j;                                                                // Запоминаем ее координаты
                }
            }
        }
        t = mas[co1][co2];                                                      // Минмакс запоминается
        mas[co1][co2] = mas[co3][co4];                                          // Вместо него пишем максмин
        mas[co3][co4] = t;                                                      // Вставляем минмакс вместо максмин
        for(int i = 0; i < row; i++)                                            // Цикл для вывода матрицы
        {
            for(int j = 0; j < col; j++)
            {
                printf("%d\t", mas[i][j]);                                              // Вывод матрицы
            }
            printf("\n");
        }
        printf("Maxmin: %d\nMinmax: %d\n", mas[co3][co4], mas[co1][co2]);           // Вывод минмакс и максмин 
        printf("Do you want to repeat the program?\n1. Yes\n2. No\nAnswer: ");      // Вывод повтора программы да/нет
        scanf_s("%d", &x);                                                          // Если 1
    } while (x == 1);                                                           // То повторяем
    return 0;
}