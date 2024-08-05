#include <stdio.h>
#include <string.h>

void palin(char *s1, char *s2, int sz);

int main()
{
    FILE *f_in = fopen("input.txt", "r");
    FILE *f_out = fopen("output.txt", "w");

    char s[1001] = {0};
    char str[1001] = {0};
    fscanf(f_in, "%s", s);
    fclose(f_in);

    int size = strlen(s);
    palin(s, str, size);
    fprintf(f_out, "%s", str);
    fclose(f_out);
    return 0;
}

void palin(char *s1, char *s2, int sz)
{
    char sb[sz/2 + 2];
    int counter = 1;
    char sred;
    int fl_sr = 0;
    if(sz == 1)
    {
        sred = s1[0];
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
            if(fl_sr == 0 && (counter % 2))
            {
                sred = s1[i - 1];
                fl_sr = 1;
            }       
            counter = 1;
        }
    }
    
    for(int i = 0; i < n; i++)
            s2[i] = sb[i];

    if(fl_sr == 1)
            s2[n] = sred;

    for(int i = (n + fl_sr), j = (n - 1); j >= 0; i++, j--)
            s2[i] = sb[j];
}