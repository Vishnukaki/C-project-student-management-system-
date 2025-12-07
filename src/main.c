#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

void addStudent() {
    struct Student s;
    FILE *fp = fopen("students.txt", "a");

    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Roll Number: ");
    scanf("%d", &s.roll);

    printf("Enter Name: ");
    scanf("%s", s.name);

    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fprintf(fp, "%d %s %.2f\n", s.roll, s.name, s.marks);
    fclose(fp);

    printf("Student Added Successfully!\n");
}

void displayStudents() {
    struct Student s;
    FILE *fp = fopen("students.txt", "r");

    if (!fp) {
        printf("No records found!\n");
        return;
    }

    printf("\n--- Student Records ---\n");

    while (fscanf(fp, "%d %s %f", &s.roll, s.name, &s.marks) != EOF) {
        printf("Roll: %d | Name: %s | Marks: %.2f\n", s.roll, s.name, s.marks);
    }

    fclose(fp);
}

void searchStudent() {
    int r;
    struct Student s;
    int found = 0;

    printf("Enter Roll Number to Search: ");
    scanf("%d", &r);

    FILE *fp = fopen("students.txt", "r");

    if (!fp) {
        printf("No records found!\n");
        return;
    }

    while (fscanf(fp, "%d %s %f", &s.roll, s.name, &s.marks) != EOF) {
        if (s.roll == r) {
            printf("\nRecord Found!\n");
            printf("Roll: %d | Name: %s | Marks: %.2f\n", s.roll, s.name, s.marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No student found with roll number %d\n", r);
    }

    fclose(fp);
}

void calculateAverage() {
    struct Student s;
    FILE *fp = fopen("students.txt", "r");
    int count = 0;
    float sum = 0;

    if (!fp) {
        printf("No records found!\n");
        return;
    }

    while (fscanf(fp, "%d %s %f", &s.roll, s.name, &s.marks) != EOF) {
        sum += s.marks;
        count++;
    }

    fclose(fp);

    if (count == 0) {
        printf("No data to calculate average!\n");
        return;
    }

    printf("Class Average Marks = %.2f\n", sum / count);
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Calculate Average Marks\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: calculateAverage(); break;
            case 5: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
