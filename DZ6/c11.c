#include <stdio.h>
int nod(int a, int b);

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", nod(a, b));
    return 0;
}

int nod(int a, int b)
{
    int nod;
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
            return nod;
        }
        else
        {
            a %= nod;
            nod = a;
        }
        if(b % nod == 0)
        {
            return nod;
        }
        else
        {
            b %= nod;
            nod = b;
        }
    }
}
    