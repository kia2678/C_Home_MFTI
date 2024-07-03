#include <stdio.h>

int middle(int* a, int* b);

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", middle(&a, &b));
    return 0;
}

int middle(int* a, int* b)
{
    return (*a + *b) / 2;
}