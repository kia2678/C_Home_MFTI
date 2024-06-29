#include <stdio.h>
int main()
{
    int a, b, c, ch = 0, nch = 0; 
    scanf("%d", &a);

     for(b = 0,  c = 1;; c*=10 , b++)
    {
        if(a/c == 0)  break;
        if(((a/c)%10)%2 == 0)  ch++; 
        else nch++;       
    }

    printf("%d %d", ch, nch);
    return 0;
}