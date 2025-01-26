#include <stdio.h>

int main()
{
    unsigned int N, K; 
    scanf("%d %d", &N, &K);
    for(int i = 0; i <K; i++)
    {
        int flag = 0;
        if((N & 1) == 1)
            flag = 1;
        N >>= 1;
        if(flag)
        N |= 1<<31;
    } 
    printf("%u", N);   
    return 0;
}