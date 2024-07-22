#include <stdio.h>
int wh_bl(char s[]);

int main()
{
    char s[2];
    scanf("%s", s);
    printf("%s", (wh_bl(s) == 1)?  "BLACK"  :  "WHITE");
    return 0;
}

int wh_bl(char s[])
{
    int res = 1;
    if(s[0] % 2)
            res = 0;
    
    if(s[1] % 2)
           res = (res == 0)?  1  :  0;
    
    return res;
}