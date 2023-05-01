#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    char item;
    struct Node* next;
};

typedef struct Node* node;

bool stack_is_empty(node top)
{
    return (top == NULL);
}

node push_stack(node top, char i)
{
    node newNode = (node)malloc(sizeof(struct Node));
    newNode->item = i;
    newNode->next = NULL;
    if(stack_is_empty(top))
    {
        printf("Created a top from an empty stack\n");
        top = newNode;
    }
    else
    {
        newNode->next = top;
        top = newNode;
    }
    printf("Pushed [%c]\n", top->item);
    return top;
}

char peek_top_of_stack(node top)
{
    return top->item;
}

node pop_stack(node top)
{
    if(stack_is_empty(top))
        return NULL;
    printf("Popping the top [%c]\n", peek_top_of_stack(top));
    top = top->next;
    return top;
}

void print_stack(node top)
{
    node currentNode = top;
    printf("(top) -> ");
    while(currentNode != NULL)
    {
        printf("[%c] -> ",currentNode->item);
        currentNode = currentNode->next;
    }
    printf("|\n");
}

int main(int argc, char* argv[])
{
    node stack=NULL;
    print_stack(stack);
    stack=push_stack(stack, 'A');
    if(stack==NULL) printf("STACK IS NULL\n");
    print_stack(stack);
    stack=push_stack(stack, 'B');
    print_stack(stack);
    stack=push_stack(stack, 'C');
    print_stack(stack);
    stack=pop_stack(stack);
    print_stack(stack);
    free(stack);
    return 0;
}
