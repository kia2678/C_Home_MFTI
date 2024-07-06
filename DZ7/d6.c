#include <stdio.h>
void reverse_string();

int main()
{
    reverse_string();
    return 0;
}

void reverse_string()
{
    char a; 
    a = getchar();
   if(a != '.')
   {
        reverse_string();
        printf("%c", a);
   } 
    return;
}