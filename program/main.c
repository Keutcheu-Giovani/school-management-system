#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "students.c"
#include "majors.c"
#include "courses.c"

#define WIDTH 110

void left_text(const char* text);
void center_text(const char* text);
void student_app();
void administration_app();

int main() {
    int i, choice;

    while (1) {
        printf("%c", 201);
        for (i = 0; i < WIDTH; i++) printf("%c", 205);
        printf("%c\n", 187);

        printf("%c", 186);
        for (i = 0; i < WIDTH; i++) printf(" ");
        printf("%c\n", 186);

        center_text("Welcome to my school management platform");

        printf("%c", 186);
        for (i = 0; i < WIDTH; i++) printf(" ");
        printf("%c\n", 186);

        printf("%c", 199);
        for (i = 0; i < WIDTH; i++) printf("%c", 196);
        printf("%c\n", 182);

        printf("%c", 186);
        for (i = 0; i < WIDTH; i++) printf(" ");
        printf("%c\n", 186);

        left_text("Choose either of the following views by entering the corresponding number to make a choice");

        printf("%c", 186);
        for (i = 0; i < WIDTH; i++) printf(" ");
        printf("%c\n", 186);

        left_text("1 - Student view");
        left_text("2 - Administration view");

        printf("%c", 186);
        for (i = 0; i < WIDTH; i++) printf(" ");
        printf("%c\n", 186);

        printf("%c", 200);
        for (i = 0; i < WIDTH; i++) printf("%c", 205);
        printf("%c\n", 188);

        printf("Choice: ");
        scanf("%d", &choice);

        system("cls");

        if (choice == 1) {
            student_app();
        } else if (choice == 2) {
            administration_app();
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void student_app() {
    int choice, i, id;
    char temp_text[9];
    List_S* ls = Sfile_to_list();
    List_C* lc = Cfile_to_list();
    Student* s;

	while (1) {
	    printf("%c", 201);
	    for (i = 0; i < WIDTH; i++) printf("%c", 205);
	    printf("%c\n", 187);
	
	    printf("%c", 186);
	    for (i = 0; i < WIDTH; i++) printf(" ");
	    printf("%c\n", 186);
	
	    center_text("Welcome to the student platform ");
	
	    printf("%c", 186);
	    for (i = 0; i < WIDTH; i++) printf(" ");
	    printf("%c\n", 186);
	
	    printf("%c", 199);
	    for (i = 0; i < WIDTH; i++) printf("%c", 196);
	    printf("%c\n", 182);
	
	    printf("%c", 186);
	    for (i = 0; i < WIDTH; i++) printf(" ");
	    printf("%c\n", 186);
	
	    left_text("Enter the corresponding number to make a choice");
	
	    printf("%c", 186);
	    for (i = 0; i < WIDTH; i++) printf(" ");
	    printf("%c\n", 186);
	
	    left_text("1 - New student registration");
	    left_text("2 - Update your personal information");
	    left_text("3 - Choose a major");
	    left_text("4 - Choose your courses");
	    left_text("5 - View your courses and grades");
	    left_text("0 - Return to the home menu");
	
	    printf("%c", 186);
	    for (i = 0; i < WIDTH; i++) printf(" ");
	    printf("%c\n", 186);
	
	    printf("%c", 200);
	    for (i = 0; i < WIDTH; i++) printf("%c", 205);
	    printf("%c\n", 188);
	
	    printf("Choice: ");
	    scanf("%d", &choice);

        switch (choice) {
            case 1: {
                s = new_student();
                new_id(length(ls), s->id);
                ls = add_student(ls, *s);
                printf("Your student account was successfully created. Here is your student ID: %s\n", s->id);
                free(s);
                break;
            }
            case 2: {
                printf("Enter your B0 number: ");
                scanf("%s", temp_text);
                s = search(ls, temp_text);
                if (s != NULL) {
                    update_student(s);
                } else {
                    printf("The entered B0 number is incorrect\n");
                }
                break;
            }
            case 3: {
                printf("Enter your B0 number: ");
                scanf("%s", temp_text);
                s = search(ls, temp_text);
                if (s == NULL) {
                    printf("The entered B0 number is incorrect\n");
                } else {
                    if (strcmp(s->status, "registered") != 0) {
                        printf("You can't choose a major as your registration status is %s\n", s->status);
                        break;
                    }
                    print_all_major();
                    printf("Enter the ID of the major you want to choose: ");
                    scanf("%d", &i);
                    choose_major(s, i);
                }
                break;
            }
            case 4: {
                printf("Enter your student ID: ");
                scanf("%s", temp_text);
                s = search(ls, temp_text);
                if (s == NULL) {
                    printf("The entered B0 number is incorrect\n");
                } else {
                    if (strcmp(s->status, "registered") != 0) {
                        printf("You can't choose courses as your registration status is %s\n", s->status);
                        break;
                    }
                    if (s->majorID == -1) {
                        printf("You need to choose a major first\n");
                        break;
                    }
                    print_all_courses(lc);
                    while (1) {
                        printf("Enter the ID of the course you want to choose or 0 to stop: ");
                        scanf("%d", &id);
                        if (id == 0) break;
                        Course* c = search_c(lc, id);
                        if (c == NULL) {
                            printf("You entered an incorrect course ID\n");
                        } else {
                            if (can_register(c)) {
                                if (s->nbrCourses >= s->maxCourse) {
                                    printf("No more than %d courses per student\n", s->maxCourse);
                                } else {
                                    choose_courses(s, c->id);
                                    c->current_enrollment++;
                                    s->nbrCourses++;
                                }
                            } else {
                                printf("This course is currently full, you can't register for it\n");
                            }
                        }
                    }
                }
                break;
            }
            case 5: {
                printf("Enter your student ID: ");
                scanf("%s", temp_text);
                s = search(ls, temp_text);
                if (s != NULL) {
                    view_student_courses(s->id);
                    view_average(s->id);
                } else {
                    printf("The entered B0 number is incorrect\n");
                }
                break;
            }
            case 0:
                Slist_to_file(ls);
                free_student_list(ls);
                Clist_to_file(lc);
                free_course_list(lc);
                system("cls");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}

void administration_app() {
    int i, choice, temp_nbr, temp_nbr2, id;
    char temp_text[50];
    List_S* ls = Sfile_to_list();
    List_C* lc = Cfile_to_list();
    Student* s;
    Course* c;


	while(1){
		
	    printf("%c", 201);
	    for (i = 0; i < WIDTH; i++) printf("%c", 205);
	    printf("%c\n", 187);
	
	    printf("%c", 186);
	    for (i = 0; i < WIDTH; i++) printf(" ");
	    printf("%c\n", 186);
	
	    center_text("Welcome to the administration platform");
	
	    printf("%c", 186);
	    for (i = 0; i < WIDTH; i++) printf(" ");
	    printf("%c\n", 186);
	
	    printf("%c", 199);
	    for (i = 0; i < WIDTH; i++) printf("%c", 196);
	    printf("%c\n", 182);
	
	    printf("%c", 186);
	    for (i = 0; i < WIDTH; i++) printf(" ");
	    printf("%c\n", 186);
	
	    left_text("Enter the corresponding number to make a choice");
	
	    printf("%c", 186);
	    for (i = 0; i < WIDTH; i++) printf(" ");
	    printf("%c\n", 186);
	
	    left_text("1 - View all students");
	    left_text("2 - View students by major");
	    left_text("3 - Change a student's status");
	    left_text("4 - Search a student's ID");
	    left_text("5 - View all courses");
	    left_text("6 - View courses by major");
	    left_text("7 - Create new courses");
	    left_text("8 - Assign courses to majors");
	    left_text("9 - View all Majors");
	    left_text("0 - Return to the home menu");
	
	    printf("%c", 186);
	    for (i = 0; i < WIDTH; i++) printf(" ");
	    printf("%c\n", 186);
	
	    printf("%c", 200);
	    for (i = 0; i < WIDTH; i++) printf("%c", 205);
	    printf("%c\n", 188);
	
	    printf("Choice: ");
	    scanf("%d", &choice);
	
	    switch (choice) {
	        case 1:
	            print_all_students(ls);
	            break;
	        case 2:
	            print_all_major();
	            printf("Enter the ID of a major: \n");
	            scanf("%d", &temp_nbr);
	            print_all_student_by_major(ls, temp_nbr);
	            break;
	        case 3:
	            printf("Enter the student's B0 number: ");
	            scanf("%s", temp_text);
	            s = search(ls, temp_text);
	            if (s == NULL) {
	                printf("The entered B0 number is incorrect\n");
	            } else {
	                printf("Here are the possible statuses: registered, rejected, expelled\n");
	                scanf("%s", temp_text);
	                strcpy(s->status, temp_text);
	            }
	            break;
	        case 4:
	            printf("Enter the student's B0 number: ");
	            scanf("%s", temp_text);
	            s = search(ls, temp_text);
	            if (s == NULL) {
	                printf("The entered B0 number is incorrect\n");
	            } else {
	                print_student(s);
	            }
	            break;
	        case 5:
	            print_all_courses(lc);
	            break;
	        case 6:
	            print_all_major();
	            printf("Enter the ID of a major: ");
	            scanf("%d", &temp_nbr);
	            FILE* file = fopen("../Storage text file/offers.txt", "r");
	            if (file == NULL) {
	                printf("The file ../Storage text file/offers.txt was not found\n");
	                break;
	            }
	            while (fscanf(file, "%d %d", &temp_nbr2, &id) == 2) {
	                if (temp_nbr2 == temp_nbr) {
	                    Course* course = search_c(lc, id);
	                    if (course) {
	                        print_course(course);
	                    }
	                }
	            }
	            fclose(file);
	            break;
	        case 7:
	            new_course(c);
	            lc = add_course(lc, *c);
	            break;
	        case 8:
	            print_all_major();
	            print_all_courses(lc);
	            printf("Enter the ID of the major to which you want to assign a course: ");
	            scanf("%d", &temp_nbr);
	            printf("Enter the ID of the course you want to assign: ");
	            scanf("%d", &temp_nbr2);
	            assign_course(temp_nbr, temp_nbr2);
	            break;
	        case 9:
	            print_all_major();
	            break;
	        case 0:
	            Slist_to_file(ls);
                free_student_list(ls);
                Clist_to_file(lc);
                free_course_list(lc);
	            system("cls");
	            return;
	        default:
	            printf("Invalid choice. Please try again.\n");
	            break;
	    }
	}
}

void left_text(const char* text) {
    int length_text = strlen(text);
    int i, total_space;

    total_space = WIDTH - length_text - 5;
    if (total_space < 0) total_space = 0;

    printf("%c", 186);
    printf("     %s", text);
    for (i = 0; i < total_space; i++) printf(" ");
    printf("%c\n", 186);
}

void center_text(const char* text) {
    int length_text = strlen(text);
    int i, total_space;

    total_space = WIDTH - length_text;
    if (total_space < 0) total_space = 0;

    printf("%c", 186);
    for (i = 0; i < total_space / 2; i++) printf(" ");
    printf("%s", text);
    for (i = 0; i < (total_space / 2); i++) printf(" ");
    printf("%c\n", 186);
}
