#include <stdio.h>
#include<stdint.h>

int extractExp(float f_data);

int main()
{
    float N; 
    scanf("%f", &N);
    printf("%d", extractExp(N));
    return 0;
}


int extractExp(float f_data)
{
    union f_int_d
    {
        float f;
        uint32_t d;
    } fid; 
    fid.f = f_data;
    int res = 0;
    for(int i = 30; i >= 23; i--)
    {
        res <<= 1;
        res |= ((fid.d >> i) & 1);
    }
}