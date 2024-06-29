#include <stdio.h>
int main()
{
    int a, b = 0, c = 1; 
    scanf("%d", &a);
    while (1)
    {
    if(a/c == 0) break;
    b += (a/c)%10;
    c *= 10;
    }
    printf("%d\n", b);
    return 0;
}