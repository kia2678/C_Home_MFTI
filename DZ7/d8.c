#include <stdio.h>
void print_a_b(int n1, int n2);

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    print_a_b(a, b);

    return 0;
}


void print_a_b(int n1, int n2)
{
    if(n1 == n2) printf("%d ", n1);

    if(n1 > n2) printf("%d ", n1);

    if(n1 > n2) print_a_b(n1 -1, n2 );
    if(n1 < n2) print_a_b(n1, n2 - 1);

    if(n1 < n2) printf("%d ", n2);
    
    return;
}