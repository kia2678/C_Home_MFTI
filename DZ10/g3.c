#include <stdio.h>
#include <string.h>

int main()
{
    char s[1001] = {0};
    char ccc, c;
    int i = 0;
    FILE *f_in = fopen("input.txt", "r");
    FILE *f_out = fopen("output.txt", "w");
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
    ccc = s[size - 1];
    for(int i = 0; i < size - 1; i++)
    {
        if(s[i] == ccc)
                fprintf(f_out, "%d ", i)  ; 
    }
    fclose(f_out); 
    return 0;
}