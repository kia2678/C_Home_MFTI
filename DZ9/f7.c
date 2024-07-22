#include <stdio.h>
int compression(int a[], int b[], int N);

int main()
{
    int arr[10] = {0, 1, 0, 1, 0, 0, 0, 1, 1, 1};
    int arr_k[11] = {0};
    
    printf("%d\n", compression(arr, arr_k, 10));
    for(int i = 0; i < 11; i++)
            printf ("%d ", arr_k[i]);
    return 0;
}


int compression(int a[], int b[], int N)
{
    int z = 0;
    if(a[0] == 1)
    {
        z++;
        b[0] = 0;
    }       

    int counter = 1;
    for(int i = 0; i < N - 1; i++)
    {
        if(a[i] == a[i + 1])
                counter++;

        if(a[i] != a[i + 1])
        {
            b[z] = counter;
            z++;
            counter = 1;
        }
    }
    b[z] = counter;

    return z + 1;
}