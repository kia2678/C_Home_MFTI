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
    int temp;
    for(int i = 0; i < n - 1; i++)
    {
        for(int s = 1 + i; s < n; ++s)
        {
            if(arr[i] > arr[s])
            {
                temp = arr[i];
                arr[i] = arr[s];
                arr[s] = temp;
            }
        }
    }

    long long int b = 0;
    for(int i = 0, l = 1; i < n; ++i, l *= 10)
    {
        b += arr[i] * l;
    }

    printf("%lld\n", b);
}