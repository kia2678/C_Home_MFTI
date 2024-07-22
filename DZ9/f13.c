#include <stdio.h>

int count_between(int from, int to, int size, int a[]);

int main()
{
    int d[10];
    for(int i = 0; i < 10; i++)
             scanf("%d", &d[i]);
    
    printf("%d", count_between(4, 6, 10, d));

    return 0;
}



int count_between(int from, int to, int size, int a[]) 
{
    for(int i = 0; i < size; i++)
    {
        for(int b = 1 + i; b < size; b++)
        {
            if(a[i] > a[b])
            {
                int d = a[i];
                a[i] = a[b];
                a[b] = d;
            }
        }
    }

    int counter = 0;

    for(int i = 0; i < size; i++)
    {
        if (a[i] >= from && a[i] <= to)
                counter++;
    }

    return counter;
}