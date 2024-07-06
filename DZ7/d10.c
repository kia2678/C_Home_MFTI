#include <stdio.h>
int is_prime(int n, int delitel);

int main ()
{
    int a, b = 2;
    scanf("%d", &a);
    printf("%s\n", (is_prime(a, b) == 1)?  "YES"  :  "NO");
}


int is_prime(int n, int delitel)
{
    if(n == 1) return 0;
    if(n == 2) return 1;
    if(n % delitel == 0) return 0;
    if(n/2 > delitel) return (is_prime(n, delitel + 1) == 1)?  1  :  0;
    return 1;
}