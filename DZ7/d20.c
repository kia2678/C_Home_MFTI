#include <stdio.h>
long long int recurs_power(int n, int p);

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%lld", recurs_power(a, b));
    return 0;
}


long long int recurs_power(int n, int p)
{
    if(p == 0) return 1;
    static long long int res = 1;
    if(p > 1) recurs_power(n, p -1);
    res *= n;
    return res;
}