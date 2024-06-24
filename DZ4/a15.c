#include <stdio.h>

int main()
{
    int x1, x2, y1, y2;
    float k, b; 
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    k = (y1 - y2) / (float)(x1 - x2);
    b = y2 - k*x2;

    printf("%.2f %.2f\n", k, b);
    return 0;
}