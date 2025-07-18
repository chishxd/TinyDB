#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"

void ClearInputBuffer();

int main() {
  Student student[100];
  int count = 0;
  int option;
  printf("==== STUDENT MANAGMENT SYSTEM ====\n");
  do {
    printf("1. Add a student.\n");
    printf("2. Display all student.\n");
    printf("3. Search a student.\n");
    printf("4. Update the list.\n");
    printf("5. Delete the student.\n");
    printf("6. Exit\n");
    printf("Enter your choice:");

    if (scanf(" %d", &option) != 1) {
      printf("Invalid input!! Try again!\n");
      ClearInputBuffer();
      option = 0;
    }

    ClearInputBuffer();

    switch (option) {
      case 1:
        add_student(student, &count);
        break;
      case 2:
        list_students(student, count);
        break;
      case 3:
        search_student(student, count);
        break;
      case 4:
        update_student(student, count);
        break;
      case 5:
        delete_student(student, &count);
        break;
      case 6:
        printf("Thanks for visiting. Have a nice day :)");
        break;
      default:
        printf("Invalid input!! Fuck off!!");
        break;
    }
  }

  while (option != 6);
  return 0;
}

void ClearInputBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}