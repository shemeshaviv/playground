#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 3

struct StudentStruct
{
    char name[200];
    int age;
    double average;
};

typedef struct StudentStruct* Student;

bool write_data(char* filename, Student data, int total);
Student read_data(char* filename, int* total);


bool write_data(char* filename, Student data, int total)
{
    FILE* file;
    file = fopen(filename, "wb");
    if(file == NULL)
    {
        fprintf(stderr, "Error opening file");
        return false;
    }
    // Write how many records are expected to be written at the beginning of the file
    if(fwrite(&total, sizeof(int), 1, file) != 1)
        return false;

    // Write the data, and expect fwrite to return the total record amount 
    if(fwrite(data, sizeof(struct StudentStruct), total, file) != total)
        return false;
    
    if(fclose(file) == EOF)
        return false;

    return true;
}

Student read_data(char* filename, int* total)
{
    FILE* file;
    file = fopen(filename, "rb");
    if(file == NULL) return NULL;
    // Read the total value from the top of the file. Expecting the value of 1 item
    if(fread(total,sizeof(int),1,file) != 1) 
    {
        printf("Error when trying to read the top total value\n");
        return NULL;
    }
    Student data = (Student)malloc(sizeof(struct StudentStruct) * *total);
    if(fread(data, sizeof(struct StudentStruct), *total, file) != *total)
    {
        printf("Error when trying to read the records\n");
        free(data);
        return NULL;
    }
    if(fclose(file) == EOF)
    {
        printf("Error when trying to close the file after reading the records\n");
        free(data);
        return NULL;
    }
    return data;
}

int main()
{
    Student students;
    students = (Student)malloc(sizeof(struct StudentStruct) * SIZE);
    printf("Populating students\n");
    strcpy(students[0].name, "John");
    students[0].age = 19;
    students[0].average = 80.25;
    strcpy(students[1].name, "Buba");
    students[1].age = 20;
    students[1].average = 86.75;
    strcpy(students[2].name, "Smith");
    students[2].age = 21;
    students[2].average = 85.5;
    char filename[] = "students.bin";

    // WRITE
    printf(" === Part I: Writing\n");
    bool success = write_data(filename, students, SIZE);
    if(success)
    {
        printf("Written successfully\n");
    }
    else
    {
        printf("Something went wrong. Exiting\n");
        return 1;
    }

    free(students);

    // READ
    printf(" === Part II: Reading\n");
    int total = 0;
    Student file_data;
    file_data = read_data(filename, &total);
    if(file_data == NULL)
    {
        printf("Error reading from file\n");
        return 1;
    }
    printf("Data read OK, total of %d records\n", total);
    for(int i=0; i < total; i++)
    {
        printf("Student %d: ", i+1);
        printf("(name = %s, age = %d, average = %.2f)\n", file_data[i].name, file_data[i].age, file_data[i].average);
    }
    free(file_data);
    return 0;
}
