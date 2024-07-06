#include <stdio.h>
int sum_1_n(int n);

int main()
{
    int a;
    scanf("%d", &a);
    printf("%d\n", sum_1_n(a));

    return 0;
}


int sum_1_n(int n)
{
    if( n > 1)
    {
        return n += sum_1_n(n - 1);
    }   
}