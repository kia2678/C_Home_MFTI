#include <stdio.h>

void filling_array(int* arr, size_t size);
int sum_max_value(int* arr, size_t size);

int main()
{
    int arr[10] = {0};
    size_t size = sizeof(arr) / sizeof(*arr);

    filling_array(arr, size);
    
    printf("%d\n", sum_max_value(arr, size));
    return 0;
}


void filling_array(int* arr, size_t size)
{
    for (int i = 0; i < size; ++i)      scanf("%d", &arr[i]);
}


int sum_max_value(int* arr, size_t size)
{
    int max_1 = arr[0], max_2 = 0;

    for(int i = 1; i < size; ++i)
    {
        if(max_1 < arr[i])
        {
            max_2 = max_1;
            max_1 = arr[i];
        }
        else if(max_2 < arr[i])
        {
            max_2 = arr[i];
        }

    }  
    
    return max_1 + max_2;
}