#include <stdio.h>
#define N 4                                         // Размер матрицы N на N(Матрица 5 на 5)

int main()
{
    int mm[N] [N];                                  // Размер матрицы N на N
    int t, max;
    int line = 0;
    int num = 0;                                         // Для временной переменной(свап) 
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
    max = mm[0][0];
    for(int i = N - 1; i == 0; i--)
    {
        for(int j = N - 1; j == 0; j--)
        {
            if(max < mm[i][j])
            {
                max = mm[i][j];
                line = i + 1;
                num = j + 1;
            }
        }
    }
    for(int i = 1; i < N; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(max < mm[i][j])
            {
                max = mm[i][j];
                line = i + 1;
                num = j + 1;
            }
        }
    }
    printf("Max: %d\n", max);
    printf("Line: %d\nNumber: %d", line, num);
    return 0;
}