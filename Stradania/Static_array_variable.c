// Статичный массив с возможностью выбора вывода линий и столбцов
// Легко сломать если будешь вводить кол-во линий/столбцов больше чем в массиве



#include <stdio.h>

int main()
{
    int mm[10] [10];                                    //величина двухмерного массива 10 строчек, 10 столбцов(aka цифр в строчке) 
    int row, col;                                       //переменныедля количества строчек и столбцов
    printf("How many lines? ");                             //вывод сообщения (сколько строчек должно быть в массиве)
    scanf_s("%d", &row);                                    //присваивание числа к row (кол-во строчек)
    printf("How many collums? ");                           //вывод сообщения (сколько столбцов должно быть в массиве)
    scanf_s("%d", &col);                                    //присваивание числа к col (кол-во столбцов)
    for(int i = 0; i < row; i++)                            //цикл, чтобы вписать col чисел в линию
    {
        for(int j = 0; j < col; j++)                            //цикл для ввода цифр и row линий
        {
            printf("Write a number: ");                             //вывод сообщения (впишите число)
            scanf_s("%d", &mm[i] [j]);                              //присваивание числа к массиву i(номер строчки) и к j(цифры в строчке)
        }
    }
    for(int i = 0; i < row; i++)                            //цикл вывода - i номер строчки
    {
        for(int j = 0; j < col; j++)                            //цикл вывода чисел j в строке i  
        {
            printf("%d\t",mm[i][j]);                                //выводит цифры j в строчке i из массива mm(\t делает 4 пробела между цифрами)
        }
        printf("\n");                                           //для перехода на новую строчку
    }
    return 0;
}