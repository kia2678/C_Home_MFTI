#include <stdio.h>
int main()
{
    int a, b, c = 0; 
    scanf("%d %d", &a, &b);
    for (int i = a; i <= b; i++)
    {
        c += i*i;
    }
    printf("%d ", c);
    return 0;
}