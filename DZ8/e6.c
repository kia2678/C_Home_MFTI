#include <stdio.h>

void filling_array(int* arr, size_t size);
float average_arithmetic(int* arr, size_t size);

int main()
{
    int arr[12] = {0};
    size_t size = sizeof(arr) / sizeof(*arr);

    filling_array(arr, size);
    
   printf("%.2f\n", average_arithmetic(arr, size));
    return 0;
}


void filling_array(int* arr, size_t size)
{
    for (int i = 0; i < size; ++i)      scanf("%d", &arr[i]);
}


float average_arithmetic(int* arr, size_t size)
{
    int a = 0;
    for(int i = 0; i < size; ++i)      a += arr[i];
    
    return a / (float) size;
}