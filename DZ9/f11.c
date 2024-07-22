#include <stdio.h>

void sum_min(int *d, int size);

int main()
{
    int d[30];
    for(int i = 0; i < 30; i++)
             scanf("%d", &d[i]);
    
    sum_min(d, 30);
    
    return 0;
}

void sum_min(int *d, int size)
{   int n1 = 0;
    int n2;
    int min_1 = d[0];
    int min_2 = d[0];

    for(int i = 1; i < size; i++)
    {
        if(d[i] < min_1)
        {
            min_1 = d[i];
            n1 = i;
        }          
    }

    if(n1 == 0)
    {
        min_2 = d[1];
        n2 = 1;
    }
            
    for(int i = 1; i < size; i++)
    {
        if(d[i] < min_2 && i != n1)
        {
            min_2 = d[i];
            n2 = i;
        }         
    }
    (n1 < n2)?  printf("%d %d", n1, n2)  :  printf("%d %d", n2, n1);
}
