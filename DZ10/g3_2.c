#include <stdio.h>

int main()
{
    char ccc = EOF;
    FILE *f_in = fopen("input.txt", "r");
    FILE *f_out = fopen("output.txt", "w");
    int l = 0;
    while(ccc < 32)
    {
        fseek(f_in, -l, SEEK_END);
        ccc = fgetc(f_in);
        l++;
    }
    
    int size = ftell(f_in);
    for(int i = 0; i < size - 1; i++)
    { 
        fseek(f_in, i, SEEK_SET);
        char c = fgetc(f_in);
        if(c == ccc)
        {
            fprintf(f_out, "%d ", i);
        }
    }

    fclose(f_in);
    fclose(f_out);
    
    return 0;
}