#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

struct LinkedList
{
    int value;
    struct LinkedList* next;
};

typedef struct LinkedList* Node;    // Define node as pointer of data type struct LinkedList

Node createNode(int value)
{
    Node newNode;                                      // Declare a node
    newNode = (Node)malloc(sizeof(struct LinkedList)); // Allocate memory using malloc()
    newNode->next = NULL;                              // Make next point to NULL
    newNode->value = value;                            // Set value
    return newNode;                                    // Return the new node
}

Node addNode(Node root, int value)
{
    Node newNode, currentNode; 
    newNode = createNode(value); // Will return a new node with data = value and next pointing to NULL.
    if(root == NULL)
    {
        root = newNode;     // When linked list is empty, set root as the new node
    }
    else
    {
        currentNode  = root;             // set current-node as root
        while(currentNode->next != NULL)
        {
            //traverse the list until currentNode is the last node.The last node always points to NULL.
            currentNode = currentNode->next; 
        }
        currentNode->next = newNode;   //Point the previous last node to the new node created.
    }
    return root;
}

Node addNodeSorted(Node root, int value)
{
    Node newNode, currentNode;
    newNode = createNode(value);
    if(root == NULL)
    {
        root = newNode;
    }
    else
    {
        if(root->value > value)
        {
            newNode->next = root;
            root = newNode;
        }
        else
        {
            currentNode = root;
            while(currentNode->next != NULL && currentNode->next->value < value)
            {
               currentNode = currentNode->next;
            }
            newNode->next = currentNode->next;
            currentNode->next = newNode;
        }
    }
    return root;
}

Node removeNode(Node root, int value)
{
    if(root == NULL)
       return NULL;
    while((root->value == value) && (root->next != NULL))
    {
        Node old_root = root;
        root = root->next;
        free(old_root);
    }
    Node currentNode = root;
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
    return root;
}

void printLinkedList(Node root)
{
    Node current = root;
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
    Node root;
    int values[] = {5,3,10,7};
    for(int i=0; i < sizeof(values) / sizeof(int); i++)
    {
        root = addNodeSorted(root, values[i]);
        printf("Added %d\n", values[i]);
        printLinkedList(root);
    }
    root = removeNode(root, 7);
    printf("Removed 7\n");
    printLinkedList(root);

    return 0;
}
