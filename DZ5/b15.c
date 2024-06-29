#include <stdio.h>
int main()
{
    int a, b = 0; 
    
    while (1)
    {
        scanf("%d", &a);
        if(a == 0)  break;  
       if(a%2 == 0) b++;
    }
    printf("%d\n", b);
    return 0;
}