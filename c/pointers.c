#include <stdio.h>
#include <stdint.h>

int main()
{
    int x = 0x12345678;
    char* p = (char*) &x;
    int i;
    printf("The value of x is 0x%x . Sizeof(x)=%ld\n", x, sizeof(int));
    for(i=0; i<sizeof(int); i++)
    {
        printf("Pointer %p, Value: 0x%x \n", p, *p);
        p++;
    }
    return 0;
}

