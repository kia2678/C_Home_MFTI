#include <stdio.h>
int parity(int n);

int main()
{
    int a;
    scanf("%d", &a);
    printf("%s\n", (parity(a) == 0)?  "YES"  :  "NO");
    return 0;
}

int parity(int n)
{
   int b = 0, c = 1; 
    
    while (1)
    {
    if(n/c == 0) break;
    b += (n/c)%10;
    c *= 10;
    }
    return (b % 2 == 0)?  0  :  1;
}