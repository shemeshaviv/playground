#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING_SIZE 100

void substring(char* destination, const char* source, int begin, int length)
{
    while(length>0)
    {
        *destination = *(source + begin);
        destination++;
        source++;
        length--;
    }
    destination='\0';
}

int main(int argc, char* argv[])
{
    char source[] = "Extracting a sub-string from this source string";
    char destination[MAX_STRING_SIZE];     //Same as: char* destination = (char*)malloc(MAX_STRING_SIZE * sizeof(char));
    
    substring(destination, source, 11, 12);
    printf("Source  string: \"%s\"\n", source);
    printf("Dest substring: \"%s\"\n", destination);
    return 0;
}
