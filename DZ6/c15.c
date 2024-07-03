#include <stdio.h>
int grow_up(int n);

int main()
{
    int a;
    scanf("%d", &a);
    printf("%s\n", (grow_up(a) == 0)?  "NO"  :  "YES");
    return 0;
}


int grow_up(int n)
{
    int b = 0, c = 1;
    while (1)
    {
        if((b <= (n/c)%10) && (c != 1))  return 0;
        if(n/c == 0)                     return 1;

        b = (n/c)%10;
        c *= 10;
    }
}