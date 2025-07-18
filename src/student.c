#include "student.h"

#include <stdio.h>
#include <string.h>

// This function adds new Records of Students
//  Student is a structure with members: roll_no, name, age and marks
//  Count is used to know the length of array
void add_student(Student students[100], int* count) {
  if (*count >= 100) {
    printf("Error: Too many students\n");
    return;
  }
  int roll_no;
  char name[50];
  int age;
  float marks;

  printf("Enter Roll No: ");
  if (scanf("%d", &roll_no) != 1) {
    printf("Invalid roll number\n");
    return;
  }
  getchar();  // Consume the newline character left by scanf
  printf("Enter Name: ");
  fgets(name, sizeof(name), stdin);
  name[strcspn(name, "\n")] = 0;  // Remove trailing newline from fgets

  printf("Enter Age: ");
  if (scanf("%d", &age) != 1) {
    printf("Invalid age\n");
    return;
  }

  printf("Enter Marks: ");
  if (scanf("%f", &marks) != 1) {
    printf("Invalid Marks\n");
    return;
  }

  students[*count].roll_no = roll_no;
  strcpy(students[*count].name, name);
  students[*count].age = age;
  students[*count].marks = marks;

  (*count)++;
}

// This Function Lists Added Students
// Accepts Students Structure for now
void list_students(const Student students[], const int count) {
  if (count == 0) {
    printf("No students found\n");
  } else {
    for (int i = 0; i < count; i++) {
      printf("Roll No: %d\n", students[i].roll_no);
      printf("Name: %s\n", students[i].name);
      printf("Age: %d\n", students[i].age);
      printf("Marks: %f\n", students[i].marks);
      printf("\n");
    }
  }
}

void update_student(Student students[], const int count, const int id) {
  if (id >= count || id < 0) {
    printf("Invalid id\n");
    return;
  }

  printf("Updating student at ID: %d\n", id);

  int roll_no;
  char name[50];
  int age;
  float marks;

  printf("Enter Roll No: ");
  if (scanf("%d", &roll_no) != 1) {
    printf("Invalid roll number\n");
    return;
  }
  getchar();  // Consume the newline character left by scanf
  printf("Enter Name: ");
  fgets(name, sizeof(name), stdin);
  name[strcspn(name, "\n")] = 0;  // Remove trailing newline from fgets

  printf("Enter Age: ");
  if (scanf("%d", &age) != 1) {
    printf("Invalid age\n");
    return;
  }

  printf("Enter Marks: ");
  if (scanf("%f", &marks) != 1) {
    printf("Invalid Marks\n");
    return;
  }

  students[id].roll_no = roll_no;
  strcpy(students[id].name, name);
  students[id].age = age;
  students[id].marks = marks;

  printf("Updated student at ID: %d\n", id);
}

void delete_student(Student students[], int* count, int id) {
  if (id >= *count || id < 0) {
    printf("Invalid id\n");
    return;
  }
  printf("Deleting student at ID: %d\n", id);
  for (int i = id; i < *count - 1; i++) {
    students[i] = students[i + 1];
  }
  (*count)--;
  printf("Student deleted successfully\n");
}