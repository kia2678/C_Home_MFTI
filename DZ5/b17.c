#include <stdio.h>
int main()
{
    int a; 
    scanf("%d", &a);
    
    for(int i = 10; i <= a; i++)
    {
        int d[10] ={0}, b = 0, c = 1;
        for(;; c*=10 , b++)
        {
            d[b] = (i/c)%10;
            if(i/c == 0)  break;     
        }
        
        int sum = 0, mul = 1;
        for(; b > 0; b--)
        {
            sum +=d[b-1];
            mul *=d[b-1];
        }

        if(sum == mul)   printf("%d ", i);
    }
    return 0;
}