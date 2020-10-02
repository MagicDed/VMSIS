#include <stdio.h>

int main()
{
     int m[10];
     int b = 0;
     int index = 0;
    for (int i = 0; i < 10; i++)
    {
        printf("Write a number: ");
        scanf_s("%d", &m[i]);
    }
    for (int i = 0; i < 10; i++)
    {
        if((m[i - 1]*m[i]) > b)
        {
            b = (m[i - 1]*m[i]);
            index = i;
        }
    } 
    printf("Array: ");
    for(int i = 0; i < 10; i++)
    {
        printf("%d ", m[i]);
    }
    printf("\n Biggest product of a number: %d", b);
    printf("\n Slot: %d", index); 
    return 0;
}



















/* int main();
{
    m[10];
    int num;
    int n;
    int sum;
    for (int i = 0; i < 10; i++)       
	{
		printf("Write a number: ");    
		scanf_s("%d", &m[i]);         
	}
    for (int i = 0; i < 10; i++)
    {
        if(m[i-1]*m[i] > m[i-1]*m[i-2]
        {
            num = i;
            n = i-1;
        }
    }

    	for (int i = 0; i < 10; i++)       
	{
		printf("%d ", m[i]);           
	}
    printf("Mult %d\n", sum);
} */ 
