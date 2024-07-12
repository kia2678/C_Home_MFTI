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
    int res[10] = {0};
    int caunter = 0;

    for(int i = 0; i < size; ++i)
    {
        for(int k = 1 + i; k < size; ++k)
        {
            if(arr[i] == arr[k])
            {
                int fl = 0;
                for(int s = 0; s < caunter; ++ s)
                {
                    if( arr[i] == res[s])   ++fl;
                }

                if(fl == 0)
                {
                    res[caunter] = arr[i];
                    caunter ++;
                    printf("%d ", arr[i]);
                }
            }
        } 
    }
}