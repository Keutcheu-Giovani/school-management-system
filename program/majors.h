#ifndef MAJOR_H
#define MAJOR_H

#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
} Major;

void print_major(int id);
void print_all_major();
void assign_course(int idMajor, int idCourse);

#endif
