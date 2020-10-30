// Матрица с динамическим массивом в которой нужно отсортировать числа по убыванию в столбце, но оставлять положительные числа на своих местах

#include <stdio.h>
#include <stdlib.h>
// #include <iostream>          // Для VS

int main()
{
    
	int row, col, x, t;                                      // Переменные кол-ва строчек(row), колонок(col), повтора кода(x), временная(t) 
	int *mas;                                                // Двухмерный массив, а точнее его указатель
    do                                                       // Цикл повторять прогу пока мы хотим
    {
        // system("CLS");                                           // Для VS
        printf("How many lines? ");
	    scanf_s("%d", &row);
        printf("How many numbers in the line? ");
        scanf_s("%d", &col);
	    mas = (int*)malloc(row * col * sizeof(int));              // Выделение памяти для строчек 
	    for (int i = 0; i < row; i++)                             // Цикл чтобы вписать цифры в матрицу
        {
            for(int j = 0; j < col; j++)
            {
                printf("Write a number: ");                             // Выводит сообщение чтобы ввели число
	    	    scanf_s("%d", &mas[i * col + j]);                       // Присваивает это число к значению mas[i * col + j]
            }
        }
        for (int i = 0; i < row; i++)                               // Цикл чтобы вывести матрицу
        {
            for(int j = 0; j < col; j++)
            {
                printf("%d\t", mas[i * col + j]);                           // Рисует матрицу
            }
            printf("\n");
        }
        printf("\n");                                               // Отступ между выведиными матрицами
        for(int j = 0; j < col; j++)
        {
            for(int k = 0; k < row; k++)                                // Первое число для пузырька
            {
                for(int i = 1 + k; i < row; i++)                            // Второе число для пузырька
                {
                    if(mas[k * col + j] > 0)                                    // Если число больше нуля
                    {
                        do                                                          // Происходит скип до тех пор пока не будет отрецательное
                        {
                            k += 1;
                            i += 1;
                        } while(mas[k * col + j] > 0 && i < row);                        
                    }
                    if(mas[k * col + j] < 0 && mas[i * col + j] < 0)            // Если число меньше нуля
                    {
                        if(mas[k * col + j] < mas[i * col + j])                     // Если первое число больше второго
                        {
                            t = mas[k * col + j];                                       // Первое число запоминаем
                            mas[k * col + j] = mas[i * col + j];                        // На его место пишем второе число
                            mas[i * col + j] = t;                                       // Вместо второго пишем первое
                        }
                    }
                }
            }
        }
        for (int i = 0; i < row; i++)                               // Вывод матрицы
        {
            for(int j = 0; j < col; j++)
            {
                printf("%d\t", mas[i * col + j]);                           // Рисует матрицу
            }
            printf("\n");
        }
        printf("Repeat program? \n1. Yes \n2. No\n");               // Вывод сообщения (Повторить программу да/нет)
        printf("Answer: ");                                         // Вывод сообщения (Ответ)
        scanf_s("%d", &x);                                            // Присваивание введеного числа к x 
    } while (x == 1);                                           // Если это 1 то повторяем программу
    return 0;
}