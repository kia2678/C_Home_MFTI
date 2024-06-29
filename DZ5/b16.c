#include <stdio.h>
int main()
{
    int a, b, nod; 
    scanf("%d %d", &a, &b);
    if(a < b)
    {
        nod = a;
        a = b;
        b = nod;
    }
    else nod = b;
    
    while (1)
    {
        if(a % nod == 0)
        {
            printf("%d\n", nod);
            break;
        }
        else
        {
            a %= nod;
            nod = a;
        }
        if(b % nod == 0)
        {
            printf("%d\n", nod);
            break;
        }
        else
        {
            b %= nod;
            nod = b;
        }

    }
    return 0;
}