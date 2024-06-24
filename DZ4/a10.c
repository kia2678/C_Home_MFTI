#include <stdio.h>

int main()
{
    int a, b, c, d, e, rez; 
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    rez = (a < b)? ((a < c)? a : c) : ((b < c)? b : c);
    rez = (rez < d)? ((rez < e)? rez : e) : ((d < e)? d : e);
    printf("%d\n", rez);
    return 0;
}