#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(char *name, char *programme, float grade, float average);

typedef struct Student Student;
struct Student {
    char name[20];
    char programme[20];
    float grade;
};

int main(int argc, char *argv[]) {
    Student *allStudents;
    int total = argc / 3;
    // Allocating memory for at least 2 students
    allStudents = (Student *)malloc(2 * sizeof(Student));
    int count = 0;
    float average = 0;

    for (int i = 1; i < argc - 1; i += 3) {
        strcpy(allStudents[count].name, argv[i]);
        strcpy(allStudents[count].programme, argv[i + 1]);
        allStudents[count].grade = atof(argv[i + 2]);
        average += allStudents[count].grade;
        count++;
    }
    average = average / count;

    // Reallocate memory if necessary
    if (total > 2) {
        Student *pTemp = (Student *)realloc(allStudents, total * sizeof(Student));
        if (pTemp != NULL) {
            allStudents = pTemp;
        } else {
            // Handle realloc failure
            free(allStudents);
            return -1;
        }
    }

    for (int i = 0; i < total; i++) {
        print(allStudents[i].name, allStudents[i].programme, allStudents[i].grade, average);
    }
    printf("Average grade: %.2f\n", average);
    free(allStudents);
    return 0;
}

void print(char *name, char *programme, float grade, float average) {
    if ((strcmp(programme, "CSCE") == 0) && grade > average) {
        printf("%s, %.2f\n", name, grade);
    }
}
