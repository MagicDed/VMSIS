// Тест сортировки пузырьком

#include <stdio.h>
#define N 5

int main()
{
    int mm[N];
    int t;
    for(int i = 0; i < N; i++)
    {
        scanf_s("%d", &mm[i]);
    }
    for(int i = 0; i < N; i++)
    {
        printf("%d ", mm[i]);
    }
    for(int i = 0; i < N - 1; i++)
    {
        for(int j = 0 ; j < N - i - 1 ; j++)
        {
            if(mm[j] > mm[j+1]) 
            {
                t = mm[j];               
                mm[j] = mm[j + 1];
                mm[j + 1] = t; 
            }
        }  
    }
    printf("\n");
    for(int i = 0; i < N; i++)
    {
        printf("%d ", mm[i]);
    }
    return 0;
}