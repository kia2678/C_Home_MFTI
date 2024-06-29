#include <stdio.h>
int main()
{

    int a, b, c, k =0; 
    scanf("%d", &a);
     for(b = 0, c = 1;; c*=10 , b++)
    {
        if((a/c)%10 == 9)  k++;

        if(a/c == 0)     break; 
    }
    printf("%s\n", (k == 1)? "YES" : "NO");
    return 0;
}