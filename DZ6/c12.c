#include <stdio.h>
#include <math.h>
float sinus(float x);
float factorial(float n);

int main()
{
    float a;
    scanf("%f", &a);
    a = a * 3.14 / 180;
    
    printf("%.3f\n", sinus(a));
    return 0;
}



float sinus(float x)
{
    float res = x;
    for(int i = 3, zn = 2 ; i < 11; i +=2, zn++)
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

