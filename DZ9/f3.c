#include <stdio.h>
#include <string.h>

 void u_n(char *sn, int size);

 int main ()
 {
    char str_number[1000];
    scanf("%s", str_number);
    int size = strlen(str_number);
   u_n(str_number, size);
    return 0;
 }



 void u_n(char *sn, int size)
 {
    for(int i = 0; i < size - 1; i++)
    {
        for(int z = 1 + i; z < size; z++)
        {
            char c;
            if (sn[i] > sn[z])
            {
                c = sn[i];
                sn[i] = sn[z];
                sn[z] = c;
            }
        }
    }
    int counter = 1;
    for(int i = 0; i < size - 1; i++)
    {
        if(sn[i] == sn[i + 1])
                    counter++;
        
        if(sn[i] != sn[i + 1])
        {
            printf("%c %d\n", sn[i], counter);
            counter = 1;
        }
    }
    printf("%c %d\n", sn[size - 1], counter);
 }