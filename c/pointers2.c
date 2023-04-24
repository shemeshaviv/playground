#include <stdio.h>
#include <assert.h>

int main() {
    int num = 777;
    int* pnum = NULL;
    
    printf("Value of num: %d\n", num);
    printf("Value of the address of num: %p\n", &num);
    
    pnum = &num;
    printf("Address of pnum: %p\n", (void*)&pnum);
    printf("value of pnum (indicating earlier address on num): %p\n", pnum);
    printf("Value of pnum points to (should be the same value as num): %d\n", *pnum);

    assert(*pnum == num);   // Expecting *pnum == num (777)
    return 0;
}

/*
Value of num: 777
Value of the address of num: 0x7ffdb949badc
Address of pnum: 0x7ffdb949bae0
value of pnum (indicating earlier address on num): 0x7ffdb949badc
Value of pnum points to (should be the same value as num): 777

num (&num = 0x..badc) -> 777
                \
                 ------------\
pnum(&pnum = 0x..bae0) -> 0x..badc 
*pnum = num = 777
*/
