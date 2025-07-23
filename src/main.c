#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "library.h"

/*
cd /home/dadaso/TinyDB/src/
gcc main.c library.c -o student_app
./student_app
*/

int main() {
  int option;
  printf("==== STUDENT MANAGEMENT SYSTEM ====\n");

  do {
    printf("\n|-- Options --|\n");
    printf("1. Add Student\n");
    printf("2. Display All Student\n");
    printf("3. Search Student by ID\n");
    printf("4. Update Student Record\n");
    printf("5. Delete All Student Records\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");

    if (scanf(" %d", &option) != 1) {
      printf("Invalid input. Try again!\n");
      clearInputBuffer();
      option = 0;
      continue;
    }
    clearInputBuffer();

    switch (option) {
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
        Update_list();
        break;
      case 5:
        Delete_Record();
        break;
      case 6:
        printf("Thanks for your service. Have a nice day! :)\n");
        break;
      default:
        printf("Invalid Input. Fuck Off!\n");
        break;
    }
  } while (option != 6);

  return 0;
}
