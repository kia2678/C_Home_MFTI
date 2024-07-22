// #include <stdio.h>

// void filling_array(int* arr, size_t size);
// void sort_array(int size, int a[]);

// int main()
// {
//     int arr[5] = {0};
//     size_t size = sizeof(arr) / sizeof(*arr);

//     filling_array(arr, size);

//     sort_array(5, arr);

//     for(int i = 0; i < size; ++i)
//     {
//             printf("%d ", arr[i]);
//     }
    
   
//     return 0;
// }


// void filling_array(int* arr, size_t size)
// {
//     for (int i = 0; i < size; ++i)      scanf("%d", &arr[i]);
// }


void sort_array(int size, int a[])
{
    
    for(int i = 0; i < size; ++i)
    {
        for(int z = 1 + i; z < size; ++z)
        {
            int n;
            if(a[i] > a[z])
            {
                n = a[z];
                a[z] = a[i];
                a[i] = n;
            }
        }
    }
}