#include "student.h"

#include <stdio.h>

#include "string.h"
#include "utils.h"

void add_student(Student students[], int* count) {
  if (*count >= 100) {
    printf("Error: Too many students\n");
    return;
  }

  char name[50];
  int roll_no, age;
  float marks;

  while (!read_integer("Enter Roll No: ", &roll_no)) {
    printf("Error: Invalid roll number\n");
  }


  do {
    if (!read_string("Enter Name: ", name, sizeof(name))) {
      fprintf(stderr, "Input error.\n");
    }
  } while (strlen(name) == 0);


  while (!read_integer("Enter Age: ", &age)) {
    printf("Error: Invalid age\n");
  }

  while (!read_float("Enter Marks: ", &marks)) {
    printf("Error: Invalid marks\n");
  }

  students[*count].id = *count;
  students[*count].roll_no = roll_no;
  strcpy(students[*count].name, name);
  students[*count].age = age;
  students[*count].marks = marks;

  printf("---------------------------------------\n");
  printf("Student added successfully with ID %d\n", *count);
  printf("---------------------------------------\n");

  (*count)++;
}


// This Function Lists Added Students
// Accepts Students Structure for now
void list_students(const Student students[], const int count) {
  if (count == 0) {
    printf("No students found\n");
  } else {
      for (int i = 0; i < count; i++) {
      printf("---------------------------------------\n");
      printf("ID: %d\n", students[i].id);
      printf("Roll No: %d\n", students[i].roll_no);
      printf("Name: %s\n", students[i].name);
      printf("Age: %d\n", students[i].age);
      printf("Marks: %f\n", students[i].marks);
      printf("---------------------------------------\n");
    }
  }
}

void search_student(const Student students[], const int count) {
  int id;
  if (!read_integer("Enter ID: ", &id)) {
    printf("Error: Invalid roll number\n");
  }
  if (count == 0 || id > count - 1) {
    printf("---------------------------------------\n");
    printf("No students found\n");
    printf("---------------------------------------\n");
    return;
  }
  printf("---------------------------------------\n");
  printf("Student ID: %d\n", id);
  printf("Roll No: %d\n", students[id].roll_no);
  printf("Name: %s\n", students[id].name);
  printf("Age: %d\n", students[id].age);
  printf("Marks: %f\n", students[id].marks);
  printf("---------------------------------------\n");
}

void update_student(Student students[], const int count) {
  int id;
  while(!read_integer("Enter ID: ", &id)) {
    printf("---------------------------------------\n");
    printf("Error: Invalid roll number\n");
    printf("---------------------------------------\n");
  }
  while (id < 0 || id >= count-1) {
    printf("---------------------------------------\n");
    printf("Invalid ID\n");
    printf("---------------------------------------\n");
  }
  printf("---------------------------------------\n");
  printf("Updating student at ID: %d\n", id);
  printf("---------------------------------------\n");

  int roll_no;
  while (!read_integer("Enter Roll No: ", &roll_no)) {
    printf("---------------------------------------\n");
    printf("Invalid roll number\n");
    printf("---------------------------------------\n");
  }
  char name[64];

  do {
    if (!read_string("Enter Name: ", name, sizeof(name))) {
      fprintf(stderr, "Input error.\n");
    }
  } while (strlen(name) == 0);


  name[strcspn(name, "\n")] = '\0'; // Strip trailing newline

  int age;
  while (!read_integer("Enter Age: ", &age)) {
    printf("Invalid age\n");
  }
  float marks;
  while (!read_float("Enter Age: ", &marks)) {
    printf("Invalid marks\n");
  }

  students[id].roll_no = roll_no;
  students[id].age = age;
  students[id].marks = marks;
  strcpy(students[id].name, name);

  printf("---------------------------------------\n");
  printf("Updated student at ID: %d\n", id);
  printf("---------------------------------------\n");
}


void delete_student(Student students[], int* count) {
  int id;
  if (!read_integer("Enter ID: ", &id)) {
    printf("---------------------------------------\n");
    printf("Error: Invalid ID\n");
    printf("---------------------------------------\n");
    return;
  }
  // printf("Enter ID to delete: ");
  // if (scanf("%d", &id) != 1) {
  //   printf("Invalid id\n");
  // }
  if (id >= *count || id < 0) {
    printf("---------------------------------------\n");
    printf("Invalid ID\n");
    printf("---------------------------------------\n");
    return;
  }
  printf("---------------------------------------\n");
  printf("Deleting student at ID: %d\n", id);
  printf("---------------------------------------\n");
  for (int i = id; i < *count - 1; i++) {
    students[i] = students[i + 1];
  }
  (*count)--;
  printf("---------------------------------------\n");
  printf("Student deleted successfully\n");
  printf("---------------------------------------\n");
}