#include <stdio.h>
#include <string.h>

int main()
{
    char str[1001] = {0};
    FILE *f_in  = fopen("input.txt", "r");
    FILE *f_out = fopen("output.txt", "w");

    char c;
    int i = 0;
    while ((c = fgetc(f_in)) != EOF)
    {
        if(c == 'a' || c == 'A')
                c++;
        else if(c == 'b' || c == 'B')
                c--;
        
        str[i] = c;
        i++;  
    }
    fclose(f_in);

    fprintf(f_out, "%s", str);
    fclose(f_out);

    return 0;
}