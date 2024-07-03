#include <stdio.h>
int sum(int* z);

int main()
{
    int a;
    scanf("%d", &a);
    printf("%d\n", sum(&a));
    return 0;
}

int sum(int* z)
{
    int res = 0;
    for(int i = 1; i <= *z; i++)
    {
        res +=i;
    } 
    return res;
}