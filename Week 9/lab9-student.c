#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    char name[20];
    char programme[20];
    float grade;
};

void print(struct Student *student, int count);

int main(int argc, char *argv[])
{
    int numStudents = (argc - 1) / 3;
    struct Student *students = (struct Student *)malloc(numStudents * sizeof(struct Student));

    for (int i = 0; i < numStudents; ++i)
    {
        strcpy(students[i].name, argv[i * 3 + 1]);
        strcpy(students[i].programme, argv[i * 3 + 2]);
        students[i].grade = atof(argv[i * 3 + 3]);
    }
    print(students, numStudents);
    free(students);
    return 0;
}

void print(struct Student *student, int count)
{
    for (int i = 0; i < count; ++i)
    {
        printf("%s, %s, %.2f\n", student[i].name, student[i].programme, student[i].grade);
    }
}
