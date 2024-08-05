#include <stdio.h>
#include <string.h>

int main()
{
    FILE *f_in = fopen("input.txt", "r");
    FILE *f_out = fopen("output.txt", "w");

    int counter = 0,    size = 0;
    char s[1001] = {0};

    while (fscanf(f_in, "%s", s) == 1)
    {
        size = strlen(s);
        if (s[size - 1] == 'a')
                counter++;  
    }
    fclose(f_in);

    fprintf(f_out, "%d", counter);
    fclose(f_out);

    return 0;
}