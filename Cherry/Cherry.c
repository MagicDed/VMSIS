#include <stdio.h>

int main()
{
     int m[10];
     int b = 0;                                                 //переменная для большего произведения
     int index = 0;                                             //переменная для его позиции
    for (int i = 0; i < 10; i++)                                //цикл для ввода чисел в массив
    {
        printf("Write a number: ");                                  //пишешь число
        scanf_s("%d", &m[i]);                                        //присваиваешь число к массиву
    }
    for (int i = 0; i < 10; i++)                                //цикл для нахождения большего произведения и его позиции
    {
        if((m[i - 1]*m[i]) > b)                                      //если предыдущее число умноженое на текущее больше чем b, то 
        {
            b = (m[i - 1]*m[i]);                                          //записывается большее произведение
            index = i;                                                    //его позиция в массиве
        }
    } 
    printf("Array: ");
    for(int i = 0; i < 10; i++)                                 //цикл для вывода массива
    {
        printf("%d ", m[i]);                                         //вывод массива
    }
    printf("\n Biggest product of a number: %d", b);            //вывод большего числа, которое b
    printf("\n Slot: %d", index);                               //вывод его позиции, которое index
    return 0;
}