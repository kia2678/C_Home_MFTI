#include <stdio.h>
int find_max_array(int size, int a[]);

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    printf("%d", find_max_array(10, arr));
    return 0;
}


int find_max_array(int size, int a[])
{
    int max = a[0];
    for(int i = 1; i < size; i++)
    {
        if(a[i] > max)
                max = a[i];
    }
    return max;
}