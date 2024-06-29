#include <stdio.h>
int main()
{
    int a, b, c, d[10] = {0}; 
    scanf("%d", &a);
     for(b = 0, c = 1;; c*=10 , b++)
    {
        d[b] = (a/c)%10;
        if(a/c == 0)  break;     
    }
    a = 0;
    for(c = 1; b > 0; c*=10 , b--)
    {
        a += d[b-1] *c;
    }
    printf("%d", a);
    return 0;
}