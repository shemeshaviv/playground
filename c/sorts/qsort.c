#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int compareFuncInt(const void* a, const void* b) 
{
    return ( *(int*)a - *(int*)b );
}

int compareFuncStrings(const void* a, const void* b)
{
    return strcmp(*(char* const*)a, *(char* const*)b);
}

void printIntArray(int arr[], int N)
{
    for(int i=0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void printStringArray(char* arr[], int N)
{
   for(int i=0; i < N; i++)
       printf("\"%s\" ", arr[i]);
   printf("\n");
}

int main()
{
   // ------ PART I: Integers
   int values[] = {88,56,100,2,25};
   int N = sizeof(values) / sizeof(int);

   printf("Before sorting, the list is: \n");
   printIntArray(values, N);

   qsort(values, N, sizeof(int), compareFuncInt);

   printf("After sorting, the list is: \n");
   printIntArray(values, N);
 
   // ------- PART II: Strings
   char* strings[] = {"this", "is a", "test", "booooewahahah"};
   N = sizeof(strings) / sizeof(char*);
   printf("Size of string array (amount of items): %d\n", N);
   printf("Before sorting, the list is: \n");
   printStringArray(strings, N);

   qsort(strings, N, sizeof(char*), compareFuncStrings);

   printf("After sorting, the list is: \n");
   printStringArray(strings, N);
   return 0;
}
