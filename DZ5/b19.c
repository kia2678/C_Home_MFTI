#include <stdio.h>
int main()
{
    int a, d = 0; 
    scanf("%d", &a);
     for(int b = 0, c = 1;; c*=10 , b++)
    {
        if(a/c == 0)  break;
        d += (a/c)%10;     
    }
    printf("%s\n", (d == 10)? "YES" : "NO");
    return 0;
}