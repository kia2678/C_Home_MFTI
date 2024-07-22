#include <stdio.h>

int sum_between_ab(int from, int to, int size, int a[]);

int main()
{
    int d[12];
    for(int i = 0; i < 12; i++)
             scanf("%d", &d[i]);
    
    printf("%d", sum_between_ab(4, 6, 12, d));

    return 0;
}



int sum_between_ab(int from, int to, int size, int a[]) 
{
    if(from > to)
    {
        int buf = from;
        from = to;
        to = buf;
    }

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

    int sum = 0;

    for(int i = 0; i < size; i++)
    {
        if (a[i] >= from && a[i] <= to)
                sum += a[i];
    }

    return sum;
}