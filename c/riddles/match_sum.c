#include <stdio.h>
#include <stdlib.h>

void printArray(int a[], int n)
{
    for(int i=0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

int matchSum(int a[], int n)
{
    //int m = sizeof(a) / sizeof(a[0]);
    int sum = 0;
    int max = 0;
    int maxPos = -1;
    int operationCount = 0;  // division count that we return
    while(sum != n)          // sum == n means each item is 1
    {
        sum = 0;
        max = 0;
        maxPos = -1;
        for(int i=0; i < n; i++)
        {  
            if(a[i] > max)   // choosing the maximum valued item as a candidiate to divide
            {
                maxPos = i;  // keeping its location and updating the max value
                max = a[i];
            }
            sum+= a[i];      // updating total sum
        }
        if((sum > n) && (a[maxPos] != 1)) 
        {
            a[maxPos]/= 2;
            operationCount++;
            printArray(a,n);
        }
        if(sum == n)
            return operationCount;
    }
    return -1;
}

int main()
{
    int arr[] = {1,2,32,1,1};
    int N = sizeof(arr) / sizeof(int);
    int operationCount = 0;

    printArray(arr,N);
    operationCount = matchSum(arr, N);
    printf("Amount of operations: %d\n", operationCount);
    return 0;
}
