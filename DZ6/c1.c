#include <stdio.h>

int module(int* number);

int main()
{
    int a;
    scanf("%d", &a);
    printf("%d\n", module (&a));
    return 0;
}

int module(int* number)
{
    return (*number >= 0)? *number : (*number) * -1;
}