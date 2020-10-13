// В веденной массиве исчется максимальное число на главной диагонали, а потом число ниже ее

#include <stdio.h>
#define N 4                                         // Размер матрицы N на N(Матрица 5 на 5)

int main()
{
    int mm[N] [N];                              // Размер матрицы N на N
    int t, max;                                 // Временная переменная и максимальное число
    int line = 0;                               // Координата линни
    int num = 0;                                // Координата столбца
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
    max = mm[0][0];                                     // Первое число массива и есть максимальное
    for(int i = 0; i < N; i++)                          // Два цикла для поиска числа на главной диагонали
    {
        for(int j = i; j == i; j++)
        {
            if(max < mm[i][j])                                   // Если какое то число больше максимального то
            {
                max = mm[i][j];                                     // Оно становитс максимальным
                line = i + 1;                                       // Записывается место линии
                num = j + 1;                                        // Записывается номер столбца
            }
        }
    }
    for(int i = 1; i < N; i++)                          // Два цикла которые исчут числа ниже главной диагонали
    {
        for(int j = 0; j < i; j++)
        {
            if(max < mm[i][j])                                  // Если какое то число больше максимального то
            {
                max = mm[i][j];                                     // Оно становитс максимальным
                line = i + 1;                                       // Записывается место линии
                num = j + 1;                                        // Записывается номер столбца
            }
        }
    }
    printf("Max: %d\n", max);                           // Вывод максимального числа
    printf("Line: %d\nNumber: %d", line, num);          // Вывод его координат
    return 0;
}