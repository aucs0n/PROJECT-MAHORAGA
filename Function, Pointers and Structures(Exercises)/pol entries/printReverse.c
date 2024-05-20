#include <stdio.h>
#include <stdlib.h>

void printReverse(int *numArr, int count);

int main()
{
    int count;
    printf("Enter how many elements: ");
    scanf("%d", &count);

    int *numArr = (int*) malloc(count*sizeof(numArr));
    for(int i = 0; i < count; i++)
    {
        printf("Enter number #%d: ", i+1);
        scanf("%d", numArr+i);
    }

    printReverse(numArr,count);
    free(numArr);
    return 0;


}

void printReverse(int *numArr, int count)
{
    for(int i = count-1; i >= 0;i--)
    {
        printf("%d ", *(numArr+i));
    }
}