#include <stdio.h>
void print_1_n(int n);

int main()
{
    int a;
    scanf("%d", &a);
    print_1_n(a);

    return 0;
}


void print_1_n(int n)
{
    printf("%d ", n);
    if( n > 1) print_1_n(n - 1);
    return;
}