#include "library.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Add_Student() {
  Student newStudent;
  FILE *student_info = NULL;

  printf("Enter the Name: \n");
  if (fgets(newStudent.name, sizeof(newStudent.name), stdin) == NULL) {
    printf("Error reading name.\n");
    return 1;
  }
  newStudent.name[strcspn(newStudent.name, "\n")] = '\0';

  printf("Enter Student ID (Roll number): \n");
  if (scanf("%d", &newStudent.ID) != 1) {
    printf("Invalid ID. Please enter a number.\n");
    return 1;
  }
  clearInputBuffer();

  printf("Enter student grade: \n");
  if (scanf(" %c", &newStudent.grade) != 1) {
    printf("Invalid grade. Please enter a single character.\n");
    return 1;
  }
  clearInputBuffer();

  student_info = fopen("stud_info.bin", "ab");
  if (student_info == NULL) {
    printf("File can't be opened! An error occurred!!\n");
    return 1;
  }

  if (fwrite(&newStudent, sizeof(Student), 1, student_info) != 1) {
    printf("Error saving data.\n");
    fclose(student_info);
    return 1;
  }
  printf("Data saved successfully.\n");

  fclose(student_info);
  return 0;
}

int Display_Student() {
  FILE *student_info;
  Student currentStudent;

  student_info = fopen("stud_info.bin", "rb");

  if (student_info == NULL) {
    printf("Error: No student data found or file could not be opened.\n");
    return 1;
  }

  printf("\n--- Displaying All Students ---\n");
  printf("Name             ID     Grade\n");
  printf("-----------------------------------\n");

  int students_found = 0;

  while (fread(&currentStudent, sizeof(Student), 1, student_info) == 1) {
    printf("%-16s %-6d %c\n", currentStudent.name, currentStudent.ID,
           currentStudent.grade);
    students_found = 1;
  }

  if (students_found == 0) {
    printf("No student records found in the file.\n");
  }
  printf("-----------------------------------\n\n");

  fclose(student_info);
  return 0;
}

int Search_Student() {
  Student find_student;
  int found = 0, input_roll;

  FILE *student_info = NULL;

  printf("Enter the roll no(ID) of the student:\n");
  if (scanf(" %d", &input_roll) != 1) {
    printf("Error Wrong input");
    return 1;
  }
  clearInputBuffer();

  student_info = fopen("stud_info.bin", "rb");

  if (student_info == NULL) {
    printf("Error opening file!\n");
    return 1;
  }

  while (fread(&find_student, sizeof(Student), 1, student_info) == 1) {
    if (find_student.ID == input_roll) {
      printf("\n---- Displaying Student ----\n");
      printf("Name             ID     Grade\n");
      printf("-----------------------------------\n");
      printf("%-16s %-6d %c\n", find_student.name, find_student.ID,
             find_student.grade);
      printf("-----------------------------------\n\n");
      found = 1;
    }
  }

  if (found == 0) {
    printf("No such student found with %d ID", &input_roll);
  }

  return 0;
}

int Update_list() {
  Student find_student;
  int found = 0;
  int input_roll;
  char option;

  FILE *student_info = NULL;
  FILE *temp_info = NULL;

  printf("Enter the roll no(ID) of the student you want to update:\n");
  if (scanf(" %d", &input_roll) != 1) {
    printf("Error: Wrong input. Please enter a number.\n");
    clearInputBuffer();
    return 1;
  }
  clearInputBuffer();

  student_info = fopen("stud_info.bin", "rb");
  if (student_info == NULL) {
    printf("Error opening student_info.bin for reading!\n");
    return 1;
  }

  temp_info = fopen("temp_stud_info.bin", "wb");
  if (temp_info == NULL) {
    printf("Error opening temp_stud_info.bin for writing!\n");
    fclose(student_info);
    return 1;
  }

  while (fread(&find_student, sizeof(Student), 1, student_info) == 1) {
    if (find_student.ID == input_roll) {
      found = 1;
      printf("\n---- Displaying Student ----\n");
      printf("Name             ID     Grade\n");
      printf("-----------------------------------\n");
      printf("%-16s %-6d %c\n", find_student.name, find_student.ID,
             find_student.grade);
      printf("-----------------------------------\n\n");
      printf("Is this the student you want to update?(y/n): \n");
      scanf(" %c", &option);
      clearInputBuffer();
      char upoption = toupper(option);

      if (upoption == 'Y') {
        printf("Enter the new Name: \n");
        if (fgets(find_student.name, sizeof(find_student.name), stdin) ==
            NULL) {
          printf("Error reading new name.\n");
          fclose(student_info);
          fclose(temp_info);
          remove("temp_stud_info.bin");
          return 1;
        }
        find_student.name[strcspn(find_student.name, "\n")] = '\0';

        printf("Enter new Student ID (Roll number): \n");
        if (scanf("%d", &find_student.ID) != 1) {
          printf("Invalid ID. Please enter a number.\n");
          clearInputBuffer();
          fclose(student_info);
          fclose(temp_info);
          remove("temp_stud_info.bin");
          return 1;
        }
        clearInputBuffer();

        printf("Enter new student grade: \n");
        if (scanf(" %c", &find_student.grade) != 1) {
          printf("Invalid grade. Please enter a single character.\n");
          clearInputBuffer();
          fclose(student_info);
          fclose(temp_info);
          remove("temp_stud_info.bin");
          return 1;
        }
        clearInputBuffer();

        if (fwrite(&find_student, sizeof(Student), 1, temp_info) != 1) {
          printf("Error writing updated data to temporary file.\n");
          fclose(student_info);
          fclose(temp_info);
          remove("temp_stud_info.bin");
          return 1;
        }
        printf("Student information updated in memory. Saving...\n");
      } else if (upoption == 'N') {
        if (fwrite(&find_student, sizeof(Student), 1, temp_info) != 1) {
          printf("Error writing original data to temporary file.\n");
          fclose(student_info);
          fclose(temp_info);
          remove("temp_stud_info.bin");
          return 1;
        }
        break;
      } else {
        printf(
            "Invalid option. Please enter 'y' or 'n'. Skipping update for this "
            "student.\n");
        if (fwrite(&find_student, sizeof(Student), 1, temp_info) != 1) {
          printf("Error writing original data to temporary file.\n");
          fclose(student_info);
          fclose(temp_info);
          remove("temp_stud_info.bin");
          return 1;
        }
        continue;
      }
    } else {
      if (fwrite(&find_student, sizeof(Student), 1, temp_info) != 1) {
        printf("Error writing data to temporary file.\n");
        fclose(student_info);
        fclose(temp_info);
        remove("temp_stud_info.bin");
        return 1;
      }
    }
  }

  fclose(student_info);
  fclose(temp_info);

  if (found == 0) {
    printf("No such student found with ID %d.\n", input_roll);
    remove("temp_stud_info.bin");
  } else {
    if (remove("stud_info.bin") != 0) {
      printf("Error deleting original file.\n");
      return 1;
    }
    if (rename("temp_stud_info.bin", "stud_info.bin") != 0) {
      printf("Error renaming temporary file.\n");
      return 1;
    }
    printf("Student data updated successfully.\n");
  }

  return 0;
}

int Delete_Record() {
  FILE *student_info = fopen("stud_info.bin", "wb");
  if (student_info == NULL) {
    printf("Error opening file!");
    return 1;
  }

  fclose(student_info);

  printf("Data deleted succesfully\n");
  printf("|--------------------------|\n\n");
}

void clearInputBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}