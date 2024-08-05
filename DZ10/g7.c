#include <stdio.h>

int main()
{
    FILE *f_in = fopen("input.txt", "r");
    FILE *f_out = fopen("output.txt", "w");

    int m = 0,    b = 0;
    char c;

    while((c = fgetc(f_in)) != EOF)
    {
        if(c >= 'a' && c <= 'z')
                m++;
        if(c >= 'A' && c <= 'Z')
                b++;
    }
    fclose(f_in);

    fprintf(f_out, "%d %d", m, b);
    fclose(f_out);
    return 0;
}