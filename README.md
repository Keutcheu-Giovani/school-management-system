# School Management System

## Overview

The School Management System is a console-based application designed to facilitate the management of student records, courses, and majors in an educational institution. This system provides two main interfaces: one for students and another for administrative staff.

## Features

- **Student Registration**: Allows new students to create accounts.
- **Personal Information Update**: Students can update their personal details.
- **Major Selection**: Students can choose their academic major from a list of available options.
- **Course Enrollment**: Students can enroll in courses up to their maximum capacity.
- **View Courses and Grades**: Students can view their enrolled courses and grades.
- **Administration Functions**: Administrators can manage student records, view courses, and assign courses to majors.

## Technologies Used

- **C Programming Language**
- **Standard Libraries**: Utilized for file handling and string manipulation.
- **Data Structures**: Primarily implemented using linked lists for dynamic storage.
- **Data Storage**: Text files were used to persistently store information.

## File Structure
/SchoolManagementSystem  
├── /Storage text file  
│ ├── courses.txt # Course information  
│ ├── majors.txt # Major information  
│ ├── offers.txt # Course assignments to majors  
│ └── students.txt # Student information  
├── /Program  
│ ├── majors.h # Header file for major-related functions  
│ ├── majors.c # Implementation of major-related functions  
│ ├── courses.h # Header file for course-related functions  
│ ├── courses.c # Implementation of course-related functions  
│ ├── students.h # Header file for student-related functions  
│ ├── students.c # Implementation of student-related functions  
│ └── main.c # Main application file  

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/Keutcheu-Giovani/school-management-system.git
   cd school-management-system

2. Compile the program:
   ```bash
   gcc main.c students.c majors.c courses.c -o school_management

3. Run the application:
   ```bash
   ./school_management

## Usage
Upon launching the application, users will be presented with a menu to choose between student and administration views. Each section provides further options based on the user's role.

### Student View Options
1. New student registration
2. Update personal information
3. Choose a major
4. Choose courses
5. View courses and grades
6. Return to the main menu
   
### Administration View Options
1. View all students
2. View students by major
3. Change a student's status
4. Search for a student's ID
5. View all courses
6. View courses by major
7. Create new courses
8. Assign courses to majors
9. View all majors
10. Return to the main menu

## Contributing
This project was developed as a personal practice initiative after completing my first-year engineering programming course. Contributions are highly encouraged! If you have suggestions for improvements or new features, please feel free to fork the repository and submit a pull request. Your feedback and contributions will be greatly appreciated!

## License
This project is licensed under the MIT License - see the LICENSE file for details.

## Contact
For questions or feedback, don't hesitate to contact Yannick Yonkeu at keutcheug@gmail.com.
