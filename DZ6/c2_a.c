#include <stdio.h>

int power(int* n, int* p);

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", power(&a, &b));
    return 0;
}

int power(int* n, int* p)
{
    int res = (*p < 0)?  0  :  1;
    for(int i = 0; i < *p;  i++) res *= *n;

    return res;
}