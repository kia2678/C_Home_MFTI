#include <stdio.h>
int max_find(int max);

int main ()
{
    int a;
    scanf("%d", &a);
    if(a == 0) return 0;
    printf("%d", max_find(a));
    return 0;
}


int max_find(int max)
{
    int a, b = -2147483648;
    scanf("%d", &a);
    if(a != 0)  b = max_find(a);
    return (max > b)?  max  :  b;
}
