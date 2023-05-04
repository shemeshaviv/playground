#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int* a, int* b)
{
    if(a == b) return;
    *a = *a + *b;  // a=3,b=4 --> a=a+b=7
    *b = *a - *b;  // a=7,b=4 --> b=a-b=7-4=3
    *a = *a - *b;  // a=7,b=3 --> a=a-b=7-3=4
}

// This function returns an array of random distinctive numbers with no repetitions. Basically by randomzing each subset of array
// where every subset is one less item from the end. The range is 1..N
void randomize(int arr[], const int N)
{
    srand(clock());
    int random_index;
    for(int i=0; i < N; i++)
        arr[i] = i+1;
    for(int j=N-1; j > 0; j--)
    {
        random_item = rand() % j;
        swap(&arr[random_index], &arr[j]);
    }
}

void printArray(int arr[], int N)
{
    for(int i=0; i<N; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(int argc, char* argv[])
{
    int N = 7;
    int ITERATIONS = 5;
    int arr[N];
    for(int i=0; i < ITERATIONS; i++)
    {
        printf("Iteration %d\n", i+1);
        randomize(arr, N);
        printArray(arr, N);
    }
    return 0;
}
