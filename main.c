#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void ClearInputBuffer();
int Add_Student();
void Display_Student();
void Search_Student();
void Update_List();
void Delete_Student();

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
   } while (option != 6);

   if (scanf("%d , &option") != 1)
   {
      printf("Invalid input!! Try again!");
      ClearInputBuffer();
      option = 0;
   }

   ClearInputBuffer();

   switch (option)
   {
   case 1:
      int Add_Student();
      break;
   case 2:
      void Display_Student();
   case 3:
      void Search_Student();
   case 4:
      void Update_List();
   case 5:
      void Delete_Student();
   default:
      break;
   }
   return 0;
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