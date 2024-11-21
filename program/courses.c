#include "courses.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

void new_course(Course* c) {
    printf("Enter Course ID (integer): ");
    scanf("%d", &c->id);
    printf("Enter Course Name: ");
    scanf("%s", c->name); 
    printf("Enter Instructor Name: ");
    scanf("%s", c->instructor_name);
    printf("Enter Maximum Students: ");
    scanf("%d", &c->max_students);
    c->current_enrollment = 0;
}

void update_course(Course* c) {
    if (c == NULL) return;
    printf("Enter Course Name: ");
    scanf("%s", c->name);
    printf("Enter Instructor Name: ");
    scanf("%s", c->instructor_name);
    printf("Enter Maximum Students: ");
    scanf("%d", &c->max_students);
}

void print_course(Course* c) {
    if (c != NULL) {
        printf("ID: %d, Name: %s, Instructor: %s, Max Students: %d, Current Enrollment: %d\n",
               c->id, c->name, c->instructor_name, c->max_students, c->current_enrollment);
    }
}

int empty_c_list(List_C* lc) {
    return lc == NULL;
}

List_C* add_course(List_C* lc, Course c) {
    List_C* new_node = (List_C*)malloc(sizeof(List_C));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return lc;
    }

    new_node->c = c;
    new_node->next = NULL;

    if (empty_c_list(lc)) {
        return new_node; // First node
    }

    List_C* current = lc;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    return lc;
}

void print_all_courses(List_C* lc) {
    List_C* current = lc;
    while (current != NULL) {
        print_course(&current->c);
        current = current->next;
    }
}

Course* search_c(List_C* lc, int id) {
    List_C* current = lc;
    while (current != NULL) {
        if (current->c.id == id) {
            return &current->c;
        }
        current = current->next;
    }
    printf("Course with ID %d not found.\n", id);
    return NULL;
}

int lengthC(List_C* lc) {
    int count = 0;
    List_C* current = lc;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void sort_AZ_lc(List_C** lc) {
    if (empty_c_list(*lc) || (*lc)->next == NULL) return; // Check for empty or single node

    List_C *current, *next;
    Course temp;

    for (current = *lc; current->next != NULL; current = current->next) {
        for (next = current->next; next != NULL; next = next->next) {
            if (strcmp(current->c.name, next->c.name) > 0) { 
                temp = current->c;
                current->c = next->c;
                next->c = temp;
            }
        }
    }
}

int can_register(Course* c) {
    return c != NULL && c->current_enrollment < c->max_students;
}

List_C* Cfile_to_list() {
    FILE* file = fopen("../Storage text file/courses.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return NULL;
    }

    List_C* lc = NULL;
    Course c;

    while (fscanf(file, "%d,%49[^,],%49[^,],%d,%d\n", &c.id, c.name, c.instructor_name, &c.max_students, &c.current_enrollment) == 5) {
        lc = add_course(lc, c);
    }

    fclose(file);
    return lc;
}

void Clist_to_file(List_C* lc) {
    FILE* file = fopen("../Storage text file/courses.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    List_C* current = lc;
    while (current != NULL) {
        fprintf(file, "%d,%s,%s,%d,%d\n", current->c.id, current->c.name, current->c.instructor_name, current->c.max_students, current->c.current_enrollment);
        current = current->next;
    }

    fclose(file);
}
void free_course_list(List_C* lc) {
    List_C* current = lc;
    while (current != NULL) {
        List_C* temp = current;
        current = current->next;
        free(temp);
    }
}
