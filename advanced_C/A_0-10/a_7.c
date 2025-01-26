#include <stdio.h>

int main()
{
    int N, a, res = 0; 
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &a);
        res ^= a;
    }
    printf("%d", res);   
    return 0;
}