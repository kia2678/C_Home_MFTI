#include <stdio.h>

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
    for(int j = 0; j < i; j++)
    {
        int f = 0;
        if(s[j] == 'L' && s[j+1] == 'i' && s[j+2] == 'n' && s[j+3] == 'g')
        {
            fprintf(f_out, "Cao");
            j += 3; 
            f = 1; 
        }
        if(f == 0)
                fputc(s[j], f_out);
    }
    fclose(f_out);
             
    return 0;
}