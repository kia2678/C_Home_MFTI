#include <stdio.h>

void filling_array(int* arr, size_t size);
int minimum_value(int* arr, size_t size);

int main()
{
    int arr[5] = {0};
    size_t size = sizeof(arr) / sizeof(*arr);

    filling_array(arr, size);
    
   printf("%d\n", minimum_value(arr, size));
    return 0;
}


void filling_array(int* arr, size_t size)
{
    for (int i = 0; i < size; ++i)      scanf("%d", &arr[i]);
}


int minimum_value(int* arr, size_t size)
{
    int a = arr[0];
    for(int i = 1; i < size; ++i)
    {
        if(arr[i] < a)   a = arr[i];
    }      
    
    return a;
}