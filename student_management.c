#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "students.dat"
#define TEMP_FILE "temp.dat"
#define SUBJECTS 5

typedef struct {
    int rollNo;
    char name[50];
    char course[30];
    float marks[SUBJECTS];
} Student;

// Read an integer safely
int readInt(const char *message) {
    int value;
    char line[100];

    while (1) {
        printf("%s", message);

        if (fgets(line, sizeof(line), stdin) &&
            sscanf(line, "%d", &value) == 1) {
            return value;
        }

        printf("Invalid input! Enter a number.\n");
    }
}

// Read a string
void readString(const char *message, char *value, int size) {
    printf("%s", message);

    if (fgets(value, size, stdin)) {
        value[strcspn(value, "\n")] = '\0';
    }
}

// Calculate percentage
float calculatePercentage(Student s) {
    float total = 0;

    for (int i = 0; i < SUBJECTS; i++) {
        total += s.marks[i];
    }

    return total / SUBJECTS;
}

// Calculate grade
char calculateGrade(float percentage) {
    if (percentage >= 90)
        return 'A';
    else if (percentage >= 75)
        return 'B';
    else if (percentage >= 60)
        return 'C';
    else if (percentage >= 40)
        return 'D';
    else
        return 'F';
}

// Check whether roll number exists
int rollExists(int rollNo) {
    FILE *fp = fopen(FILE_NAME, "rb");
    Student s;

    if (fp == NULL)
        return 0;

    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        if (s.rollNo == rollNo) {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

// Display a student record
void displayStudent(Student s) {
    printf("\n-----------------------------------\n");
    printf("Roll Number : %d\n", s.rollNo);
    printf("Name        : %s\n", s.name);
    printf("Course      : %s\n", s.course);

    printf("Marks       : ");

    for (int i = 0; i < SUBJECTS; i++) {
        printf("%.2f ", s.marks[i]);
    }

    float percentage = calculatePercentage(s);

    printf("\nPercentage  : %.2f%%\n", percentage);
    printf("Grade       : %c\n", calculateGrade(percentage));
    printf("-----------------------------------\n");
}

// Input student details
void inputStudent(Student *s) {
    readString("Enter student name: ",
               s->name, sizeof(s->name));

    readString("Enter course name: ",
               s->course, sizeof(s->course));

    for (int i = 0; i < SUBJECTS; i++) {
        char message[50];

        sprintf(message, "Enter marks for subject %d (0-100): ",
                i + 1);

        do {
            printf("%s", message);

            if (scanf("%f", &s->marks[i]) != 1) {
                printf("Invalid marks!\n");

                while (getchar() != '\n');
                s->marks[i] = -1;
            } else {
                while (getchar() != '\n');

                if (s->marks[i] < 0 || s->marks[i] > 100) {
                    printf("Marks must be between 0 and 100.\n");
                }
            }
        } while (s->marks[i] < 0 || s->marks[i] > 100);
    }
}

// Add a student
void addStudent() {
    Student s;

    s.rollNo = readInt("Enter roll number: ");

    if (rollExists(s.rollNo)) {
        printf("This roll number already exists!\n");
        return;
    }

    inputStudent(&s);

    FILE *fp = fopen(FILE_NAME, "ab");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fwrite(&s, sizeof(Student), 1, fp);
    fclose(fp);

    printf("\nStudent record added successfully!\n");
}

// Display all students
void displayAll() {
    FILE *fp = fopen(FILE_NAME, "rb");
    Student s;
    int count = 0;

    if (fp == NULL) {
        printf("No student records found.\n");
        return;
    }

    printf("\n===== ALL STUDENT RECORDS =====\n");

    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        displayStudent(s);
        count++;
    }

    fclose(fp);

    if (count == 0)
        printf("No records available.\n");
}

// Search student
void searchStudent() {
    int rollNo = readInt("Enter roll number to search: ");

    FILE *fp = fopen(FILE_NAME, "rb");
    Student s;

    if (fp == NULL) {
        printf("No records found.\n");
        return;
    }

    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        if (s.rollNo == rollNo) {
            displayStudent(s);
            fclose(fp);
            return;
        }
    }

    fclose(fp);
    printf("Student not found!\n");
}

// Update student
void updateStudent() {
    int rollNo = readInt("Enter roll number to update: ");

    FILE *fp = fopen(FILE_NAME, "rb");
    FILE *temp = fopen(TEMP_FILE, "wb");

    Student s;
    int found = 0;

    if (fp == NULL || temp == NULL) {
        printf("Error opening file!\n");

        if (fp != NULL) fclose(fp);
        if (temp != NULL) fclose(temp);

        return;
    }

    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        if (s.rollNo == rollNo) {
            printf("\nEnter updated details:\n");
            inputStudent(&s);
            found = 1;
        }

        fwrite(&s, sizeof(Student), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove(FILE_NAME);
    rename(TEMP_FILE, FILE_NAME);

    if (found)
        printf("Student record updated successfully!\n");
    else
        printf("Student not found!\n");
}

// Delete student
void deleteStudent() {
    int rollNo = readInt("Enter roll number to delete: ");

    FILE *fp = fopen(FILE_NAME, "rb");
    FILE *temp = fopen(TEMP_FILE, "wb");

    Student s;
    int found = 0;

    if (fp == NULL || temp == NULL) {
        printf("Error opening file!\n");

        if (fp != NULL) fclose(fp);
        if (temp != NULL) fclose(temp);

        return;
    }

    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        if (s.rollNo == rollNo) {
            found = 1;
            continue;
        }

        fwrite(&s, sizeof(Student), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove(FILE_NAME);
    rename(TEMP_FILE, FILE_NAME);

    if (found)
        printf("Student record deleted successfully!\n");
    else
        printf("Student not found!\n");
}

// Main menu
int main() {
    int choice;

    do {
        printf("\n====================================\n");
        printf(" STUDENT RECORD MANAGEMENT SYSTEM\n");
        printf("====================================\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("====================================\n");

        choice = readInt("Enter your choice: ");

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                displayAll();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                printf("Thank you for using the system!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}
