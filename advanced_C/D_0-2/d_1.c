#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef int32_t datatype;

typedef struct tree 
{
    datatype key;
    struct tree *left, *right;
} tree;

void add_to_tree(tree** top, datatype n)
{
    tree* br = malloc(sizeof(tree));
    br->left = NULL;
    br->right = NULL;
    br->key = n;

    if(*top == NULL) 
        *top = br;
    else
    {
        int flag = 1;
        tree* buf = *top;
        do
        {
            if(n > buf->key)
            {
                if(buf->right == NULL)
                {
                    buf->right = br;
                    flag = 0;
                }
                else
                    buf = buf->right;
            }
            if(n < buf->key)
            {
                if(buf->left == NULL)
                {
                    buf->left = br;
                    flag = 0;
                }
                else
                    buf = buf->left;
            }
        } while (flag);
    }
}
void btUpView(tree *root)
{
    int flag_r = 0;
    tree* last = NULL;
    tree* buf = root;
    if(root == NULL)
        return;
    while (flag_r == 0)
    {
        if(last == root->left)
        {
            flag_r = 1;
            break;
        }           
        if(buf->left == last)
        {
            printf("%d ", buf->key);
            last = buf;
            buf = root;
        }
        else
            buf = buf->left;            
    }
    while (flag_r)
    {
        if(buf->right == NULL)
        {
            printf("%d ", buf->key);
            return;
        }
        else
        {
            printf("%d ", buf->key);
            buf = buf->right;
        } 
    }
}

int main()
{
    tree* top = NULL;
    char buf[20] = {0};
    size_t n = 0;
    char c = 0;
    while ((c = getchar()) != '\n')
    {
        buf[n] = c;
        n++;
        if(c == ' ')
        {
            buf[n - 1] = '\0';
            add_to_tree(&top, atoi(buf));
            n = 0;
        }
    } 
    buf[n] = '\0';
    btUpView(top);
    return 0;
}