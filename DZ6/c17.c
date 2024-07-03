#include <stdio.h>
int is_happy_number(int n);

int main()
{
    int a;
    scanf("%d", &a);
    printf("%s\n", (is_happy_number(a) == 0)?  "NO"  :  "YES");
    return 0;
}

int is_happy_number(int n)
{
    int d[10] ={0}, b = 0, c = 1;
    for(;; c*=10 , b++)
    {
        d[b] = (n/c)%10;
        if(n/c == 0)  break;     
    }
        
    int sum = 0, mul = 1;
    for(; b > 0; b--)
    {
        sum +=d[b-1];
        mul *=d[b-1];
    }

    return (sum == mul)?  1  :  0;  
}
