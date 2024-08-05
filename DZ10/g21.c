#include <stdio.h>

int main()
{
    FILE *f_in = fopen("input.txt", "r");
    FILE *f_out = fopen("output.txt", "w");

    char c;
    int i = 0;
   
    while ((c = fgetc(f_in)) != EOF)
    {
        if(c == '*')
                i++;
    }
    fclose(f_in);
    int res = 0;
    int k = 3;
    int j = 3;
    while(j <= i)
    {
        if(j == i)
        {
            res = 1;
            break;
        }
        j += k;
        k++;
    }
    if(res == 0)
            fprintf(f_out, "NO");
    else
    {
        int h = k - 1, t = k - 1;
        while(j > 0)
        {
            for(int i = 0; i < h - 1; i++) 
                    fputc(' ', f_out);
            

            for(int g = h - 1; g < t; g += 2)
            {
                fputc('*', f_out);
                fputc(' ', f_out);
            }
            fputc('\n', f_out);
            j -= h;
            h--;
            t++;   
        } 
        fclose(f_out); 
    }
    return 0;
}