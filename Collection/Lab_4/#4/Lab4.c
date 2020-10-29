// Матрица с динамическим массивом в которой нужно отсортировать числа по убыванию, но оставлять отрицательные числа на своих местах

#include <stdio.h>
#include <stdlib.h>
// #include <iostream>          // Для VS

int main()
{
    
	int row, col, x, t;                                     // Переменные кол-ва строчек(row), колонок(col), повтора кода(x), временная(t) 
	int *ptr;                                              // Двухмерный массив, а точнее его указатель
    do                                                      // Цикл повторять прогу пока мы хотим
    {
        // system("CLS");                                           // Для VS
        printf("How many lines? ");
	    scanf_s("%d", &row);
        printf("How many numbers in the line? ");
        scanf_s("%d", &col);
	    ptr = (int*)malloc(row * col * sizeof(int));                // Выделение памяти для строчек 
	    for (int i = 0; i < row; i++)                               // Цикл чтобы вписать цифры в матрицу
        {
            for(int j = 0; j < col; j++)
            {
                printf("Write a number: ");                             // Выводит сообщение чтобы ввели число
	    	    scanf_s("%d", &ptr[i * col + j]);                       // Присваивает это число к значению ptr[i * col + j]
            }
        }
        for (int i = 0; i < row; i++)                               // Цикл чтобы вывести матрицу
        {
            for(int j = 0; j < col; j++)
            {
                printf("%d\t", ptr[i * col + j]);                           // Рисует матрицу
            }
            printf("\n");
        }
        printf("\n");                                               // Отступ между выведиными матрицами
        for(int i = 0; i < row; i++)                                // Цикл сортировки матрицы
        {
            for(int k = 0; k < col; k++)                                // Цикл для сортировки пузырьком
            {
                for(int j = 1 + k; j < col; j++)                            // Начало отсчета от 1 + k
                {
                    if(ptr[i * col + k] < 0)                                    // Если число отрицательное то
                    {
                        do                                                          // Пропускать это число пока не найдется положительное
                        {
                            k += 1;                                                     // Сам пропуск
                            j += 1;                                                     // Сам пропуск
                        } while(ptr[i * col + k] < 0);
                    }
                    if(ptr[i * col + k] < ptr[i * col + j])                     // Если k число меньше j то 
                    {
                        t = ptr[i * col + k];                                       // Мы запоминаем k
                        ptr[i * col + k] = ptr[i * col + j];                        // Вместо него вписывает j
                        ptr[i * col + j] = t;                                       // Вместо j ставим k
                    }
                }
            }
        }
        for (int i = 0; i < row; i++)                               // Вывод матрицы
        {
            for(int j = 0; j < col; j++)
            {
                printf("%d\t", ptr[i * col + j]);                           // Рисует матрицу
            }
            printf("\n");
        }
        printf("Repeat program? \n1. Yes \n2. No\n");               // Вывод сообщения (Повторить программу да/нет)
        printf("Answer: ");                                         // Вывод сообщения (Ответ)
        scanf("%d", &x);                                            // Присваивание введеного числа к x 
    } while (x == 1);                                           // Если это 1 то повторяем программу
    return 0;
}