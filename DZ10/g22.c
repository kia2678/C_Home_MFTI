#include <stdio.h>
#include <string.h>

int main()
{
    FILE *f_in = fopen("input.txt", "r");
    FILE *f_out = fopen("output.txt", "w");

    char s[21] = {0}; 
    int i = 0;  
    char c;
    while ((c = fgetc(f_in)) != EOF)
    {
        if(i == 0)
        {    
            s[i] = c;
            i++;
        }
        else if(c == 'b' || c == 'f' || c == 'p' || c == 'v')
        {
            s[i] = '1';
            i++;
        }
        else if(c == 'c' || c == 'g' || c == 'j' || c == 'k' || c == 'q' || c == 's' || c == 'x' || c == 'z')
        {
            s[i] = '2';
            i++;
        }
        else if(c == 'd' || c == 't')
        {
            s[i] = '3';
            i++;
        }
        else if(c == 'l')
        {
            s[i] = '4';
            i++;
        }
        else if(c == 'm' || c == 'n')
        {
            s[i] = '5';
            i++;
        }
        else if(c == 'r')
        {
            s[i] = '6';
            i++;
        }
    }
    fclose(f_in);

    int size = strlen(s);
    int j = 0;
    for(int i = 0; i < size; i++)
    {
        if(i == 0)
        {
            fputc(s[i], f_out);
            j++;
        }
        else if(s[i] != s[i - 1] && j < 4)
        {
            fputc(s[i], f_out);
            j++;   
        }  
    }
    for(int i = j; i < 4; i++)
            fputc('0', f_out);
    fclose(f_out);
    return 0;
}