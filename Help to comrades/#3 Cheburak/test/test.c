#include<stdio.h>

#define N 5
int main ()
{
    int mm[N];
    int i, k, j, f;
    for(i = 0; i < N; i++)
    {
        printf("Write numbers: ");
        scanf("%d",&mm[i]);
    }
    for(i = 0; i < N; i++)
    {
        printf("%d ",mm[i]);
    }
    for(int i = 0; i < N; i++)
        {
            for(int j = 1 + i; j < N; j++)
            {
                if(mm[i] < mm[j])
                {
                    k = mm[i];
                    mm[i] = mm[j];
                    mm[j] = k;
                }
            }
        }
    printf("\n");
    for(i = 0; i < N; i++)
    {
        printf("%d ",mm[i]);
    }
    return 0;
}