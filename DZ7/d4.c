#include <stdio.h>
void order(int n);

int main()
{
    int a;
    scanf("%d", &a);
    order(a);
    return 0;
}


void order(int n)
{
    if(n /10 != 0)  order(n /10);
    printf("%d ", n % 10); 
    return;
}