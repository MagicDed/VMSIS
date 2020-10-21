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
    for(int i = 0; i < N; i++)
    {
        for(int j = 1 + i; j < N; j++)
        {
            if(mm[i] > mm[j]) 
            {
                t = mm[i];
                mm[i] = mm[j];
                mm[j] = t;
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