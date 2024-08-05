#include <stdio.h>

int main()
{
    int N;
    char str[26] = {0};
    FILE *f_in = fopen("input.txt", "r");
    FILE *f_out = fopen("output.txt", "w");
    fscanf(f_in, "%d", &N);
    fclose(f_in);
    for(char i = 1, n = 2, cc = 'A'; i <= N; i++)
    {
        char c;
        if(i % 2 == 0)
        {
            c = n + '0';
            n += 2;
        }
        if (n == 10)
                n = 2;
        if(i % 2)
        {
            c = cc;
            cc++;
        }
        fputc(c, f_out);       
    }
    fclose(f_out);
    return 0;
}