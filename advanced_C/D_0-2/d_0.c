#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef struct list 
{
    char word[20];
    struct list *next;
}list;

void add_to_list(list** head, char str[], size_t n)
{
    list* add = malloc(sizeof(list));
    add->next = *head;
    for(int i = 0; i < n; i++)
        add->word[i] = str[i];
        add->word[n] = '\0';
    *head = add;
}

void print_list(list* head)
{
    if(head == NULL)
        return;
    while (head != NULL)
    {
        printf("%s ", head->word);
        head = head->next;
    }
}

void swap_elements(list** head)
{
    if(*head == NULL)
        return;
    list*prev, *nxt, *buf;
    int flag;
    do
    {
        prev = *head;
        buf= (*head)->next;
        flag = 0;  
        if((*head)->next != 0 && strcmp((*head)->word, (*head)->next->word) > 0)
        {
            list* nb;
            nxt = (*head)->next->next;
            nb = *head;
            *head = (*head)->next;
            (*head)->next = nb;
            (*head)->next->next = nxt;
            flag++;
            buf = (*head)->next;
            prev = *head;
        }

        while (buf->next != NULL)
        {
            if(strcmp(buf->word, buf->next->word) > 0)
            {
                list* nb;
                nxt = buf->next->next;
                nb = buf;
                buf = buf->next;
                prev->next = buf;
                buf->next = nb;
                buf->next->next = nxt;
                flag++;
            }
            
            prev = buf;
            buf = buf->next;  
        }
    } while (flag);  
}

void delete_list(list** head)
{
    if(*head == NULL)
        return;
    list* pr_del = *head;
    while(pr_del != NULL)
    {
        pr_del = (*head)->next;
        free(*head);
        *head = pr_del;
    }
}

int main()
{
    list* list_str = NULL;
    char buf[20] = {0};
    size_t n = 0;
    char c = 0;
    while ((c = getchar()) != '.')
    {
        buf[n] = c;
        n++;
        if(c == ' ')
        {
            buf[n - 1] = '\0';
            add_to_list(&list_str, buf, n);
            n = 0;
        }
    } 
    buf[n] = '\0';
    add_to_list(&list_str, buf, n); 
    swap_elements(&list_str);
    print_list(list_str);
    delete_list(&list_str);
    return 0;
}