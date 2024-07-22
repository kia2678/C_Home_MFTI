#include <stdio.h>
int coun_d(int (*d)[5]);

int main()
{
    int d[5][5];
    for(int a = 0; a < 5; a++)
    {
        for(int b = 0; b < 5; b++)
                scanf("%d", &d[a][b]);
    }
               
    printf("%d", coun_d(d));

    return 0;
}



int coun_d(int (*d)[5])
{
    int counter = 0;
    int min = 0;

    for(int i = 0; i < 5; i++)
            min += d[i][i];
            
    min /=5;

    for(int i = 0; i < 5; i++)
    {
        for(int s = 0; s < 5; s++)
        {
            if(d[i][s] > min)
                    counter++;
        }
    }
          
    return counter;
}