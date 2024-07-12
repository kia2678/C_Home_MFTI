#include <stdio.h>

void filling_array(int* arr, size_t size);
void shift(int* arr, size_t size);

int main()
{
    int arr[10] = {0};
    size_t size = sizeof(arr) / sizeof(*arr);

    filling_array(arr, size);
    
    shift(arr, size);
    return 0;
}


void filling_array(int* arr, size_t size)
{
    for (int i = 0; i < size; ++i)      scanf("%d", &arr[i]);
}


void shift(int* arr, size_t size)
{
  
    printf("%d ", arr[size - 1]);
    for(int i = 0; i < size - 1 ; ++i)
    {
        printf("%d ", arr[i]);
    } 
}