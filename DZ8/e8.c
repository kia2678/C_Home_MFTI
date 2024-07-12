#include <stdio.h>

void filling_array(int* arr, size_t size);
void inversion(int* arr, size_t size);

int main()
{
    int arr[12] = {0};
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

    printf("%d %d %d %d %d %d %d %d %d %d %d %d",  arr[3], arr[2], arr[1],  arr[0], 
                                                   arr[7], arr[6], arr[5],  arr[4], 
                                                   arr[11], arr[10], arr[9], arr[8]);
    
    return ;
}