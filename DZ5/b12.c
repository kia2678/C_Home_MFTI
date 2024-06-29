#include <stdio.h>
int main()
{
    int a, b, c, d[10] = {0}, k; 
    scanf("%d", &a);

     for(b = 0,  c = 1;; c*=10 , b++)
    {
        d[b] = (a/c)%10;
        if(a/c == 0)  break;     
    }

    for(int i = 0; i < b; i++)
    {
        for(int z = 1+i; z < b; z++)
        {
            if(d[i] > d[z])
            {
                k = d[i];
                d[i] = d[z];
                d[z] = k;                  
            }
        }
    }
    printf("%d %d", d[0], d[b-1]);
    return 0;
}