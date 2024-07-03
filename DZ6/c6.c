#include <stdio.h>

  long long int corn( int z);

int main()
{
    int a;
    scanf("%d", &a);
    printf("%llu\n", corn(a));
    return 0;
}

long long int corn(int z)
{
    long long int res = 1;
    for(int i = 1; i < z; i++)
    {
        res *= 2;
    } 
    return res;
}