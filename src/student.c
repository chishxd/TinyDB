#include "student.h"
#include <stdio.h>
#include <string.h>

//This function adds new Records of Students
// Student is a structure with members: roll_no, name, age and marks
// Count is used to know the length of array
void add_student(Student students[100], int* count)
{
    if (*count >= 100)
    {
        printf("Error: Too many students\n");
        return;
    }
    int roll_no;
    char name[50];
    int age;
    float marks;

    printf("Enter Roll No: ");
    if (scanf("%d", &roll_no) != 1)
    {
        printf("Invalid roll number\n");
        return;
    }
    getchar(); // Consume the newline character left by scanf
    printf("Enter Name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // Remove trailing newline from fgets

    printf("Enter Age: ");
    if (scanf("%d", &age) != 1)
    {
        printf("Invalid age\n");
        return;
    }

    printf("Enter Marks: ");
    if (scanf("%f", &marks) != 1)
    {
        printf("Invalid Marks\n");
        return;
    }


    students[*count].roll_no = roll_no;
    strcpy(students[*count].name, name);
    students[*count].age = age;
    students[*count].marks = marks;

    (*count)++;
}

