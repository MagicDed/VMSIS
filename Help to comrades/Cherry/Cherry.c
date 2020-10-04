// В введеном массиве ищется наибольшее произведение соседних чисел и выводится место где оно

#include <stdio.h>

int main()
{
    int m[10];                                          // Массив
    int b = 0;                                          // Переменная для большего произведения
    int slot = 0;                                       // Переменная для его позиции
    for (int i = 0; i < 10; i++)                                // Цикл для ввода чисел в массив
    {
        printf("Write a number: ");                                 // Вывод текста (напишите число)
        scanf_s("%d", &m[i]);                                       // Присваиваешь число к массиву
    }
    for (int i = 0; i < 10; i++)                                // Цикл для нахождения большего произведения и его позиции
    {
        if((m[i - 1]*m[i]) > b)                                     // Если предыдущее число умноженое на текущее больше чем b, то 
        {
            b = (m[i - 1]*m[i]);                                        // Записывается большее произведение в b
            slot = i;                                                   // Записывается его позиция в массиве в slot
        }
    } 
    printf("Array: ");                                          // Выводит текст (Массив: )
    for(int i = 0; i < 10; i++)                                 // Цикл для вывода массива
    {
        printf("%d ", m[i]);                                        // Вывод массива
    }
    printf("\nBiggest product of a number: %d\n", b);           // Вывод большего числа, которое b
    printf("Slot: %d", slot);                                   // Вывод его позиции, которое slot
    return 0;
}