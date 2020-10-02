#include <stdio.h>

int main();
{
    m[10];
    int num;
    int n;
    int sum;
    for (int i = 0; i < 10; i++)       //цикл для ввода цифр в первый массив
	{
		printf("Write a number: ");    //ввод числа
		scanf_s("%d", &m[i]);         //ввод цифр в массив
	}
    for (int i = 0; i < 10; i++)
    {
        if(m[i-1]*m[i] > m[i-1]*m[i-2]
        {
            num = i;
            n = i-1;
        }
    }

    	for (int i = 0; i < 10; i++)       //цикл для вывода
	{
		printf("%d ", m[i]);           //вывод второго массива
	}
    sum = n * num;
    printf("Mult %d\n", sum);
}
