#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};
    int searchStudentByName(struct Student* students, int size, char* searchName) {
    for (int i = 0; i < size; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            return i;
        }
    }

    return -1;
}

void parseString(char* inputString, struct Student* students, int size) {
    char* token;
    token = strtok(inputString, " ");

    for (int i = 0; i < size; i++) {
        students[i].rollno = atoi(token);

        token = strtok(NULL, " ");
        strcpy(students[i].name, token);

        token = strtok(NULL, " ");
        students[i].marks = atof(token);

        token = strtok(NULL, " ");
    }
}

int main() {
    int size;
    printf("Enter the number of students: ");
    scanf("%d", &size);
    getchar(); 
    struct Student* students = (struct Student*)malloc(size * sizeof(struct Student));

    char inputString[100];
    printf("Enter the student details: ");
    fgets(inputString, sizeof(inputString), stdin);
    inputString[strcspn(inputString, "\n")] = '\0';  
    parseString(inputString, students, size);

    

    printf("\n");

    for (int i = 0; i < size; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
      char searchName[20];
    printf("Enter the name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';  // Remove the trailing newline character

    int foundIndex = searchStudentByName(students, size, searchName);
    if (foundIndex != -1) {
        printf("Student found at index %d\n", foundIndex);
        printf("Roll No: %d\n", students[foundIndex].rollno);
        printf("Name: %s\n", students[foundIndex].name);
        printf("Marks: %.2f\n", students[foundIndex].marks);
    } else {
        printf("Student not found.\n");
    }

    free(students);
    

    return 0;
}