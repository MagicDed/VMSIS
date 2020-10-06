#include <stdio.h>
#define N 5                                         // Число в массиве
#define D 2                                         // Кол-во значений которое нужно удалить

int main()
{
    int m[N];                                   // Массив с размером N
    int min, t;                                 // Переменная для минимального числа(min) и для временного числа(t)
    int slot = 0;                               // Переменная для записи места минимального числа
    for(int i = 0; i < N; i++)                      // Цикл для ввода цифр в массив
    {
        printf("Write a number: ");                     // Выводит текст
        scanf_s("%d", &m[i]);                           // Записывает число в массив
    }
    for(int d = 0; d < D; d++)                      // Цикл который удаляет 5 наименьших чисел
    {
        min = m[0 + d];                                 // Первое число массива и есть наименьшее
        slot = 0;                                       // Обнулиение слота против багов
        for(int i = 1 + d; i < N; i++)                  // Стартуем со второго числа
        {
            if(min > m[i])                                  // Сравниваем их
            {
                min = m[i];                                     // Если min больше какого то числа во всем массиве, то оно будет новым min
                slot = i;
            }
        }
        min = 0;                                        // Минимальное приравниваем к нулю
        t = m[0 + d];                                   // Записываем первое число массива во временную переменную
        m[0 + d] = min;                                 // Вместо него вписываем минимальное
        m[slot] = t;                                    // Вместо минимального на его изначальном месте записываем временную
    }
    printf("\n");
    for(int i = D; i < N; i++)                      // Цикл начинается после первых D чисел
    {
        printf("%d ", m[i]);                            // Рисуем массив
    }
    return 0;
}