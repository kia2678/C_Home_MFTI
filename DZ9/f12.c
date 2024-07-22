#include <stdio.h>

void change_max_min(int size, int a[]);

int main()
{
    int d[10];
    for(int i = 0; i < 10; i++)
             scanf("%d", &d[i]);
    
    change_max_min(10, d);

    return 0;
}



void change_max_min(int size, int a[])
{
    int n1 = 0;
    int n2 = 0;
    int min = a[0];
    int max = a[0];

    for(int i = 1 ; i < size; i++)
    {
        if(a[i] < min)
        {
            min = a[i];
            n1 = i;
        }
        if(a[i] > max)
        {
            max = a[i];
            n2 = i;
        }
    }

    a[n1] = max;
    a[n2] = min;
}