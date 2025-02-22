#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
//===ключ-значение для функции===
#define k 13
//===============================
typedef int32_t datatype;

typedef struct tree
{
    datatype key;
    struct tree *left, *right;
    struct tree *parent; // ссылка на родителя
} tree;

void add_to_tree(tree** top, datatype n)
{
    tree* br = malloc(sizeof(tree));
    br->left = NULL;
    br->right = NULL;
    br->parent = NULL;
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
                    buf->right->parent = buf;
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
                    buf->left->parent = buf;
                    flag = 0;
                }
                else
                    buf = buf->left;
            }
        } while (flag);
    }
}

tree* findBrother(tree *root, int key)
{
    if(root == NULL)
        return  NULL;
    tree* buf = root;
    while(1)
    {
        if (buf->key == key)
        {
            if (buf->parent == NULL)
                return NULL;
            if (buf->parent->left == buf)
                return (buf->parent->right != NULL) ? buf->parent->right : NULL;
            if (buf->parent->right == buf)
                return (buf->parent->left != NULL) ? buf->parent->left : NULL;
        }
        if (buf->key < key)
        {
            if (buf->right == NULL)
                return NULL;
            buf = buf->right;
        }
        if (buf->key > key)
        {
            if (buf->left == NULL)
                return NULL;
            buf = buf->left;
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
    add_to_tree(&top, atoi(buf));
    tree* fd = findBrother(top, k);
    if(fd == NULL)
        printf("NULL");
    else
    printf("%d", fd->key);
    return 0;
}