#include <stdio.h>
int is_prime(int n);

int main()
{
    int a;
    scanf("%d", &a);
    printf("%s\n", (is_prime(a) == 0)?  "NO"  :  "YES");
    return 0;
}

int is_prime(int n)
{
    if(n == 1 || n == 0) return 0;
    for(int i = 2; i < n/2; i++)
    {
        if(n%i == 0) return 0;     
    }  
    return 1; 
}