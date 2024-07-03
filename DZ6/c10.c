#include <stdio.h>
void print_simple(int n);

int main()
{
    int a;
    scanf("%d", &a);
    print_simple(a);
    return 0;
}

void print_simple(int n)
{
    int res = 1;
    while(n > 0)
    {
        int z = 1;   
        while(1)
        {
            z++;
            int d = 0;
            for(int i = 2; i < z; i++)
            {
                if(z%i == 0)
                {
                    d = 1;
                    break;
                }       
            } 
            if(d == 0 && (n % z) == 0)
            {
                res = z;
                break;
            }               
        }
        printf("%d ", res);
        n = (n == res)?   0 : (n / res);      
    } 
    return;
}