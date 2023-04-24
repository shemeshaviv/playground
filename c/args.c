#include <stdio.h>

int main(int argc, char* argv[])
{
    int numberOfArguments = argc;
    printf("Number of arguments: %d\n", numberOfArguments);
    if(argc != 2)
    {
        printf("Need a single argument to run this\n");
        return 1;
    }
    char* argument0 = argv[0];
    char* argument1 = argv[1];
    printf("Argument 0 is the program name: %s\n", argument0);
    printf("Argument 1 is the command line argument: %s\n", argument1);
    return 0;
}
