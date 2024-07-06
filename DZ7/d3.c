#include <stdio.h>
void back(int n);

int main()
{
    int a;
    scanf("%d", &a);
    back(a);
    return 0;
}


void back(int n)
{
    int s = n % 10;
    printf("%d ", s);
    n /=10;
    if( n !=0 )  back(n);
    return;
}