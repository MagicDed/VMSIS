// Матрица с динамическим массивом в которой нужно отсортировать числа по убыванию, но оставлять отрицательные числа на своих местах

#include <stdio.h>
#include <stdlib.h>
// #include <iostream>          // Для VS

int main()
{
    
	int row, col, x, t;                                     // Переменные кол-ва строчек(row), колонок(col), повтора кода(x), временная(t) 
	int **mas;                                              // Двухмерный массив, а точнее его указатель
    do                                                      // Цикл повторять прогу пока мы хотим
    {
        // system("CLS");                                           // Для VS
        printf("How many lines? ");
	    scanf_s("%d", &row);
        printf("How many numbers in the line? ");
        scanf_s("%d", &col);
	    mas = (int**)malloc(row * sizeof(int*));                    // Выделение памяти для строчек 
        for(int i = 0; i < row; i++)
        {
            mas[i] = (int*)malloc(col * sizeof(int));                   // Выделение памяти для столбцов
        }
	    for (int i = 0; i < row; i++)                               // Цикл чтобы вписать цифры в матрицу
        {
            for(int j = 0; j < col; j++)
            {
                printf("Write a number: ");                             // Выводит сообщение чтобы ввели число
	    	    scanf_s("%d", &mas[i][j]);                              // Присваивает это число к значению mas[i][j]
            }
        }
        for (int i = 0; i < row; i++)                               // Цикл чтобы вывести матрицу
        {
            for(int j = 0; j < col; j++)
            {
                printf("%d\t", mas[i][j]);                                  // Рисует матрицу
            }
            printf("\n");
        }
        printf("\n");                                               // Отступ между выведиными матрицами
        for(int j = 0; j < col; j++)
        {
            for(int k = 0; k < row; k++)
            {
                for(int i = 1 + k; i < row; i++)
                {
                    if(mas[k][j] > 0)
                    {
                        do
                        {
                            k = k + 1;
                            i = i + 1;
                        } while(mas[k][j] > 0 && i < row);                        
                    }
                    if(mas[k][j] < 0)
                    {
                        if(mas[k][j] > mas[i][j])
                        {
                            t = mas[k][j];
                            mas[k][j] = mas[i][j];
                            mas[i][j] = t;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < row; i++)                               // Вывод матрицы
        {
            for(int j = 0; j < col; j++)
            {
                printf("%d\t", mas[i][j]);                                  // Рисует матрицу
            }
            printf("\n");
        }
        printf("Repeat program? \n1. Yes \n2. No\n");               // Вывод сообщения (Повторить программу да/нет)
        printf("Answer: ");                                         // Вывод сообщения (Ответ)
        scanf("%d", &x);                                            // Присваивание введеного числа к x 
    } while (x == 1);                                           // Если это 1 то повторяем программу
    return 0;
}