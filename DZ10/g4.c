#include <stdio.h>
#include <string.h>

int select(int sz1, int sz2, char *st1, char *st2, char *ct_res);

int main()
{
    char s[101] = {0};
    char ss[101] = {0};
    char s_res[101] = {0};

    FILE *f_in  = fopen("input.txt", "r");
    FILE *f_out = fopen("output.txt", "w");

    fscanf(f_in, "%s %s", s, ss);
    fclose(f_in);

    int sz_s = strlen(s);
    int sz_ss = strlen(ss);

    int size = select(sz_s, sz_ss, s, ss, s_res);
    for(int i = 0; i < size; i++)
            fprintf(f_out, "%c ", s_res[i]);
    fclose(f_out);
      
    return 0;
}



int select(int sz1, int sz2, char *st1, char *st2, char *ct_res)
{
    int counter1 = 0;
    int counter2 = 0;
    int cn = 0;
     for(int i = 0; i < sz1; i++)
        {
            for(int j = 0; j < sz1; j++)
            {
                if(st1[i] == st1[j])
                        counter1++;
            }
            if(counter1 == 1)
            {
                for(int g = 0; g < sz2; g++)
                {
                    if(st1[i] == st2[g])
                            counter2++;
                }
            }
            if (counter1 == 1 && counter2 == 1)
            {
                ct_res[cn] = st1[i];
                cn++;
            }
            counter1 = 0;
            counter2 = 0;
        }
    return cn;
}