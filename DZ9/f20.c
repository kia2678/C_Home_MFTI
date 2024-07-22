#include <stdio.h>
#include <string.h>

void ccc(int d[], int size);

int main()
{
    int d[10];
    for(int i = 0; i < 10; i++)
            scanf("%d", &d[i]);
    ccc(d, 10);
    return 0;
}

void ccc(int d[], int size)
{
    int ch = 0;
    int no_ch = 0;
    for(int i = 0; i < size; i++)
    {
        if(d[i] % 2)
                no_ch++;
        else 
                ch++;
    }

    if(ch > no_ch)
    {
        for(int i = 0; i < size; i++)
        {
            if(d[i] % 2)
            {
                int res = 1;
                char s[10];
                sprintf(s, "%d", d[i]);
                int sz = strlen(s);
                for(int g = 0; g < sz; g++)
                {
                    if(s[g] % 2)
                            res *= (s[g] - '0');
                }
                d[i] = res;
            }
        }
    }
    else
    {
       for(int i = 0; i < size; i++)
        {
            if(d[i] % 2 == 0)
            {
                int res = 1;
                char s[10];
                sprintf(s, "%d", d[i]);
                int sz = strlen(s);
                for(int g = 0; g < sz; g++)
                {
                    if(s[g] % 2 == 0)
                            res *= (s[g] - '0');
                }
                d[i] = res;
            }
        } 
    }

    for(int i = 0; i < size; i++)
            printf("%d ", d[i]);
}