#include <stdio.h>
int main()
{
    int a, b = 0; 
    
    while (1)
    {
        scanf("%d", &a);
        if(a == 0)  break;  
        b++;
    }
    printf("%d\n", b);
    return 0;
}