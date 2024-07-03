#include <stdio.h>
void str_UP(void);

int main()
{
    str_UP();
    return 0;
}  

void str_UP(void)
{
        char a;  
    while((a = getchar()) != '.')
    {
        if(a > 96 && a < 123)  a -= 32;
        putchar(a); 
    }    
}