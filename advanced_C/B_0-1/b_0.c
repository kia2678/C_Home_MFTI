#include <stdio.h>
#include<stdint.h>
#include <stdlib.h>

typedef struct list {
uint64_t address;
size_t size;
char comment[64];
struct list *next;
} list;

uint64_t findMaxBlock(list *head);

int main()
{
    list* top = NULL;

    printf("%llu", findMaxBlock(top));
    return 0;
}


uint64_t findMaxBlock(list *head)
{
    if(head == NULL)
        return (uint64_)head;
    size_t max = 0;
    uint64_t addr = 0;
    list* find = head;
    while (find != NULL)
    {
        if(find->size > max)
        {
            max = find->size;
            addr = find->address;
        }
        find = find->next;
    }
    return addr;
}