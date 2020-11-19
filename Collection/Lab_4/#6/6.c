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
    int *mas;
    do
    {
        // system("CLS");                                           // Для VS
        printf("How many lines? ");                                             // Вывод текста (сколько строк)
        scanf_s("%d", &row);                                                    // Присваивание числа
        printf("how many numbers in the line? ");                               // Вывод текста (сколько столбцов)
        scanf_s("%d", &col);                                                    // Присваивание числа
        mas = (int*)malloc(row * col * sizeof(int));                            // Выделение памяти под строчки
        for(int i = 0; i < row; i++)                                            // Цикл для ввода цифр в матрицу
        {
            for(int j = 0; j < col; j++)
            {
                printf("Write a number: ");                                         // Вывод надписи(введите число)
                scanf_s("%d", mas+ i * col + j);                                    // Присваивание числа к матрице
            }
        }
        for(int i = 0; i < row; i++)                                                // Цикл вывода массива
        {
            for(int j = 0; j < col; j++)
            {
                printf("%d\t", *(mas + i * col + j));                               // Выводит массив
            }
            printf("\n");                                                           // Переход на новую линию
        }
        printf("\n");
        for(int i = 0; i < row; i++)                                                // Цикл находит самое маленькое и самое большое число
        {
            for(int j = 0; j < col; j++)
            {
                if(*(mas + i * col + j) < maxmin && *(mas + i * col + j) < 0)       // Находит самое минимальное меньше нуля
                {
                    maxmin = *(mas + i * col + j);                                  // Присваивает число к переменной
                }
                if(*(mas + i * col + j) > minmax && *(mas + i * col + j) >= 0)      // Находит самое большое которое больше или равно нулю
                {
                    minmax = *(mas + i * col + j);                                  // Присваивает число к переменной
                }
            }
        }
        for(int i = 0; i < row; i++)                                                // Находит максмин и минмакс
        {
            for(int j = 0; j < col; j++)
            {
                if((*(mas + i * col + j) > maxmin && *(mas + i * col + j) < 0) || *(mas + i * col + j) == maxmin)       // Находит максимальное число до нуля
                {
                    maxmin = *(mas + i * col + j);                                                                      // Присваивает число к переменной и запоминает координаты
                    co1 = i;
                    co2 = j;
                }
                if((*(mas + i * col + j) < minmax && *(mas + i * col + j) >= 0) || *(mas + i * col + j) == minmax)      // Находит минимальное число до отрицательных чисел
                {
                    minmax = *(mas + i * col + j);                                                                      // Присваивает число к переменной и запоминает координаты
                    co3 = i;
                    co4 = j;
                }
            }
        }
        if(minmax < 0 || maxmin >= 0)                                               // Если какое то из переменных не верно
        {
            printf("There is no minmax or maxmin\n");                               // То тут нет максмин и минмакс
        }
        else                                                                        // В другом случае
        {
            t = *(mas +co1 * col + co2);                                            // Максмин и минмакс меняется местами
            *(mas + co1 * col + co2) = *(mas + co3 * col + co4);
            *(mas + co3 * col + co4) = t;
            for(int i = 0; i < row; i++)                                            // Цикл вывода массива
            {
                for(int j = 0; j < col; j++)
                {
                    printf("%d\t", *(mas + i * col + j));                           // Выводит массив
                }
                printf("\n");                                                       // Переход на новую линию
            }
            printf("\n");
        }
        printf("Maxmin: %d\nMinmax: %d\n", maxmin, minmax);                         // Вывод максмин и минмакс
        printf("Do you want to repeat the program?\n1. Yes\n2. No\nAnswer: ");      // Вывод повтора программы да/нет
        scanf_s("%d", &x);                                                          // Если 1
    } while (x == 1);                                                           // То повторяем
    return 0;
}