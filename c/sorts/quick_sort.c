// C code to implement quicksort

#include <stdio.h>
#define ARRAY_SIZE 6

// Function to swap two elements
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

// Swapping numbers without an addition variable
void swap_num(int* a, int* b)
{
    if(a == b) return; // We don't want to override the same address. This will break the following calculations
    *a = (*a) + (*b);  // Can also replace the operation with XOR (^)
    *b = (*a) - (*b);  // Can also replace the operation with XOR (^)
    *a = (*a) - (*b);  // Can also replace the operation with XOR (^)
}

void printArray(int arr[], const int SIZE)
{
    for(int i=0; i < SIZE; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Partition the array using the last element as the pivot
int partition(int arr[], int low, int high)
{
	// Choosing the pivot as the last item
	int pivot = arr[high];
	
	// Index of smaller element and indicates
	// the right position of pivot found so far
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) 
    {	
		// If current element is smaller than the pivot
		if (arr[j] < pivot) 
        {	
			// Increment index of smaller element
			i++;
            printf("Pivot is %d, swapping between %d and %d:\n", pivot, arr[i], arr[j]);
			swap_num(&arr[i], &arr[j]);
            printArray(arr, ARRAY_SIZE);
		}
	}
    printf("Finished looping. Pivot is %d, swapping between %d and %d:\n", pivot, arr[i+1], arr[high]);
	swap_num(&arr[i + 1], &arr[high]);
    printArray(arr, ARRAY_SIZE);
	return (i + 1);
}

// The main function that implements QuickSort
// arr[] --> Array to be sorted,
// low --> Starting index,
// high --> Ending index
void quickSort(int arr[], int low, int high)
{
	if (low < high) {
		
		// pi is partitioning index, arr[p]
		// is now at right place
		int pi = partition(arr, low, high);
		
		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

int main()
{
	int arr[] = { 10, 7, 9, 8, 1, 5 };
	int N = sizeof(arr) / sizeof(arr[0]);
    printf("Initial (unsorted) array:\n");
    printArray(arr, N);
    printf("(Array Size: %d)\n", N);
    
    printf("Sorting....\n");
	quickSort(arr, 0, N - 1);
	printf("Sorted array: \n");
    printArray(arr, N);
	return 0;
}

