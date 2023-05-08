#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define DEBUG true

void debug(char *pointer)
{
    if(DEBUG)
        printf("%p: %c\n", pointer, *pointer);
}

int str_length(char* string)
{
    int len = 0;
    char* c = string;
    while(*c != '\0')
    {
        len++;
        c++;
    }     
    return len;
}

int str_length2(char string[])
{
    int i;
    for(i = 0; string[i] != '\0'; i++);
    return i;
}

void swap(char* p, char* q)
{
    char tmp;
    tmp = *p;
    *p = *q;
    *q = tmp;
}

void reverse_string(char* string)
{
    char* p = string;
    char* q = p + str_length(string)-1;  // Or use the built-in strlen() in string.h
    while(p < q)
    {
       swap(p, q);
       debug(p);
       debug(q);

       p++;
       q--;
    }
    printf("\n");
}

int main()
{
    char string[] = "Reversed!";
    printf("  String: %s\n\n", string);
    reverse_string(string);
    printf("Reversed: %s\n", string);
}
