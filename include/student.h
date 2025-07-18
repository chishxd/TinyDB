#ifndef STUDENT_H
#define STUDENT_H

typedef struct {
  int roll_no;
  char name[50];
  int age;
  float marks;
} Student;

void add_student(Student students[], int *count);
void list_students(const Student students[], int count);
void update_student(Student students[], int count, int id);
void delete_student(Student students[], int *count, int id);

#endif  // STUDENT_H