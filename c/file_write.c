#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 20

struct PersonStruct
{
    int num;
    char firstName[NAME_LENGTH];
    char lastName[NAME_LENGTH];
};

typedef struct PersonStruct* Person;

void writeFile(Person person)
{
    FILE* outputFile;
    char fileName[] = "person.bin";
    outputFile = fopen(fileName,"wb");
    if(outputFile == NULL)
    {
        fprintf(stderr, "\nError opening file for write\n");
        exit(1);
    }

    printf("Writing the following data: %d, %s, %s \n", person->num, person->firstName, person->lastName);
    int rc = 0;
    rc = fwrite(&person, sizeof(struct PersonStruct), 1, outputFile);
    if(rc)
        printf("Successfully written to file %s\n", fileName);
    else
        printf("Error writing to file %s\n", fileName);

    fclose(outputFile);
 
}

int main()
{
    Person person = (Person)malloc(sizeof(struct PersonStruct));
    person->num= 1;
    strcpy(person->firstName,"Aharon");
    strcpy(person->lastName, "Vasershloch");
    writeFile(person);
    return 0;
}
