#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
int pref_suf(char* a, char* b, size_t n_a, size_t n_b);

int main()
{
    char* s_1 = calloc(2010, sizeof(char));
    char* s_2 = calloc(2010, sizeof(char));
    scanf("%s\n%s", s_1, s_2);
    size_t n_1 = strlen(s_1);
    size_t n_2 = strlen(s_2);

    printf("%d %d", pref_suf(s_1, s_2, n_1, n_2), pref_suf(s_2, s_1, n_2, n_1));

    free(s_1);
    free(s_2);

    return 0;
}

int pref_suf(char* a, char* b, size_t n_a, size_t n_b)
{
    int count = 0;
    int cnt = 0;

    for(int i = 0; i < n_a; i++)
    {
        if (b[n_b-1] == a[i])
        {
            for (int j = i, k = n_b-1; j >= 0; j--, k--)
            {
                
                if(a[j] == b[k])
                    cnt++;
                else 
                {
                    cnt = 0;
                    break;
                }
            }
        }
        if(cnt > count)
            count = cnt;
        cnt = 0;
    }

    return count;    
}