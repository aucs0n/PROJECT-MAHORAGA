#include <stdio.h>
#include <windows.h>
#include <string.h>

typedef struct 
{
    char id[10];
    char name[50];
    char course[10];
    int year;
} STUDENT;

void getInfo(STUDENT *info, int i);
void printInfo(STUDENT *info, int i);

int main()
{
    STUDENT info[5];

    system("cls");
    for(int i = 0; i < 5; i++)
    {
        getInfo(&info[i],i);
    }

    

    for(int i = 0; i < 5; i++)
    {
        printInfo(&info[i], i);
    }

    return 0;
}

void getInfo(STUDENT *info, int i)
{
    
    fflush(stdin);
    printf("Enter student id #%d: ", i+1);
    gets(info->id);
    fflush(stdin);
    printf("Enter student name #%d: ", i+1);
    gets(info->name);
    printf("Enter student course #%d: ", i+1);
    gets(info->course);
    fflush(stdin);
    printf("Enter student year #%d: ", i+1);
    scanf("%d", &info->year);
    printf("\n");

    return;
}
void printInfo(STUDENT *info, int i)
{
    printf("==============================================\n");
    printf("ID #%d: %s\n",i+1, info->id);
    printf("NAME #%d: %s\n", i+1, info->name);
    printf("COURSE #%d: %s\n", i+1, info->course);
    printf("YEAR #%d: %d\n", i+1, info->year);
    printf("==============================================\n");

    return;

}
