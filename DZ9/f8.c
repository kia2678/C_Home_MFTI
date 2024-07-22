#include <stdio.h>

void filling_array(int* arr);
int lost(int *ar, int size);
int size = 0;

int main()
{
    int arr[1000] = {0};
    
    filling_array(arr);

    printf("%d\n", lost(arr, size));
    return 0;
}




void filling_array(int *arr)
{
    int h;
    while ((h = scanf("%d", &arr[size])) && arr[size] != 0)
    {
        size++;
    }         
}


int lost(int *ar, int size)
{
    
    for (int i = 0; i < size; i++)
    {
        for (int s = 1 + i; s < size; s++)
        {
            if (ar[i] > ar[s])
            {
                int a;
                a = ar[i];
                ar[i] = ar[s];
                ar[s] = a;
            }
        }
    }

    for(int i = 0; i < size - 1; i++)
    {
        if(ar[i] != (ar[i + 1] - 1))
                   return ar[i] + 1;
    }
    return 0;
}