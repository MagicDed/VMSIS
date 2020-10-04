// В введеной матрице производится сортировка пузырьком построчно(через константу)

#include <stdio.h>
#define N 5                                         // Размер матрицы N на N(Матрица 5 на 5)

int main()
{
    int mm[N] [N];                                  // Размер матрицы N на N
    int t;                                          // Для временной переменной(свап) 
    for(int i = 0; i < N; i++)                          // Весь цикл чтобы вписать цифры в матрицу (Цикл, чтобы вписать N чисел в линию)
    {
        for(int j = 0; j < N; j++)                          // Цикл для ввода цифр в N линий
        {
            printf("Write a number: ");                         // Вывод сообщения (впишите число)
            scanf_s("%d", &mm[i][j]);                           // Присваивание числа к массиву i(номер строчки) и к j(цифры в строчке)
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
        for(int k = 0; k < N - 1; k++)                      // Цикл повторного сканирования линии(проверка)
        {
            for(int j = 0; j < N - 1 - k; j++)                  // Цикл сканирования линии
            {
                if(mm[i][j] > mm[i][j + 1])                         // Условие свапа чисел
                {
                    t = mm[i][j];                                       // Загоняем в переменную
                    mm[i][j] = mm[i][j + 1];                            // Свап
                    mm[i][j + 1] = t;                                   // Возращаем предыдущее значение в следуйщее
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
    return 0;
}