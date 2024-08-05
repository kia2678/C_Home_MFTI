#include <stdio.h>
#include <string.h>

int is_palindrom(char *str);

int main()
{
    char str[1001] = {0};
    FILE *f_in  = fopen("input.txt", "r");
    FILE *f_out = fopen("output.txt", "w");

    fscanf(f_in, "%s", str);
    fclose(f_in);
    
    fprintf(f_out, "%s", (is_palindrom(str))?  "YES"  :  "NO");
    fclose(f_out);
    return 0;
}



int is_palindrom(char *str)
{
    int size = strlen(str);
    for(int i = 0, j = size -1; i < size / 2; i++, j--)
    {
        if(str[i] != str[j])
                return 0;
    }
    return 1;
}