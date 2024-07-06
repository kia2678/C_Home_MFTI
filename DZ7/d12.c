#include <stdio.h>
void d_12(int n, int s);

int main()
{
    int a, s = 1;
    scanf("%d", &a);
    d_12(a, s);

    return 0;
}


void d_12(int n, int s)
{ 
    static int caunter = 1;  
    for(int i = 1; i <= s; ++i, ++caunter)
    {
        if(caunter <= n)  printf("%d ", s);
    }
    s++;
    if(caunter <= n) d_12(n, s);
}