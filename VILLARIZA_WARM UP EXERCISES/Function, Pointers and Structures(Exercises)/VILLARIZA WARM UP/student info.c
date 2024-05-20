#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char id[15];
    char name[50];
    char course[15];
    int year;
} Student;

void getInfo(Student *info, int i);
void displayInfo(Student *info, int i);

int main()
{
    Student info[5];

    system("cls");
    for(int i = 0; i < 5; i++)
    {
        getInfo(&info[i], i);
    }
    for(int i = 0; i < 5; i++)
    {
        displayInfo(&info[i], i);
    }
    return 0;
}

void getInfo(Student *info, int i)
{
    fflush(stdin);
    printf("Enter student ID number [%d]: ", i+1);
    gets(info->id);
    fflush(stdin);
    printf("Enter student name [%d]: ", i+1);
    gets(info->name);
    printf("Enter student course [%d]: ", i+1);
    gets(info->course);
    fflush(stdin);
    printf("Enter student year [%d]: ", i+1);
    scanf("%d", &info->year);
    printf("\n\n");
    return;
}

void displayInfo(Student *info, int i)
{
    printf("ID number [%d]: %s\n",i+1, info->id);
    printf("Name [%d]: %s\n", i+1, info->name);
    printf("Course [%d]: %s\n", i+1, info->course);
    printf("Year [%d]: %d\n", i+1, info->year);
    printf("\n\n");
    return;
}
