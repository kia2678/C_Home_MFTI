#include <stdio.h>
int brackets(char c, int* s);

int main()
{
    int res = 0;
    char a; 
    while((a = getchar()) != '.') res += brackets(a, &res);
    printf("%s\n", (res == 0)?  "YES"  :  "NO");

    return 0;
}

int brackets(char c, int* s) 
{

    if(c == 41 && *s == 0) return 1;
    else if(c == 40) return 1;
    else if(c == 41) return -1;
    return 0;
}