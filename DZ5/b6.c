#include <stdio.h>
int main()
{
    int a, b = 0, c = 1; 
    scanf("%d", &a);
    while (1)
    {
        if((b == (a/c)%10) && (c != 1))
        {
            printf("YES");
            break;            
        }
        if(a/c == 0)
        {
            printf("NO");
            break;
        } 
        b = (a/c)%10;
        c *= 10;
    }
    return 0;
}