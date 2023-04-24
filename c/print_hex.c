#include <stdio.h>

#define SIZE 8

void print_hex(int number)
{
    char hex_value[SIZE] = {"0"};
    int reminder;
    int i = SIZE - 1;
    while(number > 0)
    {
        reminder = number % 16;
        number = number / 16;
        if(reminder >= 10)
        {
            hex_value[i] = 'a' + reminder - 10;
        }
        else
        {
            hex_value[i] = '0' + reminder;
        }
        i--;
    }
    printf("0x");
    for(int i=0; i < SIZE; i++) printf("%c",hex_value[i]);
    printf("\n");
}

int main()
{
    print_hex(31);
    return 0;
}
