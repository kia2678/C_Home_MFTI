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
    int temp;
  
    for(int i = 0; i < size/2 - 1; ++i)
    {
        for(int k = 1 + i; k < size / 2; ++k)
        {
            if(arr[i] > arr[k])
            {
                temp = arr[i];
                arr[i] = arr[k];
                arr[k] = temp;
            }
        }
    } 

    for(int i = size/2; i < size - 1; ++i)
    {
        for(int k = size/2 + 1 + (i - size/2); k < size; ++k)
        {
            if(arr[i] < arr[k])
            {
                temp = arr[i];
                arr[i] = arr[k];
                arr[k] = temp;
            }
        }
    }
    
    for(int i = 0; i < size; ++i)
    {
        printf("%d ", arr[i]);
    }
}