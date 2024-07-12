#include <stdio.h>

void filling_array(int* arr, size_t size);
void one(int* arr, size_t size);

int main()
{
    int arr[10] = {0};
    size_t size = sizeof(arr) / sizeof(*arr);

    filling_array(arr, size);
    
    one(arr, size);
    return 0;
}


void filling_array(int* arr, size_t size)
{
    for (int i = 0; i < size; ++i)      scanf("%d", &arr[i]);
}


void one(int* arr, size_t size)
{
    int caunter = 0;

    for(int i = 0; i < size; ++i)
    {
        for(int k = 0; k < size; ++k)
        {
            if(arr[i] == arr[k] && i != k)   caunter++;
        }

        if(caunter == 0)     printf("%d ",  arr[i]);
        caunter = 0;
    }  
    
}