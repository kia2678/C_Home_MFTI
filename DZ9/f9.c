#include <stdio.h>

void filling_array(int* arr);
void swap_negmax_last(int size, int a[]);
int size = 0;

int main()
{
    int arr[1000] = {0};   
    filling_array(arr);
    swap_negmax_last(size, arr);
    for(int i = 0; i < size; i++)
            printf("%d ", arr[i]);
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


void swap_negmax_last(int size, int a[])
{
    int index = -1;
    int min = -32768;
    for (int i = 0; i < size; i++)
    {
        if(a[i] < 0 && a[i] > min)
        {
            index = i;
            min = a[i];
        }
    }
    if(index != -1)
    {
        a[index] = a[size -1];
        a[size - 1] = min;
    }   
}