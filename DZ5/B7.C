#include <stdio.h>
int main()
{

    int a, b, c; 
    scanf("%d", &a);
    int d[10] = {0};
    for(b = 0, c = 1; b < 10; c*=10 , b++)
    {
        int k = 0;
        for(int i = b; i > 0; i--)
        {
            if((a/c)%10 == d[i - 1])
            {
                k = 1;
            }
        }

        if(k)
        {
            printf("YES");
            break;
        }
        
        if(a/c == 0)
        {
            printf("NO");
            break;
        } 
        d[b] = (a/c)%10;
    }
    

    return 0;
}