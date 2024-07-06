#include <stdio.h>
int is2pow(int n);

int main ()
{
    int a;
    scanf("%d", &a);
    printf("%s\n", (is2pow(a))?  "YES"  :  "NO");

    return 0;
}



int is2pow(int n)
{
    if(n == 1) return 1;
    if(n % 2  == 1) return 0;

    int s = 1;
    if(n > 2) s = is2pow(n /2);
    
    return s;
}