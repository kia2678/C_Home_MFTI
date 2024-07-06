#include <stdio.h>
#include <math.h>

int code_2(int);

int main()
{
   int a;
    scanf("%d", &a);
    printf("%d\n", code_2(a));
    return 0;
}

int code_2(int n)
{
    if(n == 0) return 0;
    static int res = 0;
    int degree = 0;
    int buf = n;

    while (!(buf > 0 && buf < 2))
    {
        buf /= 2;
        degree++;
    }

    res += (buf * pow(10, degree));
    n   -= (buf *pow(2, degree));
    degree = 0;
    
    if(n !=0) code_2(n);
    return res;
}