#include <stdio.h>
int main()
{
    char a;  
    while((a = getchar()) != '.')
    {
        if(a > 64 && a < 91)  a += 32;
        putchar(a); 
    }    
    return 0;
}