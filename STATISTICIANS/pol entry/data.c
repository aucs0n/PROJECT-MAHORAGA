
/*============================================================================
 FILE        : data.c
 AUTHOR      : Paul Andrew F. Parras
 DESCRIPTION : contains the functions that deal with calculations for displaying the data
 REVISION HISTORY
 Date: 			By: 		Description:
 2/14/2024		Paul		added file and function details
 2/15/2024      Kyle        modified the variance and standardDeviation
 2/15/2024      Paul        removed isEmpty function from standardDeviation and
                            variance
============================================================================*/

#include "statistics.h"

/*============================================================================
 FUNCTION    : minimum
 DESCRIPTION : finds the minimum value in th list
 ARGUMENTS   : Statistician *s - List pointer for statistician
 RETURNS     : min - the minimum value
============================================================================*/
int minimum(Statistician *s)
{
    int min;
    node *temp = s->head;
    min = temp->item;
    while(temp!=NULL)
    {
        if(temp->item < min)
        {
            min = temp->item;
        }
        temp = temp->next;
    }

    return min;
}

/*============================================================================
 FUNCTION    : maximum
 DESCRIPTION : finds the maximum value in th list
 ARGUMENTS   : Statistician *s - List pointer for statistician
 RETURNS     : max - the maximum value
 ============================================================================*/
int maximum(Statistician *s)
{
    int max;
    node *temp = s->head;
    max = temp->item;
    while(temp!=NULL)
    {
        if(temp->item > max)
        {
            max = temp->item;
        }
        temp = temp->next;
    }
    return max;
}
/*============================================================================
 FUNCTION    : range
 DESCRIPTION : finds the range of the given list
 ARGUMENTS   : Statistician *s - List pointer for statistician
 RETURNS     : int - max-min(range)
 ============================================================================*/
int range(Statistician *s)
{
    int min;
    int max;
    node *temp = s->head;
    max = temp->item;
    while(temp!=NULL)
    {
        if(temp->item > max)
        {
            max = temp->item;
        }
        temp = temp->next;
    }

    node *tempN = s->head;
    min = tempN->item;
    while(tempN!=NULL)
    {
        if(tempN->item < min)
        {
            min = tempN->item;
        }
        tempN = tempN->next;
    }

    return max-min;
}

/*============================================================================
 FUNCTION    : mean
 DESCRIPTION : finds the mean of the given list
 ARGUMENTS   : Statistician *s - List pointer for statistician
 RETURNS     : float - sum/s->count(mean/average)
 ============================================================================*/

float mean(Statistician *s)
{
    int sum = 0;
    node *temp = s->head;
    while(temp!=NULL)
    {
        sum += temp->item;
        temp = temp->next;
    }

    return (float)sum/s->count;
}

/*============================================================================
 FUNCTION    : median
 DESCRIPTION : finds the median value in th list
 ARGUMENTS   : Statistician *s - List pointer for statistician
 RETURNS     : median - the median value
 ============================================================================*/

float median(Statistician *s)
{


    node *ptr1 = s->head;
    node *ptr2 = s->head;
    node *prevPtr1 = s->head;

    float median = 0;

    if (ptr1 == NULL)
    {
        return 0;
    }

    while (ptr2 != NULL && ptr2->next != NULL)
    {
        ptr2 = ptr2->next->next;
        prevPtr1 = ptr1;
        ptr1 = ptr1->next;
    }

    if (ptr2 != NULL)
    {
        median = ptr1->item;
    }
    else
    {
        median = (ptr1->item + prevPtr1->item) / 2.0;
    }

    return median;
}

/*============================================================================
 FUNCTION    : mode
 DESCRIPTION : finds the mode in th list
 ARGUMENTS   : Statistician *s - List pointer for statistician
 RETURNS     : void
 ============================================================================*/

void mode(Statistician *s)
{
    node *ptr = s->head;
    node *ptr1 = s->head;
    int i, j, n = 0;
	int count = 0, maxCount = 0, maxVal = 0;

	if(ptr == NULL)
	{

        return;
    }
    else
    {
        do
        {
        	n++;
        	ptr = ptr -> next;
            }while(ptr != NULL);
            int arr[n];

            for(i=0;i < n; i++)
            {
                arr[i] = ptr1 -> item;
                ptr1 = ptr1 -> next;
            }

            for(i=0;i<n;i++)
            {
                count = 0;
                for(j=0;j<n;j++)
                {
                    if(arr[i] == arr[j])
                    {
                        count++;
                    }
                }
                if (count > maxCount)
                {
                    maxCount = count;
                    maxVal = arr[i];
                }
            }

    }
    if(maxCount == 1)
    {
        printf("Mode: All the elements appeared exactly once");
    }
    else
    {
        printf("Mode: %d, appeared %d times", maxVal, count);
    }
}
/*============================================================================
 FUNCTION    : variance
 DESCRIPTION : finds the variance value in th list
 ARGUMENTS   : Statistician *s - List pointer for statistician
 RETURNS     :var- the variance
 ============================================================================*/
float variance(Statistician *s)
{


    node *ptr = s->head;
    float sum = 0;
    float meanValue = mean(s);

    while (ptr != NULL)
    {
        sum += pow(ptr->item - meanValue, 2);
        ptr = ptr->next;
    }

    float var = sum / (s->count - 1);
    return var;
    }


/*============================================================================
 FUNCTION    : standardDeviation
 DESCRIPTION : finds the standard deviation of the list
 ARGUMENTS   : Statistician *s - List pointer for statistician
 RETURNS     : dev - the standard deviation
 ============================================================================*/

float standardDeviation(Statistician *s)
{

    float varianceValue = variance(s);
    return sqrt(varianceValue);
}
