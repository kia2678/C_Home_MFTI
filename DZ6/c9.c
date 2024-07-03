#include <stdio.h>
long long int factorial(int n);

int main()
{
    int a;
    scanf("%d", &a);
    printf("%llu\n", factorial(a));
    return 0;
}

long long int factorial(int n)
{
    int res = 1;
    for(int i = 1; i <= n; i++)
    {
        res *= i;
    } 
    return res;
}