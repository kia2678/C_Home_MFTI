#include <stdio.h>
void print_odd();

int main()
{
    print_odd(); 
    return 0;
}

void print_odd(void)
{
    int a;
    scanf("%d", &a);
    if(a == 0) return;
    if(a % 2) printf("%d ", a);
    print_odd();  
}