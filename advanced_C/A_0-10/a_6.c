#include <stdio.h>

int main()
{
    unsigned int N, nk; 
    scanf("%d", &N);
    nk = ~N;
    nk >>= 24;
    N <<= 8;
    N >>= 8;
    N |= (nk << 24);

    printf("%u", N);   
    return 0;
}