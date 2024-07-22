#include <stdio.h>
int sum_d(int *d, int size, int del);

int main()
{
    int d[25];
    for(int i = 0; i < 25; i++)
             scanf("%d", &d[i]);
    
    printf("%d", sum_d(d, 25, 5));

    return 0;
}



int sum_d(int *d, int size, int del)
{
    int sum = 0;
    for(int i = 0; i < size / del; i++)
            sum += d[i * 5 + i];
    return sum;
}