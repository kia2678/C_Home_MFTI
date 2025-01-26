#include <stdio.h>

int main()
{
    int a, c, k = 26, L = 'a', H = 'A'; 
    scanf("%d", &a);    
    do
    {
        c = getchar();
        if(c == '.' || c == ' ')
            putchar(c);
        else if(c >= 'a' && c <= 'z')
            putchar((((c-L) + a)%k) + L);
        else if(c >= 'A' && c <= 'Z')
            putchar((((c-H) + a)%k) + H);
    } while (c != '.');
    return 0;
}