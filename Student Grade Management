#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 50
#define MAX_SUBJECTS 5
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int scores[MAX_SUBJECTS];
    float average;
} Student;

void addStudent(Student students[], int *numStudents);
void calculateAverages(Student students[], int numStudents);
void displayHighestLowestScores(Student students[], int numStudents);

int main() {
    Student students[MAX_STUDENTS];
    int numStudents = 0;
    char choice;

    do {
        printf("\n1. Add student\n");
        printf("2. Calculate averages\n");
        printf("3. View highest/lowest scores\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                addStudent(students, &numStudents);
                break;
            case '2':
                calculateAverages(students, numStudents);
                break;
            case '3':
                displayHighestLowestScores(students, numStudents);
                break;
            case '4':
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != '4');

    return 0;
}

void addStudent(Student students[], int *numStudents) {
    if (*numStudents >= MAX_STUDENTS) {
        printf("Maximum number of students reached.\n");
        return;
    }

    printf("Enter student name: ");
    scanf("%s", students[*numStudents].name);

    printf("Enter scores for %s:\n", students[*numStudents].name);
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        printf("Enter score for subject %d: ", i + 1);
        scanf("%d", &students[*numStudents].scores[i]);
    }

    (*numStudents)++;
    printf("Student added successfully.\n");
}

void calculateAverages(Student students[], int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        int sum = 0;
        for (int j = 0; j < MAX_SUBJECTS; j++) {
            sum += students[i].scores[j];
        }
        students[i].average = (float)sum / MAX_SUBJECTS;
        printf("Average score for %s: %.2f\n", students[i].name, students[i].average);
    }
}

void displayHighestLowestScores(Student students[], int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        int max = students[i].scores[0];
        int min = students[i].scores[0];
        for (int j = 1; j < MAX_SUBJECTS; j++) {
            if (students[i].scores[j] > max) {
                max = students[i].scores[j];
            }
            if (students[i].scores[j] < min) {
                min = students[i].scores[j];
            }
        }
        printf("Highest score for %s: %d\n", students[i].name, max);
        printf("Lowest score for %s: %d\n", students[i].name, min);
    }
}

