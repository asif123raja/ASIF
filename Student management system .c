#include <stdio.h>
#include <stdlib.h>

int MAX_STUDENTS = 100;

// structure to store student data
struct student {
    char name[50];
    int roll_number;
    int marks;
};

// function to add a new student
void add_student(struct student students[], int *num_students) {
    if (*num_students == MAX_STUDENTS) {
        printf("Error: Maximum number of students reached\n");
        return;
    }
    struct student new_student;
    
    printf("Enter name of student: ");
    scanf("%c",&new_student.name);
    gets(new_student.name);
    
    printf("Enter roll number of student: ");
    scanf("%d", &new_student.roll_number);
    
    printf("Enter marks of student: ");
    scanf("%d", &new_student.marks);
    
    students[*num_students] = new_student;
    (*num_students)++;
    
    printf("Student added successfully\n");
}

// function to display all students
void display_students(struct student students[], int num_students) {
    printf("List of students:\n");
    for (int i = 0; i < num_students; i++) {
        printf("Name: %s, \nRoll Number: %d, \nMarks: %d\n", students[i].name, students[i].roll_number, students[i].marks);
    }
}

// function to search for a student by roll number
void search_student(struct student students[], int num_students) {
    int roll_number;
    printf("Enter roll number of student to search for: ");
    scanf("%d", &roll_number);
    
    for (int i = 0; i < num_students; i++) {
        if (students[i].roll_number == roll_number) {
            printf("Student found: Name: %s, Roll Number: %d, Marks: %d\n", students[i].name, students[i].roll_number, students[i].marks);
            return;
        }
    }
    
    printf("Error: Student with roll number %d not found\n", roll_number);
}

int main() {
    struct student students[MAX_STUDENTS];
    int num_students = 0;
    
    while (1) {
        printf("Enter 1 to add student\n2 to display all students\n3 to search for a student by roll number\n4 to exit:\n");
        
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_student(students, &num_students);
                break;
            case 2:
                display_students(students, num_students);
                break;
            case 3:
                search_student(students, num_students);
                break;
            case 4:
                exit(0);
            default:
                printf("Error: Invalid choice\n");
        }
    }
    
    return 0;
}
