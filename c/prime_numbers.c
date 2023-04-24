#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[100] = {2,3}; // Storing the prime numbers. All other items will be zero
    int current = 2;// Current iterator
    for(int i=5; i<100; i+=2)
    {
        int j;
        for(j=i-1; j>1; j--)
            if((i % j) == 0) break;
        if(j == 1) arr[current++] = i;
    }
    for(int i=0; i<current; i++)
        printf("%d, ", arr[i]);
    printf("\n");
    return 0;
}
