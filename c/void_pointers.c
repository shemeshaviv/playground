#include <stdio.h>

int main(int argc, char* argv[])
{
    int i = 123;
    float f = 45.6;
    char c = '7';
    void* vptr;

    vptr = &i;
    printf("vptr points to an int  (address: %p) with value: %d\n",(int*) vptr, *(int *)vptr);
    vptr = &f;
    printf("vptr points to a float (address: %p) with value: %.2f\n",(float*) vptr, *(float *)vptr);
    vptr = &c;
    printf("vptr points to a char  (address: %p) with value: %c\n",(char*) vptr, *(char *)vptr);
    return 0;
}
