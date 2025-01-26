#include <stdio.h>
#include<stdint.h>

struct pack_array 
{
uint32_t array; // поле для хранения упакованного массива из 0 и 1
uint32_t count0 : 8; // счетчик нулей в array
uint32_t count1 : 8; // счетчик единиц в array
};
int ar[32] = {0};
void array2struct(int arg[], struct pack_array * str);
int main()
{
    struct pack_array ctct = {0,0,0};
    for(int i = 0; i < 32; i++)
        scanf("%d", &ar[i]);
    
    array2struct(ar, &ctct);
    printf("%u %u %u", ctct.array, ctct.count0, ctct.count1);
   
    return 0;
}

void array2struct(int arg[], struct pack_array * str)
{
    for(int i = 0; i < 32; i++)
    {
        if(arg[i])
        {
            str->count1++;
            str->array |= 1 << 31 - i;
        }
        else
        {
            str->count0++;
            str->array |= 0 << i; 
        }
    }
}