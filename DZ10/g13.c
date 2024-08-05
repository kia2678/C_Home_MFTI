#include <stdio.h>

int main()
{
    FILE *f_in = fopen("input.txt", "r");
    FILE *f_out = fopen("output.txt", "w");
    int n = 0;
    int t = 0;
    int stp;
    int i = 0;
    char c;
    while(c != '/')
    {
        fseek(f_in, -i, SEEK_END);
        c = fgetc(f_in);
        if(n == 0 && c >= 46)
                n = ftell(f_in);

        if(c == '.')
        {
            t = ftell(f_in);
            break;
        }
        i++;
    }
    stp = (t == 0)?  n  :  t-1;

    for(i = 0; i < stp; i++)
    {
        fseek(f_in, i, SEEK_SET);
        c = fgetc(f_in);
        fputc(c, f_out);
    }
    fclose(f_in);
    fprintf(f_out, ".html");
    fclose(f_out);
    return 0;
}