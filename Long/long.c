#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXCHAR 1000
#define MAX_STUDENT 1000
typedef struct Student
{
    int age;
    float score;
} Student;

Student getStudent(char *);
int readAndShowInfor(char *, Student *);
int findMinScore(Student *, int);
void printBestStudent(int, Student *, int);
float averageScore(int, Student *, int);

int main()
{
    int totalStudent;
    int age;
    char ch, choice;
    Student allStudents[MAX_STUDENT];
    do
    {
        printf("Choose an options : \n");
        printf("1. Read and show information of students\n");
        printf("2. Print 5 best score\n");
        printf("3. Finf average score of an age\n");
        printf("0. Exit\n");
        printf("Your choice: \t");
        scanf("%[^\n]%*c", &choice);
        switch (choice)
        {
        case '1':
            totalStudent = readAndShowInfor("sinhvien.txt", allStudents);
            break;
        case '2':
            printBestStudent(5, allStudents, totalStudent);
            break;
        case '3':
            printf("Insert an age: ");
            scanf("%d", &age);
            printf("total score of age %d is %6.3f\n", age, averageScore(age, allStudents, totalStudent));
            break;
        case '0':
            printf("Quited!");
            return 0;
        default:
            break;
        }
    } while (choice != '0');
    return 0;
}

Student getStudent(char *str)
{
    Student st;
    int i;
    int len;
    char tmp[10];
    char tmp2[10];
    char ch;
    len = strlen(str);
    for (i = 1; i < len - 1; i++)
    {
        if (isspace(str[i]))
        {
            memcpy(tmp, str, i);
            st.age = atoi(tmp);
            memcpy(tmp2, str + i + 1, len - i - 2);
            st.score = atof(tmp2);
        }
    }

    return st;
}

int readAndShowInfor(char *filename, Student *studentList)
{
    FILE *file = fopen(filename, "r");
    char str[100];
    int currentSt = 0, num, i;
    if (file)
    {
        if (fgets(str, MAXCHAR, file) != NULL)
        {
            num = atoi(str);
            for (i = 0; i < num && i < MAX_STUDENT; i++)
            {
                fgets(str, MAXCHAR, file);
                studentList[currentSt] = getStudent(str);
                currentSt++;
            }
            for (i = 0; i < num && i < MAX_STUDENT; i++)
            {
                printf("%d: age is %d, score is %6.3f\n", i + 1, studentList[i].age, studentList[i].score);
            }
        }
    }
    return num;
}

int findMinScore(Student *studentList, int size)
{
    int i, index = 0;
    float minScore = 10.0;
    if (size)
    {
        for (i = 0; i < size; i++)
        {
            if (studentList[i].score < minScore)
            {
                minScore = studentList[i].score;
                index = i;
            }
        }
    }
    return index;
}

void printBestStudent(int numOfStudent, Student *studentList, int totalStudent)
{
    Student bestStudent[numOfStudent];
    int i, j, indexOfMinScore;
    int changed = 1;
    int minAt = 0;
    for (i = 0; i < totalStudent; i++)
    {
        if (i < numOfStudent && i < totalStudent)
        {
            bestStudent[i] = studentList[i];
        }
        else if (i < totalStudent)
        {
            if (changed)
            {
                indexOfMinScore = findMinScore(bestStudent, numOfStudent);
                changed = 0;
            }
            for (j = 0; j < numOfStudent; j++)
            {
                if (studentList[i].score > bestStudent[indexOfMinScore].score)
                {
                    bestStudent[indexOfMinScore] = studentList[i];
                    changed = 1;
                }
            }
        }
    }
    for (i = 0; i < numOfStudent && i < MAX_STUDENT && i < totalStudent; i++)
    {
        printf("%d: age is %d, score is %6.3f\n", i + 1, bestStudent[i].age, bestStudent[i].score);
    }
}

float averageScore(int age, Student *studentList, int totalStudent)
{
    int i, num = 0;
    float totalScore = 0.0;
    for (i = 0; i < totalStudent; i++)
    {
        if (studentList[i].age == age)
        {
            num++;
            totalScore += studentList[i].score;
        }
    }
    if (num == 0) {
        printf("no age available\n");
        return 0;
    }
    return totalScore / num;
}