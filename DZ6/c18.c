#include <stdio.h>
int is_digit(char c);

int main()
{
    int res = 0;
    char a; 
    while((a = getchar()) != '.') res += is_digit(a);
    printf("%d\n", res);

    return 0;
}

int is_digit(char c)  {return (c > 47 && c < 58)?  1  : 0;}