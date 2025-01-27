#include <stdio.h>
#include<stdint.h>
#include <stdlib.h>

typedef struct list {
void *address;
size_t size;
char comment[64];
struct list *next;
} list;

size_t totalMemoryUsage(list *head);

int main()
{
    list* top = NULL;

    printf("%llu", totalMemoryUsage(top));
    return 0;
}


size_t totalMemoryUsage(list *head)
{
    if(head == NULL)
        return (size_t)NULL;
    size_t sum = 0;
    list* find = head;
    while (find != NULL)
    {
        sum += find->size;
        find = find->next;
    }

    return sum;
}