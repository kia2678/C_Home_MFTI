#include <stdio.h>

int main()
{
    unsigned int N, K, mask = 0; 
    scanf("%d %d", &N, &K);

    for(int i = 0; i <K; i++)
    {
       mask <<= 1;
       mask |= 1;
    } 
    printf("%d", N & mask);   
    return 0;
}