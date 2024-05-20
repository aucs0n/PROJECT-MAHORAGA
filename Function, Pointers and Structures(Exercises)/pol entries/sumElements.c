#include <stdio.h>
#include <stdlib.h>

int addElements(int *numArr, int count);

int main()
{
    int count;
    printf("Enter number of elements: ");
    scanf("%d", &count);
    int *numArr = (int*) malloc(count*sizeof(int));
    for(int i = 0; i < count; i++)
    {
        printf("Enter element #%d: ", i+1);
        scanf("%d", numArr+i);
    }

    printf("The sum of all the elements is: %d", addElements(numArr, count));
    free(numArr);

    return 0;
}

int addElements(int *numArr, int count)
{
    int sum = 0;
    for(int i = 0; i < count; i++)
    {
        sum+=*(numArr+i);
    }

    return sum;
}