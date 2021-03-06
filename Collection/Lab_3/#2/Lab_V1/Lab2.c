// В введеной матрице производится сортировка пузырьком построчно(через константу) по возрастанию

#include <stdio.h>
// #include <iostream>
#define N 3                                         // Размер матрицы N на N(Матрица 5 на 5)

int main()
{
    int mm[N] [N];                                  // Размер матрицы N на N
    int t,x;                                          // Для временной переменной(свап)
    do
    {
        // system("CLS");
        for(int i = 0; i < N; i++)                          // Весь цикл чтобы вписать цифры в матрицу (Цикл, чтобы вписать N чисел в линию)
        {
            for(int j = 0; j < N; j++)                          // Цикл для ввода цифр в N линий
            {
                printf("Write a number: ");                       // Вывод сообщения (впишите число)
                scanf("%d", &mm[i][j]);                           // Присваивание числа к массиву i(номер строчки) и к j(цифры в строчке)
            }
        }
        for(int i = 0; i < N; i++)                          // Весь цикл выводит матрицу (Цикл вывода - i номер строчки)
        {
            for(int j = 0; j < N; j++)                          // Цикл вывода чисел j в строке i  
            {
                printf("%d\t",mm[i][j]);                            // Выводит цифры j в строчке i из массива mm(\t делает 4 пробела между цифрами)
            }
            printf("\n");                                       // Для перехода на новую строчку
        }
        for(int i = 0; i < N; i++)                          // Весь цикл делает сортировку методом пузырька (Цикл линии)
        {
            for(int k = 0; k < N; k++)                      // Цикл повторного сканирования линии(проверка)
            {
                for(int j = 1 + k; j < N; j++)                  // Цикл сканирования линии
                {
                    if(mm[i][k] > mm[i][j])                         // Условие свапа чисел
                    {
                        t = mm[i][k];                                   // Загоняем в переменную
                        mm[i][k] = mm[i][j];                            // Свап
                        mm[i][j] = t;                                   // Возращаем предыдущее значение в следуйщее
                    }
                }
            }
        }
        printf("\n");
        for(int i = 0; i < N; i++)                          // Весь цикл выводит матрицу (Цикл вывода - i номер строчки)
        {
            for(int j = 0; j < N; j++)                          // Цикл вывода чисел j в строке i  
            {
                printf("%d\t",mm[i][j]);                            // Выводит цифры j в строчке i из массива mm(\t делает 4 пробела между цифрами)
            }
            printf("\n");                                       // Для перехода на новую строчку
        }
        printf("Repeat program? \n1. Yes \n2. No\n");
        printf("Answer: ");
        scanf("%d", &x);
    } while (x == 1);     
    return 0;
}