#include <stdio.h>

int main()
{
    FILE *f_in = fopen("input.txt", "r");
    FILE *f_out = fopen("output.txt", "w");
    char c;
    int count = 0;
    int i = 0;
    while ((c = fgetc(f_in)) != EOF)
    {
        if(i == 0 && c == ' ')
        {
            count++;
            i++;
            continue;
        }
        if(i > 0 && c ==' ')
                count++;
        if(c != ' ' || (c == ' ' && count < 2))
        {
            fputc(c, f_out);
            if(c !=' ')
                    count = 0;
        }
        i++;  
    }
    fclose(f_out);
    
    return 0;
}