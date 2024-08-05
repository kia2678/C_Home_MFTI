#include <stdio.h>
#include <string.h>

int main()
{
    char s[100] = {0};
    FILE *f_in = fopen("input.txt", "r");
    FILE *f_out = fopen("output.txt", "w");
    char c = 'a';
    int i = 0;
    while ((c = fgetc(f_in)) != EOF)
    {
        if(c != '\n')
        {
            s[i] = c;
            i++;
        }   
    }
    fclose(f_in);
    int size = strlen(s);
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < size; j++)
        {
            fputc(s[j], f_out);
        }
        if(i < 2)
                fputs(", ", f_out);
    }
    fprintf(f_out, " %d", size);
    fclose(f_out);
    return 0;
}