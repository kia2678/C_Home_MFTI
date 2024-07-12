#include <stdio.h>

void filling_array(int* arr, size_t size);
int sum_positive(int* arr, size_t size);

int main()
{
    int arr[10] = {0};
    size_t size = sizeof(arr) / sizeof(*arr);

    filling_array(arr, size);
    
    printf("%d\n", sum_positive(arr, size));
    return 0;
}


void filling_array(int* arr, size_t size)
{
    for (int i = 0; i < size; ++i)      scanf("%d", &arr[i]);
}


int sum_positive(int* arr, size_t size)
{
    int max = 0;

    for(int i = 0; i < size; ++i)
    {
        if(arr[i] > 0)     max += arr[i];
    }  
    
    return max;
}