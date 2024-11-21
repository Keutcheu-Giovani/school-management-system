#ifndef COURSES_H
#define COURSES_H

typedef struct {
    int id;
    char name[50];
    char instructor_name[50];
    int max_students;
    int current_enrollment;
} Course;

typedef struct List_C {
    Course c;
    struct List_C* next;
} List_C;

// Function prototypes
void new_course(Course* c);
void update_course(Course* c);
void print_course(Course* c);
int empty_c_list(List_C* lc);
List_C* add_course(List_C* lc, Course c);
void print_all_courses(List_C* lc);
Course* search_c(List_C* lc, int id);
int lengthC(List_C* lc);
void sort_AZ_lc(List_C** lc);
int can_register(Course* c);
List_C* Cfile_to_list();
void Clist_to_file(List_C* lc);
void free_course_list(List_C* lc);

#endif
