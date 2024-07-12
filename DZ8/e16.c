#include <stdio.h>

void filling_array(int* arr, size_t size);
int max_counter(int* arr, size_t size);

int main()
{
    int arr[10] = {0};
    size_t size = sizeof(arr) / sizeof(*arr);

    filling_array(arr, size);
    
    printf("%d\n", max_counter(arr, size));
    return 0;
}


void filling_array(int* arr, size_t size)
{
    for (int i = 0; i < size; ++i)      scanf("%d", &arr[i]);
}


int max_counter(int* arr, size_t size)
{
    int max = 0;
    int c_max = 0;
    int caunter = 0;


    for(int i = 0; i < size; ++i)
    {
        for(int k = 1 + i; k < size; ++k)
        {
            if(arr[i] == arr[k])   caunter++;
        }

        if(caunter > c_max)
        {
            max = arr[i];
            c_max = caunter;
        }
        caunter = 0;
    }  
    
    return max;
}