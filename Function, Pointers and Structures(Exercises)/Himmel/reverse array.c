#include <stdio.h>
#include <stdlib.h>

void reversePrint(int *numberArr, int numberElements);

int main()
{
    int numberElements;
    printf("Enter number of elements: ");
    scanf("%d", &numberElements);
    int *numberArr = (int *) malloc(sizeof(int) * numberElements);
    for(int i = 0; i < numberElements; i++)
    {
        printf("\nEnter number [%d]: ", i+1);
        scanf("%d", numberArr+i);
    }
    reversePrint(numberArr, numberElements);

    return 0;
}

void reversePrint(int *numberArr, int numberElements)
{
    for(int i = numberElements-1; i >= 0; i--)
        printf("\n%d ", *(numberArr+i));
}
