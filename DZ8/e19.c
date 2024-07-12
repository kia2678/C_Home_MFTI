#include <stdio.h>

int main()
{
    long long int a;
    scanf("%lld", &a);
    int arr[20] = {0};

    int n = 0;
    int k = 1;

    while (a / k > 0)
    { 
        arr[n] = (a / k) % 10;   
        n++;
        k *= 10;
    }

    for(int i = n - 1; i >= 0; --i)
    {
        printf("%d ", arr[i]);
    }    
}