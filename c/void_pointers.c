#include <stdio.h>

int main(int argc, char* argv[])
{
    int i = 123;
    float f = 45.6;
    char c = '7';
    void* vptr;

    vptr = &i;
    printf("vptr points to an integer with value: %d\n", *(int *)vptr);
    vptr = &f;
    printf("vptr points to a float with value: %.2f\n", *(float *)vptr);
    vptr = &c;
    printf("vptr points to a char with value: %c\n", *(char *)vptr);
    return 0;
}
