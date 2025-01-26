#include <stdio.h>

int main()
{
    unsigned int N, res = 0; 
    scanf("%d", &N);

    for(int i = 0; i < 32; i++)
    {
        if((N >> i) & 1 == 1)
            res++;  
    } 
    printf("%d", res);   
    return 0;
}