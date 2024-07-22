#include <stdio.h>
int is_two_same(int size, int a[]);

int main()
{
    int arr[10] = {1, 1, 3, 4, 5, 6, 7, 8, 9, 10};
    
    printf("%d", is_two_same(10, arr));
    return 0;
}


int is_two_same(int size, int a[])
{
    for(int i = 0; i < size - 1; i++)
    {
        int res = 0;
        for(int d = 0; d < size; d++)
        {
            if(a[i] == a[d])
                    res++;
            
            if(res > 1)
                    return 1;
        }
    }
    return 0;
}




