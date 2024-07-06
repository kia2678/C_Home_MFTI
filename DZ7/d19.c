#include <stdio.h>
int acounter(void);

int main ()
{
    printf("%d", acounter());
    return 0;
}


int acounter(void)
{
    static int s = 0;
    char a;
    a = getchar();
    if(a != '.')  acounter();
    if(a == 'a') s++;
    return s;
}
