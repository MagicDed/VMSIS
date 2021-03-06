// Введеный массив выводится, записывается задом наперед и выводится его новый вариант(через массив и переменную)

#include <stdio.h>

int main()
{
	int ms[10];                        // Массив
	int t;                             // Переменная для временных значений
	for (int i = 0; i < 10; i++)       // Цикл для ввода цифр в первый массив
	{
		printf("Write a number: ");    // Вывод текста (напишите число)
		scanf_s("%d", &ms[i]);         // Ввод цифр в массив
	}
	printf("Array: ");
	for (int i = 0; i < 10; i++)       // Цикл для вывода массива
	{
		printf("%-4d", ms[i]);         // Вывод первого массива(не перевернутого)
	}
	for (int i = 0; i < 5; i++)        // Цикл для записи значений во второй массив
	{
		t = ms[i];                     // Запись i числа в временную переменную
		ms[i] = ms[9-i];               // Запись последнего(предпоследнего итд) числа в i 
		ms[9-i] = t;                   // Запись временного значения(i) вместо последнего(предпоследнего итд)
	}
	printf("\nFlipped array: ");       // Выводит текст (перевернутый массив)
	for (int i = 0; i < 10; i++)       // Цикл для вывода массива
	{
		printf("%-4d", ms[i]);         // Вывод второго массива(перевернутый)
	}
	return 0;
}