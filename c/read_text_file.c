#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STRING_SIZE 255
#define PRINT_RULER printf("----------------------------------------------------\n")

void write_new_file()
{
    int len;
    FILE* fp;
    fp = fopen("text_file.txt","w");
    if(fp == NULL)
    {
        fprintf(stderr,"Error opening text file for writing\n");
        exit(1);
    }
    fputs("This is the first line.\n", fp);
    fputs("Now going to the second line.\n", fp);
    fputs("Finishing in this last line; Thank you.\n", fp);
    len = ftell(fp);
    fclose(fp);
    fp=NULL;
    printf("New text_file.txt written successfully (last file position: %d)\n", len);
}

void print_content_char_by_char(FILE* file, bool to_uppercase)
{
    char c;
    while((c = fgetc(file)) != EOF)
    {
        if(to_uppercase && c >= 'a' && c <= 'z')
            c = c - 'a' + 'A';
        printf("%c", c);
    }
}

void print_reverse_content(FILE* file)
{
    char c;
    int position;
    fseek(file, -1, SEEK_END);
    position = ftell(file);
    do
    {
        fseek(file, position, SEEK_SET);
        c = fgetc(file);
        printf("%c", c);
        position--;
    } while(position >= 0);
    printf("\n");
}

void print_content_line_by_line(FILE* file)
{
    char string[MAX_STRING_SIZE];
    while(fgets(string,MAX_STRING_SIZE,file) != NULL)
    {
        printf("%s", string);
    }
}

int main(int argc, char* argv[])
{
    write_new_file();
    
    FILE* file;
    file = fopen("text_file.txt","r");
    if(file == NULL)
    {
        fprintf(stderr, "Error opening text file\n");
        exit(1);
    }
    printf("Content of file, character by character using fgetc:\n");
    PRINT_RULER;
    print_content_char_by_char(file, false);
    PRINT_RULER;

    printf("Again: Content of file, this time - line by line using fgets:\n");
    PRINT_RULER;
    rewind(file); // Equivilent to: fseek(file, 0, SEEK_SET);
    print_content_line_by_line(file);
    PRINT_RULER;

    printf("Again: Content of file, this time - uppercase:\n");
    PRINT_RULER;
    rewind(file); // Equivilent to: fseek(file, 0, SEEK_SET);
    print_content_char_by_char(file, true);
    PRINT_RULER;

    printf("Again: Content of file, this time - in reverse order:\n");
    PRINT_RULER;
    rewind(file); // Equivilent to: fseek(file, 0, SEEK_SET);
    print_reverse_content(file);
    PRINT_RULER;

    fclose(file);
    file=NULL;

    printf("Press ENTER to quit\n");
    getchar();
    return 0;
}
