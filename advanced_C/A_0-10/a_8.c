#include <stdio.h>
#include <math.h>

int main()
{
    int N, a, caunt = 0, res = 0, flag = 1, ok = 0; 
    scanf("%d", &N);
    if(N > 797161)
    {
        printf("-1");
        return 0;
    }
    int max = 1;
    while (max <= N && max < 531441)
    {
        max *= 3;
        caunt++;
    }
    if((max - N - ((max - 1) / 2)) > 0)
    {
        max /= 3;
        caunt--;
        flag = 0;
    }
    if(flag && max < 531441)
    {
        a = max - N;
        res++;
    }  
    else
        a = N;
    for(int i = caunt; i >= 0; i--)
    {
        if(a - pow(3, i) >= 0)
        {
            a -= pow(3, i);
            res++;
        }
        if(((pow(3, i)) - a - ((pow(3, i)-1)/2)) < 0)
        {
            a = pow(3, i) - a;
            res++;
        }      
        if(a == 0)
        {
            ok = 1;
            break;  
        }       
    }
    printf("%d", (ok)? res : -1);
    return 0;
}