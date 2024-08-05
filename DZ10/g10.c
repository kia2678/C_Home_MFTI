#include <stdio.h>
#include <string.h>

int main()
{
    FILE *f_in = fopen("input.txt", "r");
    FILE *f_out = fopen("output.txt", "w");

    int count = 0,    max = 0,     dub = 0;
    char res[1001] = {0},    s[1001] = {0};

    while (fscanf(f_in, "%s", s) == 1)
    {
        count = strlen(s);
        if(count == max)
                dub++;
        if(count > max)
        {
            for(int i = 0; i < count; i++)
                    res[i] = s[i];

            max = count;        
            dub = 0;
        }

        for(int i = 0; i <= count; i++)
                s[i] = 0;
    }
    fclose(f_in);

    if(dub == 0)
            fprintf(f_out, "%s", res);
    fclose(f_out);
    return 0;
}