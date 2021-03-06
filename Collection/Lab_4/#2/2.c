// В матрице найти найти минимальное число на четном месте

#include <stdio.h>
#include <stdlib.h>
// #include <iostream>                  // Для VS

int main()
{
    int x, row, col;                                            // Для повторения проги(x) Колво линий(row) Колво столбцов(col)
    int min;                                                    // Минимальное
    int co1, co2;                                               // Координаты
    int *mas;                                                   // Указатель на матрицу
    do
    {
        // system("CLS");                                                       // Для VS
        printf("How many lines? ");
        scanf_s("%d", &row);
        printf("how many numbers in the line? ");
        scanf_s("%d", &col);
        mas = (int*)malloc(row * col * sizeof(int));                            // Выделение памяти под строчки  
        for(int i = 0; i < row; i++)                                            // Цикл для ввода цифр в матрицу
        {
            for(int j = 0; j < col; j++)
            {
                printf("Write a number: ");                                         // Вывод надписи(введите число)
                scanf_s("%d", &mas[i * col + j]);                                   // Присваивание числа к матрице
            }
        }
        for(int i = 0; i < row; i++)                                            // Цикл для вывода матрицы
        {
            for(int j = 0; j < col; j++)
            {
                printf("%d\t", mas[i * col + j]);                                       // Выводит матрицу 
            }
            printf("\n");
        }
        min = mas[1];
        for(int i = 0; i < row; i++)                                            // Цикл находит максимальное на четном месте
        {
            for(int j = 1; j < col; j += 2)
            {
                if(min < mas[i * col + j])                                               // Если число больше мин то
                {
                    min = mas[i * col + j];                                                 // Оно новое мин
                }
            }
        }
        for(int i = 0; i < row; i++)                                            // Цикл находит минимальное число на четном месте
        {
            for(int j = 1; j < col; j = j + 2)
            {
                if(mas[i * col + j] < min && mas[i * col + j] >= 0)                     // Если число меньше минимального и больше нуля то
                {
                    min = mas[i * col + j];                                                 // Это число новое мин
                    co1 = i + 1;
                    co2 = j + 1;
                }
            }
        }
        printf("Min: %d\n", min);
        printf("Row: %d\nCol: %d\n", co1, co2);
        printf("Do you want to repeat the program?\n1. Yes\n2. No\nAnswer: ");  // Повтор цикла
        scanf_s("%d", &x);                                                      // Присваивание числа
    } while (x == 1);                                                       // Если один то повтор проги
    return 0;
}