#include <stdio.h>
#include <string.h>

#define NUM_STUDENTS 3

// Structure to hold student details
typedef struct {
    int id;
    char name[50];
    int isPresent; // 1 for present, 0 for absent
} Student;

// Function prototypes
void markAttendance(Student students[], int n);
void displayAttendance(Student students[], int n);

int main() {
    Student students[NUM_STUDENTS];
    int choice;

    // Initialize student details
    for (int i = 0; i < NUM_STUDENTS; i++) {
        students[i].id = i + 1;
        printf("Enter name of student %d: ", i + 1);
        scanf(" %[^\n]", students[i].name);
        students[i].isPresent = 0; // Default attendance is absent
    }

    do {
        printf("\n--- Attendance Management ---\n");
        printf("1. Mark Attendance\n");
        printf("2. Display Attendance\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                markAttendance(students, NUM_STUDENTS);
                break;
            case 2:
                displayAttendance(students, NUM_STUDENTS);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

// Function to mark attendance
void markAttendance(Student students[], int n) {
    int id, status;
    printf("Enter student ID to mark attendance (1-%d): ", n);
    scanf("%d", &id);

    if (id < 1 || id > n) {
        printf("Invalid student ID.\n");
        return;
    }

    printf("Mark attendance for %s (1 for Present, 0 for Absent): ", students[id - 1].name);
    scanf("%d", &status);

    if (status == 1 || status == 0) {
        students[id - 1].isPresent = status;
        printf("Attendance updated for %s.\n", students[id - 1].name);
    } else {
        printf("Invalid input. Attendance not updated.\n");
    }
}

// Function to display attendance
void displayAttendance(Student students[], int n) {
    printf("\n--- Attendance List ---\n");
    printf("ID\tName\t\tStatus\n");
    printf("------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%-15s\t%s\n", students[i].id, students[i].name,
               students[i].isPresent ? "Present" : "Absent");
    }
}