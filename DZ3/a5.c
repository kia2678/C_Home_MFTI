#include <stdio.h>

int main()
{
    int a, b, c;
    float d;
    scanf("%d %d %d", &a, &b, &c);
    d = (a + b + c)/3.;

    printf("%.2f\n", d);
    

    return 0;
}