#include <stdio.h>
int main()
{
    int a, d = 0; 
    scanf("%d", &a);
    if(a == 1) d = 1;
    for(int i = 2; i < a/2; i++)
    {
        if(a%i == 0)
        {
            d = 1;
            break;
        }       
    }  
    printf("%s\n", (d == 1)?  "NO" : "YES");
    return 0;
}