#include <stdio.h>

int main()
{
    unsigned int N, K, res = 0, mask = 0; 
    scanf("%d %d", &N, &K);
    
    for(int i = 0; i < K; i++)
        mask |= (1<<i);

    for(int i = 32 - K; i >= 0; i--)
    {
        int S = (N >> i) & mask;
        if(S > res)
            res = S;       
    }
    printf("%d", res);   
    return 0;
}