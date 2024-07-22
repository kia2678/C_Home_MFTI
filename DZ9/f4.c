#include <stdio.h>
#include <string.h>

 void print_digit(char s[]);

 int main ()
 {
    char str_number[1000];
    scanf("%s", str_number);
    print_digit(str_number);
    return 0;
 }



 void print_digit(char s[])
 {
    int size = strlen(s);

    for (char i = '0'; i <= '9'; i++)
    {   
        int counter = 0;
        for(int n = 0; n < size; n++)
        {
            if(s[n] == i)
                    counter++;
        }
        if(counter)
                printf("%d %d\n", i - '0', counter);
    }
 }