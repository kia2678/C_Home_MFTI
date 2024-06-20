#include <stdio.h>

int main()
{
    unsigned short a;
    scanf("%d", &a);
    unsigned short b = a/100;
    unsigned short c = (a%100)/10;
    unsigned short d = a%10;
    printf("%d\n", b*c*d);
    return 0;
}