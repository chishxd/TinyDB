#ifndef LIBRARY_H
#define LIBRARY_H

typedef struct Student
{
    char name[100];
    char grade;
    int ID;
} Student;

void clearInputBuffer();
int Add_Student();     /*Fun to add student entry (Done)*/
int Display_Student(); /*Fun to display all enteries (Done)*/
int Search_Student();  /*Fun to Search a fucking student */
void Update_list();    /*Fun to change a Entry*/
void Delete_Record();  /*Changed from delete particular entry to deleting all entries (Done)*/

#endif
