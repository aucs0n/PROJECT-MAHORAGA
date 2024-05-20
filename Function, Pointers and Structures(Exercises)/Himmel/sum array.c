#include <stdio.h>
#include <stdlib.h>

int sumElements(int *numberArr, int numberElements);

int main()
{
    int numberElements, sum;
    printf("Enter number of elements: ");
    scanf("%d", &numberElements);
    int *numberArr = (int *) malloc(sizeof(int) * numberElements);
    for(int i = 0; i < numberElements; i++)
    {
        printf("\nEnter number [%d]: ", i+1);
        scanf("%d", numberArr+i);
    }
    sum = sumElements(numberArr, numberElements);
    printf("\nThe sum of all is: %d", sum);
    return 0;
}

int sumElements(int *numArr, int numberElements)
{
    int i, sum = 0;
    for(i = 0; i < numberElements; i++)
        sum+=*(numArr+i);
    return sum;
}
