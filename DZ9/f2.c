#include <stdio.h>

void filling_array(int* arr, size_t size);
void sort_even_odd(int n, int a[]);

int main()
{
    int arr[8] = {0};
    size_t size = sizeof(arr) / sizeof(*arr);

    filling_array(arr, size);

    sort_even_odd(8, arr);

    printf("\n");
    for(int i = 0; i < size; ++i)
    {
            printf("%d ", arr[i]);
    }
    
   
    return 0;
}


void filling_array(int* arr, size_t size)
{
    for (int i = 0; i < size; ++i)      scanf("%d", &arr[i]);
}


void sort_even_odd(int n, int a[])
{
    int b = 0;
    int m = 0;
   
    while (m < n)
    {
        if (a[b] % 2)
        {
            int z = a[b];
            
            for (int t = b; t < n - 1; t++)
            {
                a[t] = a[t + 1];
            }  

            a[n - 1] = z;       
        }
        else    b++;

        m++; 
    }   
}