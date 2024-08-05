#include <stdio.h>

int is_palindrom(char *s1, int sz);

int main()
{
    FILE *f_in = fopen("input.txt", "r");

    char s[1001] = {0};
    char c;
    int i = 0;
   
    while ((c = fgetc(f_in)) != EOF)
    {
        if(c >= 'a' && c <= 'z')
        {
            s[i] = c;
            i++;
        }
    }
    fclose(f_in);

    printf("%s", (is_palindrom(s, i))?  "YES"  :  "NO"); 
    return 0;
}

int is_palindrom(char *s1, int sz)
{
    char sb[sz/2 + 2];
    int counter = 1;
    int fl_sr = 0;
    if(sz == 1)
    {
        fl_sr = 1;
    }

    for(int i = 0; i < sz; i++)
    {
        for(int j = 1 + i; j < sz; j++)
        {
            char c;
            if(s1[i] > s1[j])
            {
                c = s1[i];
                s1[i] = s1[j];
                s1[j] = c;
            }
        }
    }
    int n = 0;
    for (int i = 1; i < sz; i++)
    {
        if (s1[i] == s1[i - 1])
        {
            counter++;
            if ((counter % 2) == 0)
            {
                sb[n] = s1[i];
                n++;
            }
        }
        if(s1[i] != s1[i - 1])
        {
            if(s1[sz-1] && fl_sr == 0)
                    fl_sr = 1;
            
            if(fl_sr == 0 && (counter % 2))
                    fl_sr = 1;

            counter = 1;
        }
    }

    return (sz == n * 2 + fl_sr)?  1  :  0;
}