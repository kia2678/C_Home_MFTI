#include <stdio.h>

void filling_array(int* arr, size_t size);
void inversion(int* arr, size_t size);

int main()
{
    int arr[10] = {0};
    size_t size = sizeof(arr) / sizeof(*arr);

    filling_array(arr, size);
    
    inversion(arr, size);
    return 0;
}


void filling_array(int* arr, size_t size)
{
    for (int i = 0; i < size; ++i)      scanf("%d", &arr[i]);
}


void inversion(int* arr, size_t size)
{
    for(int i = size / 2 - 1; i >= 0; --i)
    {
        printf("%d ", arr[i]);
    } 

    for(int i = size - 1; i >= size / 2; --i)
    {
        printf("%d ", arr[i]);
    }  
}