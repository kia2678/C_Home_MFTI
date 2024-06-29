#include <stdio.h>
int main()
{
    int a, b, c; 
    scanf("%d", &a);
     for(b = 0, c = 1;; c*=10 , b++)
    {
        if(((a/c)%10)%2)
        {
            printf("NO");
            break;
        }

        if(a/c == 0)
        {
            printf("YES");
            break; 
        }    
    }
       return 0;
}