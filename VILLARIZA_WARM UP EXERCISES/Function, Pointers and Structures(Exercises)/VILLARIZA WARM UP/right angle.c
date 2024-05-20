#include <stdio.h>
#include <stdlib.h>

void printRightTriAngle(int num);

int main()
{
    int num;
    printf("Enter the last number to be printed: ");
    scanf("%d", &num);
    printRightTriAngle(num);
}

void printRightTriAngle(int num)
{
    int numPerLine = 1, numPrint = 1, j;
    for(; numPrint <= num; numPerLine++)
    {
        for(j = 1; j < numPerLine; j++, numPrint++)
            printf("%d ", numPrint);
        printf("\n");
    }
}
