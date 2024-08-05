#include <stdio.h>
void sort(char *str, int size);

int main()
{
    FILE *f_in = fopen("input.txt", "r");
    FILE *f_out = fopen("output.txt", "w");
    
    char s[1001] = {0};
    char c;
    int i = 0;
    
    while ((c = fgetc(f_in)) != EOF)
    {
        s[i] = c;
        i++;
    }
    fclose(f_in);
    sort(s, i);
    fprintf(f_out, "%s", s);
    fclose(f_out);
    return 0;
}


void sort(char *str, int size)
{
    int c1, fl = 0;
    char buf;
    for (int i = 0; i < size; i++)
    {
        
        if (fl == 0 && str[i] > ' ')
        {
            c1 = i;
            buf = str[i];
            fl = 1;
        }
        else if(fl == 1 && str[i] > ' ')
        {
            str[c1] = str[i];
            str[i] = buf;
            fl = 0; 
        }
    }
}