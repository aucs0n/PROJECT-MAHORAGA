#include <stdio.h>
#include <windows.h>

void printTriangle(int num);
int main()
{
    system("cls");
    int num;
    printf("Enter the last number to be inputted: ");
    scanf("%d", &num);

    printTriangle(num);

    return 0;
}

void printTriangle(int num)
{
    int count = 1, i = 1;
    for(; i <= num; count++)
    {
        for(int j = 1; j < count; j++, i++)
        {
            printf("%d ", i);     
        }
        printf("\n");
    }
}