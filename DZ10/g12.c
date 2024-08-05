#include <stdio.h>
#include <string.h>

int main()
{
    FILE *f_in = fopen("input.txt", "r");
    FILE *f_out = fopen("output.txt", "w");

    char s[1001] = {0};

    while (fscanf(f_in, "%s", s) == 1)
    {
        int size = strlen(s);
        
        fprintf(f_out, "%s\n", s);
        
        for(int i = 0; i <= size; i++)
                s[i] = 0;
    }
    fclose(f_in);
    fclose(f_out);

    return 0;
}