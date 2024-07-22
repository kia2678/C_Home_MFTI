#include <stdio.h>
int sum_d(int (*d)[]);

int main()
{
    int d[10][10];
    for(int a = 0; a < 10; a++)
    {
        for(int b = 0; b < 10; b++)
                scanf("%d", &d[a][b]);
    }
               
    printf("%d", sum_d(d));

    return 0;
}



int sum_d(int (*d)[10])
{
    int sum = 0;
    int max;
    for(int i = 0; i < 10; i++)
    {
        max = d[i][0];
        for(int s = 1; s < 10; s++)
        {
            if(d[i][s] > max)
                    max = d[i][s];
        }
        sum += max;
    }
          
    return sum;
}