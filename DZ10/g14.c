#include <stdio.h>

int main()
{
    FILE *f_in = fopen("input.txt", "r");
    FILE *f_out = fopen("output.txt", "w");
    char last[100] = {0};
    char name[100] = {0};

    fscanf(f_in, "%s %s", last, name);
    fclose(f_in);

    fprintf(f_out, "Hello, %s %s!", name, last);
    fclose(f_out);

    return 0;
}