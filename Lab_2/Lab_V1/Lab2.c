#include <stdio.h>
#define N 5

int main()
{
    int mm[N] [N];                                  //величина двухмерного массива N на N
    int t;
    for(int i = 0; i < N; i++)                          //цикл, чтобы вписать N чисел в линию
    {
        for(int j = 0; j < N; j++)                          //цикл для ввода цифр в N линий
        {
            printf("Write a number: ");                         //вывод сообщения (впишите число)
            scanf_s("%d", &mm[i][j]);                           //присваивание числа к массиву i(номер строчки) и к j(цифры в строчке)
        }
    }
    for(int i = 0; i < N; i++)                          //цикл вывода - i номер строчки
    {
        for(int j = 0; j < N; j++)                          //цикл вывода чисел j в строке i  
        {
            printf("%d\t",mm[i][j]);                            //выводит цифры j в строчке i из массива mm(\t делает 4 пробела между цифрами)
        }
        printf("\n");                                       //для перехода на новую строчку
    }
    for(int i = 0; i < N; i++)                          //цикл линии
    {
        for(int k = 0; k < N - 1; k++)                      //цикл повторного сканирования линии(проверка)
        {
            for(int j = 0; j < N - 1 - k; j++)                  //цикл сканирования линии
            {
                if(mm[i][j] > mm[i][j + 1])                         //условие свапа чисел
                {
                    t = mm[i][j];                                       //загоняем в переменную
                    mm[i][j] = mm[i][j + 1];                            //свап
                    mm[i][j + 1] = t;                                   //возращаем предыдущее значение в следуйщее
                }
            }
        }
    }
    printf("\n");
    for(int i = 0; i < N; i++)                          //цикл вывода - i номер строчки
    {
        for(int j = 0; j < N; j++)                          //цикл вывода чисел j в строке i  
        {
            printf("%d\t",mm[i][j]);                            //выводит цифры j в строчке i из массива mm(\t делает 4 пробела между цифрами)
        }
        printf("\n");                                       //для перехода на новую строчку
    }
    return 0;
}