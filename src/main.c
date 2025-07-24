#include "student.h"
#include "utils.h"
#include <stdio.h>

int main() {
  Student student[100];
  int count = 0;
  int option;

  printf("\n==== STUDENT MANAGEMENT SYSTEM ====\n");

  do {
    printf("\n1. Add a student.\n");
    printf("2. Display all students.\n");
    printf("3. Search a student.\n");
    printf("4. Update the list.\n");
    printf("5. Delete a student.\n");
    printf("6. Exit\n");
    printf("--------------------\n");

    if (!read_integer("Enter your choice: ", &option)) {
      printf("Invalid input! Please enter a number.\n");
    }

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
        printf("Thanks for visiting. Have a nice day :)\n");
        break;
      default:
        printf("Invalid option. Please try again.\n");
        break;
    }

  } while (option != 6);
}
