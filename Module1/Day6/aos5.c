#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

int searchStudentByName(const struct Student* students, int numStudents, const char* name) {
    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, name) == 0) {
            return i;  
        }
    }
    return -1;  
}

void displayStudent(const struct Student* student) {
    printf("Roll No: %d, Name: %s, Marks: %.2f\n", student->rollno, student->name, student->marks);
}

int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);
    getchar();  

    struct Student* students = (struct Student*)malloc(numStudents * sizeof(struct Student));

    printf("Enter the student details (rollno name marks) separated by spaces:\n");

    for (int i = 0; i < numStudents; i++) {
        scanf("%d %s %f", &students[i].rollno, students[i].name, &students[i].marks);
        getchar();  
    }

    char searchName[20];
    printf("\nEnter the name of the student to search: ");
    scanf("%s", searchName);

    int foundIndex = searchStudentByName(students, numStudents, searchName);

    if (foundIndex != -1) {
        printf("\nStudent found at index %d:\n", foundIndex);
        displayStudent(&students[foundIndex]);
    } else {
        printf("\nStudent not found.\n");
    }

    free(students);  

    return 0;
}