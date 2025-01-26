#include <stdio.h>

int main()
{
    int a, b, max = -2147483648, counter = 0;
    scanf("%d", &a);
    for(int i = 0; i < a; i++)
    {
        scanf("%d", &b);
        if(b == max)
        {
            counter++;
        }          
        if(b > max)
        {
            max = b;
            counter = 1;
        }       
    }
    printf("%d", counter);
    return 0;
}