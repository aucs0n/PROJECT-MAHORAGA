#include<stdio.h>
#include<stdlib.h>

void SearchMaxMin(int *numArr, int count);

int main()
{
    int count;
    printf("Enter number of elements: ");
    scanf("%d", &count);
    int *numArr = (int*)malloc(count*sizeof(int));
    for(int i = 0; i < count; i++)
    {
        printf("Enter number #%d: ", i+1);
        scanf("%d", numArr+i);
    }

    SearchMaxMin(numArr,count);
    free(numArr);
    return 0;
}

void SearchMaxMin(int *numArr, int count)
{
    int max = *(numArr+0);
    int min = *(numArr+0);
    for(int i = 0; i < count; i++)
    {
        if(*(numArr+i) > max)
        {
            max = *(numArr+i);
        }
        else if(*(numArr+i) < min)
        {
            min = *(numArr+i);
        }
    }

    printf("The maximum number is %d\n", max);
    printf("The minumum number is %d", min);

    return;
}
