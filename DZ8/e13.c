#include <stdio.h>

void filling_array(int* arr, size_t size);
void sort(int* arr, size_t size);

int main()
{
    int arr[10] = {0};
    size_t size = sizeof(arr) / sizeof(*arr);

    filling_array(arr, size);
    
    sort(arr, size);
    return 0;
}


void filling_array(int* arr, size_t size)
{
    for (int i = 0; i < size; ++i)      scanf("%d", &arr[i]);
}


void sort(int* arr, size_t size)
{
    for(int i = 0; i < size; ++i)
    {
        if((arr[i]/10)%10 == 0)    printf("%d ", arr[i]);  
    }
}