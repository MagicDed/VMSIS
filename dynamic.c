#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	int *ptr;
	printf("Write a size of array: ");
	scanf_s("%d", &n);
	ptr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		printf("Write a number: ", i);
		scanf_s("%d", &ptr[i]);
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", ptr[i]);
	}
	return 0;
}