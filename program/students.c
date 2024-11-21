#include "students.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

void new_id(int number, char* id) {
    snprintf(id, 9, "B%08d", number + 1);
}

Student* new_student() {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    
    if (newStudent == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
	
    printf("Enter your first name: ");
    scanf("%s", newStudent->first_name);
    printf("Enter your last name: ");
    scanf("%s", newStudent->last_name);
    strncpy(newStudent->status, "pending", sizeof(newStudent->status));
    newStudent->majorID = -1;
    newStudent->nbrCourses = 0;
    newStudent->maxCourse = 6;
    return newStudent;
}

void update_student(Student* s) {
    if (s == NULL) return;
    printf("Enter your new first name: ");
    scanf("%s", s->first_name);
    printf("Enter your new last name: ");
    scanf("%s", s->last_name);
}

void print_student(Student* s) {
    if (s != NULL) {
        printf("ID       ||       Name       ||      Status     ||     Major ID   ||     Number of courses\n");
        printf("%10s %18s %18s %15d %21d\n", s->id, s->first_name, s->last_name, s->status, s->majorID, s->nbrCourses);
    }
}

List_S* newList() {
    return NULL;
}

List_S* add_student(List_S* ls, Student s) {
    List_S* new_node = (List_S*)malloc(sizeof(List_S));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return ls;
    }
    
    new_node->s = s;
    new_node->next = ls;
    printf("The student %s has been added to the system.\n", s.id);
    return new_node;
}

void print_all_students(List_S* ls) {
    List_S* current = ls;
    while (current != NULL) {
        print_student(&current->s);
        current = current->next;
    }
}

void print_all_student_by_major(List_S* ls, int id) {
    List_S* current = ls;
    while (current != NULL) {
        if (current->s.majorID == id) {
            print_student(&current->s);
        }
        current = current->next; // Move to the next student
    }
}

Student* search(List_S* ls, char* id) {
    List_S* current = ls;
    while (current != NULL) {
        if (strcmp(current->s.id, id) == 0) {
            return &current->s;
        }
        current = current->next;
    }
    printf("There is no student with the entered ID.\n");
    return NULL;
}

int length(List_S* ls) {
    int count = 0;
    List_S* current = ls;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void sort_AZ_ls(List_S* ls) {
    if (ls == NULL || ls->next == NULL) return;

    List_S *current, *next;
    Student temp;

    for (current = ls; current->next != NULL; current = current->next) {
        for (next = current->next; next != NULL; next = next->next) {
            if (strcmp(current->s.last_name, next->s.last_name) > 0) {
                temp = current->s;
                current->s = next->s;
                next->s = temp;
            }
        }
    }
}

void choose_major(Student* s, int id) {
    if (s != NULL) {
        s->majorID = id;
        printf("You have chosen a major with ID: %d\n", id);
    } else {
        printf("The entered ID corresponds to no registered major.\n");
    }
}

void choose_courses(Student* s, int course_id) {
    FILE* file = fopen("../Storage text file/registered_for.txt", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    fprintf(file, "%s,%d,%d\n", s->id, course_id, -1); // Append student ID, course ID, and default grade
    fclose(file);
}

void view_student_courses(char* student_id) {
    char id[9];
    int course_code, grade;
    FILE* file = fopen("../Storage text file/registered_for.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("Courses for Student ID %s:\n", student_id);
    while (fscanf(file, "%s%d%d", id, &course_code, &grade) == 3) {
        if (strcmp(id, student_id) == 0) {
            printf("Course Code: %d, Grade: %d\n", course_code, grade);
        }
    }
    fclose(file);
}

void view_average(char* student_id) {
    char id[9];
    int course_code, grade, total_grades = 0, count = 0;
    FILE* file = fopen("../Storage text file/registered_for.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    while (fscanf(file, "%s%d%d", id, &course_code, &grade) == 3) {
        if (strcmp(id, student_id) == 0) {
            total_grades += grade;
            count++;
        }
    }
    
    if (count > 0) {
        printf("Average Grade for Student ID %s: %.2f\n", student_id, (float)total_grades / count);
    } else {
        printf("No grades found for Student ID %s.\n", student_id);
    }

    fclose(file);
}

List_S* Sfile_to_list() {
    List_S* list = newList();
    Student s;
    FILE* file = fopen("../Storage text file/students.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return NULL;
    }

    while (fscanf(file, "%[^,],%[^,],%[^,],%[^,],%d\n", s.id, s.first_name, s.last_name, s.status, &s.majorID) != EOF) {
        list = add_student(list, s);
    }

    fclose(file);
    return list;
}

void Slist_to_file(List_S* ls) {
    FILE* file = fopen("../Storage text file/students.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    List_S* current = ls;
    while (current != NULL) {
        fprintf(file, "%s,%s,%s,%s,%d\n", current->s.id, current->s.first_name, current->s.last_name, current->s.status, current->s.majorID);
        current = current->next;
    }

    fclose(file);
}
void free_student_list(List_S* ls) {
    List_S* current = ls;
    while (current != NULL) {
        List_S* temp = current;
        current = current->next;
        free(temp);
    }
}
