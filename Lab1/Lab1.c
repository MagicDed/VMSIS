#include <stdio.h>

int main()
{
	int ms[10];                        //первый массив
	int m[10];                         //второй массив
	for (int i = 0; i < 10; i++)       //цикл для ввода цифр в первый массив
	{
		printf("Write a number: ");    //ввод числа
		scanf_s("%d", &ms[i]);         //ввод цифр в массив
	}
	for (int i = 0; i < 10; i++)       //цикл для записи значений во второй массив
	{
		m[i] = ms[9 - i];              //запись массива во второй начиная с конца второго
	}
	printf("Flipped array: ");         //перевернутый массив
	for (int i = 0; i < 10; i++)       //цикл для вывода
	{
		printf("%d ", m[i]);           //вывод второго массива
	}
	return 0;
}