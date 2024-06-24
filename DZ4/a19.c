#include <stdio.h>
int main()
{
    int a, b, c, st_2, st_3, st_4; 
    scanf("%d %d %d", &a, &b, &c);
    printf("%s\n", ((a + b) > c && (a +c) > b && (b+c) > a)? "YES" : "NO");
    return 0;
}