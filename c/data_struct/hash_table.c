#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 20
#define EMPTY_KEY_VALUE -1

struct KeyValue 
{
   int key;
   int value;
};

struct KeyValue* dummyItem;  // used to point an empty entry

int hashCode(int key)
{
   // The key is numeric, and based on the reminder depending the maximum size
   return key % SIZE;
}

struct KeyValue* search(struct KeyValue* hashArray[], int key) 
{
   int remaining_traverse = SIZE;
   // Get the hash 
   int hashIndex = hashCode(key);  
	
   // Move in array until an empty 
   while(hashArray[hashIndex] != NULL && remaining_traverse--) 
   {
      // There's an item in the hash index. Need to check if it fits the key
      if(hashArray[hashIndex]->key == key)
          return hashArray[hashIndex]; 	
      // Go to next cell
      hashIndex++;
		
      // Wrap around the table
      hashIndex %= SIZE;
   }        
	
   return NULL;        
}

void insert(struct KeyValue* hashArray[], int key, int value)
{
   int remaining_traverse = SIZE;
   struct KeyValue* item = (struct KeyValue*) malloc(sizeof(struct KeyValue));
   item->key = key;
   item->value = value;

   // Get the hash 
   int hashIndex = hashCode(key);

   // Move in array until an empty or deleted cell
   while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != EMPTY_KEY_VALUE)
   {
      // Go to next cell
      hashIndex++;
		
      // Wrap around the table
      hashIndex %= SIZE;
      if(--remaining_traverse == 0)   // This means we travelled the entire hash array 
      {
           printf("No room to store (%d, %d)\n", key, value);
           free(item);
           return;
      }
   }
   // Inserting in the first empty (NULL) match or if the existing key is set to EMPTY_KEY_VALUE (indicating it was deleted)
   hashArray[hashIndex] = item;
}

struct KeyValue* delete(struct KeyValue* hashArray[], struct KeyValue* item)
{
    int remaining_traverse = SIZE;

    if(!item) return NULL;

    int key = item->key;

    // Get the hash 
    int hashIndex = hashCode(key);

    // Travel the array while the array is not empty
    while(hashArray[hashIndex] != NULL && remaining_traverse--)
    {
        if(hashArray[hashIndex]->key == key)
        {
           struct KeyValue* temp = hashArray[hashIndex]; 
           // Assign a dummy item (representing an empty entry) at the deleted position. Marking as deleted
           hashArray[hashIndex] = dummyItem;
           printf("Deleted item (%d,%d)\n", item->key, item->value);
           return temp;
        }
        // Go to next cell
        hashIndex++;
		
        // Wrap around the table
        hashIndex %= SIZE;
    }      
	
    return NULL;        
}

void display(struct KeyValue* hashArray[])
{
   for(int i=0; i<SIZE; i++)
      if(hashArray[i] != NULL)
         printf(" (%d,%d)",hashArray[i]->key,hashArray[i]->value);
      else
         printf(" ~~ ");
   printf("\n");
}

void print_if_item_found(int key, struct KeyValue* item)
{
    if(item != NULL)
       printf("Element with key %d found: %d\n", key, item->value);
    else
       printf("Element with key %d not found\n", key);
}

int main()
{
   // Prepare empty/dummy item where empty entries points to
   dummyItem = (struct KeyValue*) malloc(sizeof(struct KeyValue));
   dummyItem->key = EMPTY_KEY_VALUE; 
   dummyItem->value = EMPTY_KEY_VALUE;
   
   // Create hash-array
   int key, value;
   struct KeyValue* hashArray[SIZE] = {NULL};
   int key_values[14][2] = { {1,20},{2,70},{42,80},{4,25},{12,44},{24,88},{48,99},
                             {36,77},{72,66},{96,55},{60,44},{14,32},{17,11},{13,78} };
   int N = sizeof(key_values) / sizeof(key_values[0]);
   for(int i=0; i < N; i++)
   {
       key = key_values[i][0];
       value = key_values[i][1];
       printf("Iteration: %d. Inserting key=%d, value=%d\n", i, key, value);
       insert(hashArray, key, value);
       display(hashArray);
   }
   //display(hashArray);

   // Search and delete
   struct KeyValue* item;
   int key_to_find = 36;
   item = search(hashArray, key_to_find);
   print_if_item_found(key_to_find, item);
   
   delete(hashArray, item);
   item = search(hashArray, key_to_find);
   print_if_item_found(key_to_find, item);
   return 0;
}
