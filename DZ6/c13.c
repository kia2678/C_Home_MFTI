#include <stdio.h>
#include <math.h>
float cosinus(float x);
float factorial(float n);

int main()
{
    float a;
    scanf("%f", &a);
    a = a * 3.1415926535 / 180;
    
    printf("%.3f\n", cosinus(a));
    return 0;
}



float cosinus(float x)
{
    float res = 1;
    for(int i = 2, zn = 2 ; i < 7; i +=2, zn++)
    {
        if(zn % 2 ==0)    res -= (pow(x, i) / factorial(i));
        if(zn % 2 !=0)    res += (pow(x, i) / factorial(i));       
    }
    return res;
}

float factorial(float n)
{
    float res = 1;
    for(float i = 1; i <= n; i++)
    {
        res *= i;
    } 
    return res;
}
