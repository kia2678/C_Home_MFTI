#include <stdio.h>

int main()
{
    int a, b, c, d, e, min, max; 
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

    min = (a < b)? ((a < c)? a : c) : ((b < c)? b : c);
    min = (min < d)? ((min < e)? min : e) : ((d < e)? d : e);

    max = (a > b)? ((a > c)? a : c) : ((b > c)? b : c);
    max = (max > d)? ((max > e)? max : e) : ((d > e)? d : e);

    printf("%d\n", min + max);
    return 0;
}