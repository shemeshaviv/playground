#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 10
#define MAX_STRING_SIZE (100)

void print_tokens(char* tokens[], int N)
{
    for(int i=0; i<N; i++)
    {
        if(tokens[i]==NULL)
            break;
        else
            printf("Token[%d] = \"%s\"\n",i,tokens[i]);
    }
}

void tokenize(char* str, char* tokens[], int N)
{
    char* current_token=NULL;
    char* position = str;
    int i;
    for(i = 0;i<MAX_TOKENS;i++)
    {
        current_token=strtok(position,"|");
        position = NULL;
        if(current_token == NULL)
            break;
        tokens[i]=(char*)malloc(MAX_STRING_SIZE * sizeof(char));
        strcpy(tokens[i],current_token);
    }
    if(i==MAX_TOKENS)
    {
        fprintf(stderr,"Reached max tokens. Halting\n");
        exit(-1);
    }
}

void tokenize2(char* original_str, char* tokens[], int N)
{
    char* string_pos;
    char* ptr;
    char* current_token=NULL;
    int i;
    string_pos = original_str;
    for(i = 0;i<MAX_TOKENS;i++)
    {
        current_token=strtok_r(string_pos,"|",&ptr);
        string_pos=NULL;
        if(current_token == NULL)
            break;
        tokens[i]=(char*)malloc(MAX_STRING_SIZE * sizeof(char));
        strcpy(tokens[i],current_token);
    }
    if(i==MAX_TOKENS)
    {
        fprintf(stderr,"Reached max tokens. Halting\n");
        exit(-1);
    }
}

int main(int argc, char* argv[])
{
    const char DEFAULT_STR[] = "This|is a |short string| to token||ize";
    printf("argc: %d\n", argc);
    
    if(argc > 2)
    {
        fprintf(stderr, "Should provide one sting as argument or no argument at all\n");
        return(-1);
    }
    char* str = NULL;
    str = (char*)malloc(MAX_STRING_SIZE*sizeof(char));
    if(argc == 2)
        strncpy(str,argv[1],MAX_STRING_SIZE);
    else
        strncpy(str,DEFAULT_STR,MAX_STRING_SIZE);
    printf("String to tokenize (Length=%ld): \"%s\"\n", strlen(str),str);
    if(strlen(str) == 0)
    {
        fprintf(stderr,"Empty string. Exitting...\n");
        return(-1);
    }
    char* tokens[MAX_TOKENS] = {NULL};

    printf("===== Tokenizing with strtok =======\n");
    tokenize(str, tokens, MAX_TOKENS);
    print_tokens(tokens, MAX_TOKENS);

    printf("===== Tokenizing with strtok_r =======\n");
    tokenize2(str, tokens, MAX_TOKENS);
    print_tokens(tokens, MAX_TOKENS);
    
    return 0;
}

/* OUTPUT:
argc: 1
String to tokenize (Length=38): "This|is a |short string| to token||ize"
===== Tokenizing with strtok =======
Token[0] = "This"
Token[1] = "is a "
Token[2] = "short string"
Token[3] = " to token"
Token[4] = "ize"
===== Tokenizing with strtok_r =======
Token[0] = "This"
Token[1] = "is a "
Token[2] = "short string"
Token[3] = " to token"
Token[4] = "ize"
*/
