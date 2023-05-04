#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

struct NodeStruct
{
    int value;
    struct NodeStruct* next;
};

struct LinkedListStruct
{
    struct NodeStruct* root;
};

typedef struct NodeStruct* Node;              // Define node as pointer of data type struct Node
typedef struct LinkedListStruct* LinkedList;  // Define linked-list as pointer of data type struct linked-list

Node createNode(int value)
{
    Node newNode;                                      // Declare a node
    newNode = (Node)malloc(sizeof(struct NodeStruct)); // Allocate memory using malloc()
    newNode->next = NULL;                              // Make next point to NULL
    newNode->value = value;                            // Set value
    return newNode;                                    // Return the new node
}

void addNode(LinkedList linkedlist, int value)
{
    Node newNode, currentNode; 
    newNode = createNode(value); // Will return a new node with data = value and next pointing to NULL.
    if(linkedlist->root == NULL)
    {
        linkedlist->root = newNode;     // When linked list is empty, set root as the new node
    }
    else
    {
        currentNode  = linkedlist->root;             // set current-node as root
        while(currentNode->next != NULL)
        {
            //traverse the list until currentNode is the last node.The last node always points to NULL.
            currentNode = currentNode->next; 
        }
        currentNode->next = newNode;   //Point the previous last node to the new node created.
    }
}

void addNodeSorted(LinkedList linkedlist, int value)
{
    Node newNode, currentNode;
    newNode = createNode(value);
    if(linkedlist->root == NULL)
    {
        linkedlist->root = newNode;
    }
    else
    {
        if(linkedlist->root->value > value)
        {
            newNode->next = linkedlist->root;
            linkedlist->root = newNode;
        }
        else
        {
            currentNode = linkedlist->root;
            while(currentNode->next != NULL && currentNode->next->value < value)
            {
               currentNode = currentNode->next;
            }
            newNode->next = currentNode->next;
            currentNode->next = newNode;
        }
    }
}

void removeNode(LinkedList linkedlist, int value)
{
    if(linkedlist->root == NULL)
    {
        printf("Linked list is already empty\n");
        return;
    }
    while((linkedlist->root->value == value) && (linkedlist->root->next != NULL))
    {
        Node old_root = linkedlist->root;
        linkedlist->root = linkedlist->root->next;
        free(old_root);
    }
    Node currentNode = linkedlist->root;
    Node previousNode = currentNode;
    while(currentNode != NULL)
    {
        if(currentNode->value == value)
        {
            previousNode->next = currentNode->next;
            free(currentNode);
            currentNode=previousNode->next;
        }
        else
        {
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
    }
}

void printLinkedList(LinkedList linkedlist)
{
    Node current = linkedlist->root;
    printf("(root) -> ");
    while(current!=NULL)
    {
        printf("%d -> ", current->value);
        current = current -> next;
    }
    printf("(NULL)\n");
}

int main()
{
    LinkedList linkedlist = (LinkedList)malloc(sizeof(struct LinkedListStruct));
    linkedlist->root = NULL;

    int values[] = {5,3,10,7};
    for(int i=0; i < sizeof(values) / sizeof(int); i++)
    {
        addNodeSorted(linkedlist, values[i]);
        printf("Added %d\n", values[i]);
        printLinkedList(linkedlist);
    }
    removeNode(linkedlist, 7);
    printf("Removed 7\n");
    printLinkedList(linkedlist);

    return 0;
}
