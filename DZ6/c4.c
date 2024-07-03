#include <stdio.h>
int f_x();


int main()
{
    printf("%d\n", f_x());
    return 0;
}





int f_x(void)
{ 
    char buf[100] = {0};
    int i = 0;
    
    while((buf[i] = getchar()))
    { 
        if (buf[0] == '0' || (buf[i] == '0' && buf[i - 1] == ' ') || (buf[i] == '0' && buf[i - 1] == '\n')) break;
        i++;
    }

    int result = 0;
    int b = 0;
    int f = 1;
    int minus_flag = 1;
    int p = 1;

    for(int x = i - 1; x >= 0; x --)
    {
        if(buf[x] > 47 && buf[x] < 58)
        {
            b += (buf[x] - 48) * f;
            f *= 10;
        }
        if(buf[x] == '-') minus_flag = -1;

        if(buf[x] == ' ' || buf[x] == '\n' || x == 0)
        {
            b *= minus_flag;
            int ddd;
            p = b;
            if(b >= -2 && b < 2) ddd = b * b;
            if(b >= 2) ddd = b * b + b * 4 + 5;
            if(b < -2) ddd = 4;

            if(ddd > result) result = ddd;
            minus_flag = 1;
            f = 1;
            b = 0;
        }
    }  
    return result;
}