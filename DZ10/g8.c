#include <stdio.h>

int main()
{
    char N[1001] = {0};
    int nn[500] = {0};
    FILE *f_in = fopen("input.txt", "r");
    FILE *f_out = fopen("output.txt", "w");
    char c; 
    int cn = 0;
    while((c = fgetc(f_in)) != EOF)
    {
        if(c >= '0' && c <= '9')
        {
            N[cn] = c;
            cn++;
        }
        if(!(c >= '0' && c <= '9') && cn != 0 &&  N[cn - 1] != ' ')
        {
            N[cn] = ' ';
            cn++;
        }
    }
    fclose(f_in);

    int i = 0,   x = 0;
    while(N[i] != 0)
    {
        int a = 0;
        char s[20] = {0};
        while(N[i] != ' ')
        {
            s[a] = N[i++];
            a++;
        }
        sscanf(s, "%d", &nn[x]);
        i++;
        x++;
    }

    for(int i = 0; i < x; i++)
    {
        int n;
        for(int j = 1 + i; j < x; j++)
        {
            if(nn[i] > nn[j])
            {
                n = nn[i];
                nn[i] = nn[j];
                nn[j] = n; 
            }
        }
    }
          
    for(int j = 0; j < x; j++)
            fprintf(f_out, "%d ", nn[j]);
    fclose(f_out);

    return 0;
}