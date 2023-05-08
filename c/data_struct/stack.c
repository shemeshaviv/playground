#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct NodeStruct
{
    char item;
    struct NodeStruct* next;
};

struct StackStruct
{
    struct NodeStruct* top;
};

typedef struct NodeStruct* Node;
typedef struct StackStruct* Stack;

bool stack_is_empty(Stack stack)
{
    return (stack->top == NULL);
}

void push_stack(Stack stack, char i)
{
    Node newNode = (Node)malloc(sizeof(struct NodeStruct));
    newNode->item = i;
    newNode->next = NULL;
    if(stack_is_empty(stack))
    {
        printf("Created a top from an empty stack\n");
        stack->top = newNode;
    }
    else
    {
        newNode->next = stack->top;
        stack->top = newNode;
    }
    printf("Pushed [%c]\n", stack->top->item);
}

char peek_top_of_stack(Stack stack)
{
    return stack->top->item;
}

Node pop_stack(Stack stack)
{
    if(stack_is_empty(stack))
        return NULL;
    printf("Popping the top [%c]\n", peek_top_of_stack(stack));
    stack->top = stack->top->next;
    return stack->top;
}

void print_stack(Stack stack)
{
    Node currentNode = stack->top;
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
    Stack stack=(Stack)malloc(sizeof(struct StackStruct));
    stack->top = NULL;

    print_stack(stack);
    push_stack(stack, 'A');
    if(stack==NULL) printf("STACK IS NULL\n");
    print_stack(stack);
    push_stack(stack, 'B');
    print_stack(stack);
    push_stack(stack, 'C');
    print_stack(stack);
    pop_stack(stack);
    print_stack(stack);
    free(stack);
    return 0;
}
