#include <stdio.h>
int main()
{
    int a, b = 0, c = 1; 
    scanf("%d", &a);
    while (1)
    {
    if(a/c == 0) break;
    c *= 10;
    b++;
    }
    printf("%s\n", (b == 3)? "YES" : "NO");
    return 0;
}