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
    int low[10] = {0};
    int high[10] = {0};
    int caunter_l = 0;
    int caunter_h = 0;

    for(int i = 0; i < size; ++i)
    {
        if(arr[i] > 0)
        {
            high[caunter_h] = arr[i];
            caunter_h++;
        }

        if(arr[i] < 0)
        {
            low[caunter_l] = arr[i];
            caunter_l++;
        }
    }

    for(int i = 0; i < caunter_h; ++i)   printf("%d ", high[i]);
    for(int i = 0; i < caunter_l; ++i)   printf("%d ",  low[i]);

}