#include <stdio.h>
int count_bigger_abs(int n, int a[]);

int main ()
{
    int d[10];
    for(int i = 0; i < 10; i++)
             scanf("%d", &d[i]);
    printf("%d", count_bigger_abs(10, d));
    return 0;
}


int count_bigger_abs(int n, int a[])
{
    int max = a[0];
    for(int i = 1; i < n; i++)
    {
        if(a[i] > max)
                max = a[i];
    }
    int counter =0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] * -1 > max)
                counter++;
    }
    return counter;
}