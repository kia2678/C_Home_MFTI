#include <stdio.h>
#include <math.h>

int code(int, int);

int main()
{
   long long int a, b;
    scanf("%d %d", &a, &b);
    printf("%lld\n", code(a, b));
    return 0;
}

int code(int n, int p)
{
   long long int res = 0;
    int degree = 0;
    int buf;

    while (n !=0)
    {
        buf = n;
        while (!(buf > 0 && buf < p))
        {
            buf /= p;
            degree++;
        }
        res += (buf * pow(10, degree));
        n   -= (buf *pow(p, degree));
        degree = 0;
    }
    return res;
}