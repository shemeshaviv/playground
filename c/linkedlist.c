#include <stdio.h>
#include <stdlib.h>

struct LinkedList
{
    int value;
    struct LinkedList* next;
};

typedef struct LinkedList *node;    // Define node as pointer of data type struct LinkedList

node createNode()
{
    node newNode;                                      // Declare a node
    newNode = (node)malloc(sizeof(struct LinkedList)); // Allocate memory using malloc()
    newNode->next = NULL;                              // Make next point to NULL
    return newNode;                                    // Return the new node
}

node addNode(node root, int value)
{
    node newNode, currentNode; 
    newNode = createNode(); // Will return a new node with data = value and next pointing to NULL.
    newNode->value = value; // Add element's value to data part of node
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

node addNodeSorted(node root, int value)
{
    node newNode, currentNode;
    newNode = createNode();
    newNode->value = value;
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


void printLinkedList(node root)
{
    node current = root;
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
    node root;
    int values[] = {5,3,10,7};
    for(int i=0; i < sizeof(values) / sizeof(int); i++)
    {
        root = addNodeSorted(root, values[i]);
        printf("Added %d\n", values[i]);
        printLinkedList(root);
    }
    return 0;
}
