#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "library.h"

int Add_Student()
{
    Student newStudent;
    FILE *student_info = NULL;

    printf("Enter the Name: \n");
    if (fgets(newStudent.name, sizeof(newStudent.name), stdin) == NULL)
    {
        printf("Error reading name.\n");
        return 1;
    }
    newStudent.name[strcspn(newStudent.name, "\n")] = '\0'; /*newStudent madhe enter la space ne replace*/

    printf("Enter Student ID (Roll number): \n");
    if (scanf("%d", &newStudent.ID) != 1)
    {
        printf("Invalid ID. Please enter a number.\n");
        return 1;
    }
    clearInputBuffer();

    printf("Enter student grade: \n");
    if (scanf(" %c", &newStudent.grade) != 1)
    {
        printf("Invalid grade. Please enter a single character.\n");
        return 1;
    }
    clearInputBuffer();

    student_info = fopen("stud_info.txt", "a");
    if (student_info == NULL)
    {
        printf("File can't be opened! An error occurred!!\n");
        return 1;
    }

    fprintf(student_info, "%s\t%d\t%c\n", newStudent.name, newStudent.ID, newStudent.grade);
    printf("Data saved successfully.\n");

    fclose(student_info);
    return 0;
}

int Display_Student()
{
    FILE *student_info = NULL;
    char line_buffer[256]; /* Temprarory Arry display karnya sathi*/

    student_info = fopen("stud_info.txt", "r");

    if (student_info == NULL)
    {
        printf("Error: No student data found or file could not be opened.\n");
        return 1;
    }

    printf("\n--- Displaying All Students ---\n");
    printf("Name             ID     Grade\n");
    printf("-----------------------------------\n");

    int students_found = 0;
    while (fgets(line_buffer, sizeof(line_buffer), student_info) != NULL)
    {
        printf("%s", line_buffer);
        students_found = 1;
    }

    if (students_found == 0)
    {
        printf("No students records found in the file.\n");
    }
    printf("-----------------------------------\n\n");

    fclose(student_info);
    return 0;
}

int Search_Student()
{
    int search_num;
    FILE *student_info = NULL;
    if (student_info == NULL)
        printf("Error occoured during opening of file. Fuck off!! :(");
    student_info = fopen("stud_info.txt", "r");
    printf("Enter his roll Number:");
    if (scanf(" %d", &search_num) != 1)
    {
        printf("Invalid Input");
        return 1;
    }
    clearInputBuffer();
}

void Update_list()
{
    printf("Hello!!");
}

void Delete_Record()
{
    FILE *student_info = NULL;
    student_info = fopen("stud_info.txt", "w");
    if (student_info == NULL)
    {
        printf("'File is already empty!\n");
        return;
    }

    fclose(student_info);
    return 0;
}

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}
