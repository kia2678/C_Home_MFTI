#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

int check_rep(uint16_t* w_buf, uint16_t n_b, size_t count);
int it_over_srt (char* strn, uint16_t* w_buf, size_t n);

int main()
{
    char* str = calloc(100, sizeof(char));
    scanf("%s", str);
    uint16_t* win_buf = calloc(1000, sizeof(uint16_t));
    
    size_t size_str = strlen(str);
    printf("%d", it_over_srt(str, win_buf, size_str));
    free(str);
    free(win_buf);
    return 0;
}

int check_rep(uint16_t* w_buf, uint16_t n_b, size_t count)
{
    for(int i = 0; i < count; i++)
    {
        if(n_b < 100 || w_buf[i] == n_b)
            return 0;
    }
    return 1;
}

int it_over_srt (char* strn, uint16_t* w_buf, size_t n)
{
    int res = 0;
    for(int i = 0; i<n-2; i++)
    {
        uint16_t n_100 = (strn[i] - '0')*100;
        for(int j = i+1; j<n-1; j++)
        {
            uint16_t n_10 = (strn[j] - '0')*10;
            for(int k = j+1; k<n; k++)
            {
                uint16_t n_buf = n_100 + n_10 +((strn[k] - '0'));
                if(check_rep(w_buf, n_buf, res))
                {
                    w_buf[res++] = n_buf;
                }
            }
        }
    }
    return  res;
}