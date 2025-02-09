#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

int main()
{
    int* stack = calloc(1000, sizeof(int));
    uint8_t position = 0;
    char* number = calloc(15, 1);
    uint8_t n_p = 0;
    char c;
    while ((c = getchar()) != '.')
    {
        if(c >= '0' && c <= '9')
            number[n_p++] = c;
        else if (c == ' ' && n_p > 0)
        {
            number[n_p] = '\0';
            stack[position++] = (int)atoi(number);
            n_p = 0;
        }
        else if (c == '+')
        {
            int k = stack[position - 2] + stack[position - 1];
            stack[position - 2] = k;
            position --;

        }
        else if (c == '-')
        {
            int k = stack[position - 2] - stack[position - 1];
            stack[position - 2] = k;
            position --;
        }
        else if (c == '*')
        {
            int k = stack[position - 2] * stack[position - 1];
            stack[position - 2] = k;
            position --;
        }
        else if (c == '/')
        {
            int k = stack[position - 2] / stack[position - 1];
            stack[position - 2] = k;
            position --;
        } 
    }
    printf("%d", stack[position - 1]);
    
    free(stack);
    free(number);
    return 0;
}
