#include <stdio.h>

void filling_array(int* arr, size_t size);
int min_max_value(int* arr, size_t size);

int main()
{
    int arr[10] = {0};
    size_t size = sizeof(arr) / sizeof(*arr);

    filling_array(arr, size);
    
    min_max_value(arr, size);
    return 0;
}


void filling_array(int* arr, size_t size)
{
    for (int i = 0; i < size; ++i)      scanf("%d", &arr[i]);
}


int min_max_value(int* arr, size_t size)
{
    int a = arr[0], b = arr[0], n_min = 1, n_max = 1;

    for(int i = 1; i < size; ++i)
    {
        if(arr[i] < a)   
        {
            a = arr[i];  
            n_min = i + 1;
        }

        if(arr[i] > b)   
        {
            b = arr[i];  
            n_max = i + 1;
        }
    } 

    printf("%d %d %d %d\n", n_max, b, n_min, a);     
    
    return a;
}