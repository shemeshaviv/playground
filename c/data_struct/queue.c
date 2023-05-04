#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct NodeStruct
{
    char item;
    struct NodeStruct* next;
};

struct QueueStruct
{
    struct NodeStruct* start;
    struct NodeStruct* end;
};

typedef struct NodeStruct* Node;
typedef struct QueueStruct* Queue;

bool isEmpty(Queue queue)
{
    return (queue->start == NULL);
}

void printQueue(Queue queue)
{
    Node current = queue->start;
    printf("(START) ");
    while(current != NULL)
    {
        printf("%c -> ", current->item);
        current=current->next;
    }
    printf("(END)\n");
}

void enqueue(Queue queue, char item)
{
    Node newNode = (Node)malloc(sizeof(struct NodeStruct));
    newNode->item = item;
    newNode->next = NULL;
    if(isEmpty(queue))
    {
        printf("New STARTING node added with item %c\n",item);
        queue->start = newNode;
        queue->end = newNode;
    }
    else
    {
        printf("New node added with item %c\n", item);
        queue->end->next = newNode;
        queue->end = newNode;
    }
}

char dequeue(Queue queue)
{
    char first_item;;
    if(isEmpty(queue))
        return ' ';
    Node deleted = queue->start;
    first_item= deleted->item;
    printf("Dequeuing first item = %c\n", first_item);
    queue->start = queue->start->next;
    free(deleted);
    return first_item;
}

int main(int argc, char* argv[])
{
    Queue queue = (Queue)malloc(sizeof(struct QueueStruct));;
    queue->start = NULL;
    queue->end = NULL;

    enqueue(queue, 'A');
    printQueue(queue);
    enqueue(queue, 'B');
    printQueue(queue);
    enqueue(queue, 'C');
    printQueue(queue);
    char dequeued = dequeue(queue);
    printQueue(queue);
    return 0;
}
