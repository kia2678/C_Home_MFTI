#include <stdio.h>
#include <math.h>

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
    return pow(*n, *p);
}