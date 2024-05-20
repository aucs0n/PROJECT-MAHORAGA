#include <stdio.h>
#include <stdlib.h>

void maxAndMin(int *numberArr, int numberElements);

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
    maxAndMin(numberArr, numberElements);
    return 0;
}

void maxAndMin(int *numberArr, int numberElements)
{
    int max, min, i, j, temp;
    for(i = 0; i < numberElements; i++)
    {
        for(j = i+1; j < numberElements; j++)
        {
            if(*(numberArr+i) > *(numberArr+j))
            {
                temp = *(numberArr+i);
                *(numberArr+i) = *(numberArr+j);
                *(numberArr+j) = temp;
            }
        }
    }
    printf("\nMin: %d\n", *numberArr);
    printf("\nMax: %d", *(numberArr+numberElements-1));
}
