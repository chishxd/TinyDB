#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void ClearInputBuffer();
int Add_Student();      /* Fun to add a student*/
void Display_Student(); /*Fun to dispaly all the student*/
void Search_Student();  /*Fun to Search for a particular Student from his/her id*/
void Update_List();     /*Fun to make changes or editing the file idk if it's possilbe*/
void Delete_Student();  /*Fun to delete a student*/

typedef struct Student
{
   char name[100];
   char grade;
   int id;
};

int main()
{
   int option;
   printf("==== STUDENT MANAGMENT SYSTEM ====\n");
   do
   {
      printf("1. Add a student.\n");
      printf("2. Display all student.\n");
      printf("3. Search a student.\n");
      printf("4. Update the list.\n");
      printf("5. Delete the student.\n");
      printf("6. Exit");
      printf("Enter your choice:");

      if (scanf(" %d", &option) != 1)
      {
         printf("Invalid input!! Try again!\n");
         ClearInputBuffer();
         option = 0;
      }

      ClearInputBuffer();

      switch (option)
      {
      case 1:
         Add_Student();
         break;
      case 2:
         Display_Student();
         break;
      case 3:
         Search_Student();
         break;
      case 4:
         Update_List();
         break;
      case 5:
         Delete_Student();
         break;
      case 6:
         printf("Thanks for visiting. Have a nice day :)");
      default:
         printf("Invalid input!! Fuck off!!");
         break;
      }
      return 0;
   }

   while (option != 6);
}

void ClearInputBuffer()
{
   int c;
   while ((c = getchar()) != ' \n' && c != EOF)
      ;
}

int Add_Student()
{
   printf("hii");
   return 0;
}

void Display_Student()
{
   printf("hii");
}
void Search_Student()
{
   printf("hii");
}
void Update_List()
{
   printf("hii");
}
void Delete_Student()
{
   printf("hii");
}