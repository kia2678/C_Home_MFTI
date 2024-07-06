#include <stdio.h>
void print_digits(int n);

int main ()
{
    int a;
    scanf("%d", &a);
    print_digits(a);

    return 0;
}


void print_digits(int n)
{
    if(n / 10 != 0) print_digits(n / 10);
    printf("%d ", n % 10);

}
