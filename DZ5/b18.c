#include <stdio.h>
int main()
{
    int a, c = 0, d = 1, f; 
    scanf("%d", &a);
    printf("%d ", d);
    for(int i = 1; i < a; i++)
    {
        f = c + d;
        printf("%d ", f);
        c = d; 
        d = f;    
    }
    return 0;
}