#include <stdio.h>
#include <inttypes.h>

int main()
{
    uint16_t a, b, c, d; 
    scanf("%d", &d);
    a = d  / 100;
    b = (d % 100) / 10;
    c = d % 10;
    printf("%d\n", (a > b)? ((a > c)? a : c) : ((b > c)? b : c));
    return 0;
}