#include <stdio.h>

int main()
{
    FILE *f_in = fopen("input.txt", "r");
    FILE *f_out = fopen("output.txt", "w");

    char str[1001] = {0};
    int n = 0;
    char c;
    while((c = fgetc(f_in)) != EOF)
    {
        int fl = 0;
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            for(int i = 0; i < n; i++)
            {
               if(c == str[i])
                    fl++;
            }
            if(fl == 0)
            {
                str[n] = c;
                n++;
            }
        }
    }
    fclose(f_in);

    fprintf(f_out, "%s", str);
    fclose(f_out);

    return 0;
}