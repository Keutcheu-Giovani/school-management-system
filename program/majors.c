#include "majors.h"

void print_major(int id) {
    FILE* file = fopen("../Storage text file/majors.txt", "r");
    if (file == NULL) {
        printf("majors.txt not found\n");
        return;
    }

    int id2;
    char name[50];

    printf("Major ID    \t Major Name\n");
    while (fscanf(file, "%d %49s", &id2, name) == 2) {
        if (id == id2) {
            printf("%d    \t%s\n", id2, name);
        }
    }

    fclose(file);
}

void print_all_major() {
    FILE* file = fopen("../Storage text file/majors.txt", "r");
    if (file == NULL) {
        printf("majors.txt not found\n");
        return;
    }

    int id;
    char name[50];

    printf("Major ID    \t Major Name\n");
    while (fscanf(file, "%d %49s", &id, name) == 2) {
        printf("%d    \t%s\n", id, name);
    }

    fclose(file);
}

void assign_course(int idMajor, int idCourse) {
    FILE* file = fopen("../Storage text file/offers.txt", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "%d %d\n", idMajor, idCourse);
    
    fclose(file);
}
