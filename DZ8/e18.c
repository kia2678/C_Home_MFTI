#include <stdio.h>

int main()
{
    int a;
    scanf("%d", &a);
    for(int i = 2; i < 10; ++i)
    {
        printf("%d %d\n", i, a/i);
    }
    return 0;
}