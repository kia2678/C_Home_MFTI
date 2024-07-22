#include <stdio.h>

void c_n(char s[]);

int main()
{
    char s[1000];
    scanf("%s", s);
    c_n(s);
    return 0;
}

void c_n(char s[])
{
    int counter = 1;
    int i = 0;
    while (s[i] != '.')
    {
        if(s[i] == s[i + 1] && s[i+1] != '.')
                counter++;

        if(s[i] != s[i + 1])
        {
            printf("%c%d", s[i], counter);
            counter = 1;
        }
        i++;
    }
}