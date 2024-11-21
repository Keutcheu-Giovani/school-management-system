#ifndef STUDENTS_H
#define STUDENTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char id[9];
    char first_name[50];
    char last_name[50];
    char status[20];
    int majorID; 
    int nbrCourses;
    int maxCourse;
} Student;

typedef struct student_box {
    Student s;
    struct student_box* next;
} List_S;

// Function prototypes
void new_id(int number, char* id);
Student* new_student();
void update_student(Student* s);
void print_student(Student* s);
List_S* newList();
List_S* add_student(List_S* ls, Student s);
void print_all_students(List_S* ls);
void print_all_student_by_major(List_S* ls, int id);
Student* search(List_S* ls, char* id);
int length(List_S* ls);
void sort_AZ_ls(List_S* ls);
void choose_major(Student* s, int id);
void choose_courses(Student* s, int course_id);
void view_student_courses(char* student_id);
void view_average(char* student_id);
List_S* Sfile_to_list();
void Slist_to_file(List_S* ls);
void free_student_list(List_S* ls);

#endif
