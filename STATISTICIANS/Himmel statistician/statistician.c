/*============================================================================================================
FILENAME        : Statistician.c
DESCRIPTION     : This file contains all the functions to make a New Statistician, Destroy Statistician, Add Data to the
                  Statistician Delete Data from the statistician, Display the Statistics, and calculate the statistics
AUTHOR          : himmel
CREATED ON      : February 14, 2024
REVISION HISTORY
Date:  	        		By:                     	Description:
============================================================================================================*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include "Statistician.h"

/*============================================================================
 FUNCTION    : compare
 DESCRIPTION : comparison function for qsort
 ARGUMENTS : const void *a - pointer to the first element to be compared
             const void *b - pointer to the second element to be compared
 RETURNS : returns a negative value if a < b, zero if a == b, and a positive value if a > b
===========================================================================*/

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
/*============================================================================
 FUNCTION    : newStatistician
 DESCRIPTION : Creates a new empty Statistician (linked list).
 ARGUMENTS   : None
 RETURNS     : Returns a new Statistician (linked list) with NULL head.
 ============================================================================*/

Statistician newStatistician() {
    return NULL;
}
/*============================================================================
 FUNCTION    : destroyStatistician
 DESCRIPTION : Destroys the given Statistician by freeing all allocated nodes.
 ARGUMENTS   : Statistician *s - Pointer to the Statistician to be destroyed.
 RETURNS     : void
 ============================================================================*/

void destroyStatistician(Statistician *s) {
    // Traverse the list and free each node
    while (*s != NULL) {
        nodePtr temp = *s;
        *s = (*s)->next;
        free(temp);
    }
}
/*============================================================================
 FUNCTION    : add
 DESCRIPTION : Adds a new data point to the Statistician.
 ARGUMENTS   : Statistician *s - Pointer to the Statistician.
               int x - Data point to be added.
 RETURNS     : void
============================================================================*/

void add(Statistician *s, int x) {
    // Allocate memory for a new node
    nodePtr newNode = malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    // Assign data to the new node
    newNode->item = x;
    newNode->next = NULL;

    // If the statistician is empty, make the new node the head
    if (*s == NULL) {
        *s = newNode;
    } else {
        // Otherwise, traverse the list and append the new node to the end
        nodePtr current = *s;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}
/*============================================================================
 FUNCTION    : removeData
 DESCRIPTION : Removes the specified data point from the Statistician.
 ARGUMENTS   : Statistician *s - Pointer to the Statistician.
               int x - Data point to be removed.
 RETURNS     : void
============================================================================*/

void removeData(Statistician *s, int x) {
    // Traverse the list to find the node containing the data
    nodePtr current = *s;
    nodePtr prev = NULL;
    while (current != NULL && current->item != x) {
        prev = current;
        current = current->next;
    }

    // If the data is found, remove the node from the list
    if (current != NULL) {
        if (prev != NULL) {
            prev->next = current->next;
        } else {
            *s = current->next;
        }
        free(current);
    }
}
/*============================================================================
 FUNCTION    : displayData
 DESCRIPTION : Displays the data points in the Statistician.
 ARGUMENTS   : Statistician s - Statistician to be displayed.
 RETURNS     : void
============================================================================*/

void displayData(Statistician s) {
    while (s != NULL) {
        printf("%d ", s->item);
        s = s->next;
    }
    printf("\n");
}
/*============================================================================
 FUNCTION    : isEmpty
 DESCRIPTION : Checks if the Statistician is empty.
 ARGUMENTS   : Statistician s - Statistician to be checked.
 RETURNS     : Returns TRUE if the Statistician is empty, FALSE otherwise.
============================================================================*/

Boolean isEmpty(Statistician s) {
    return s == NULL ? TRUE : FALSE;
}
/*============================================================================
 FUNCTION    : minimum
 DESCRIPTION : Finds the minimum value in the Statistician.
 ARGUMENTS   : Statistician s - Statistician to be searched.
 RETURNS     : Returns the minimum value.
============================================================================*/

int minimum(Statistician s) {
    int min = s->item;
    while (s != NULL) {
        if (s->item < min) {
            min = s->item;
        }
        s = s->next;
    }
    return min;
}
/*============================================================================
 FUNCTION    : maximum
 DESCRIPTION : Finds the maximum value in the Statistician.
 ARGUMENTS   : Statistician s - Statistician to be searched.
 RETURNS     : Returns the maximum value.
============================================================================*/

int maximum(Statistician s) {
    int max = s->item;
    while (s != NULL) {
        if (s->item > max) {
            max = s->item;
        }
        s = s->next;
    }
    return max;
}
/*============================================================================
 FUNCTION    : range
 DESCRIPTION : Calculates the range of values in the Statistician.
 ARGUMENTS   : Statistician s - Statistician to be analyzed.
 RETURNS     : Returns the range of values.
============================================================================*/

int range(Statistician s) {
    return maximum(s) - minimum(s);
}
/*============================================================================
 FUNCTION    : mean
 DESCRIPTION : Calculates the mean (average) of the values in the Statistician.
 ARGUMENTS   : Statistician s - Statistician to be analyzed.
 RETURNS     : Returns the mean value.
============================================================================*/

float mean(Statistician s) {
    float sum = 0.0;
    int count = 0;
    while (s != NULL) {
        sum += s->item;
        count++;
        s = s->next;
    }
    return sum / count;
}
/*============================================================================
 FUNCTION    : median
 DESCRIPTION : Calculates the median of the values in the Statistician.
 ARGUMENTS   : Statistician s - Statistician to be analyzed.
 RETURNS     : Returns the median value.
============================================================================*/

float median(Statistician s) {
    // Count the number of elements in the list
    int count = 0;
    nodePtr temp = s;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    // If the list is empty, return 0
    if (count == 0)
        return 0.0;

    // Create an array to store the elements
    int *arr = malloc(count * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    // Copy elements from the list to the array
    int index = 0;
    temp = s;
    while (temp != NULL) {
        arr[index++] = temp->item;
        temp = temp->next;
    }

    // Sort the array
    qsort(arr, count, sizeof(int), compare);

    // Calculate the median
    float medianValue;
    if (count % 2 == 0) {
        medianValue = (arr[count / 2 - 1] + arr[count / 2]) / 2.0;
    } else {
        medianValue = arr[count / 2];
    }

    // Free the memory allocated for the array
    free(arr);

    return medianValue;
}
/*============================================================================
 FUNCTION    : mode
 DESCRIPTION : Calculates the mode of the values in the Statistician.
 ARGUMENTS   : Statistician s - Statistician to be analyzed.
 RETURNS     : Returns a linked list (DataStore) containing mode and frequency.
               Returns NULL if there is no mode.
============================================================================*/

DataStore mode(Statistician s) {
    // Initialize variables to store the mode and its frequency
    int modeValue = 0;
    int maxFrequency = 0;
    int distinctValues = 0;

    // Traverse the list to count the frequency of each element
    while (s != NULL) {
        int currentFrequency = 0;
        nodePtr temp = s;

        // Count the frequency of the current element
        while (temp != NULL) {
            if (temp->item == s->item)
                currentFrequency++;
            temp = temp->next;
        }

        // Update the mode if a higher frequency is found
        if (currentFrequency > maxFrequency) {
            maxFrequency = currentFrequency;
            modeValue = s->item;
        }

        s = s->next;
        distinctValues++; // Count distinct values
    }

    // If all values are distinct and appear only once, there is no mode
    if (maxFrequency == 1 && distinctValues > 1) {
        printf("Mode              : All values appeared just once\n");
        return NULL; // Return NULL to indicate no mode
    }

    // Create a new node to store the mode and its frequency
    DataStore modeData = malloc(sizeof(struct node));
    modeData->item = modeValue;
    modeData->next = malloc(sizeof(struct node));
    modeData->next->item = maxFrequency;
    modeData->next->next = NULL;

    return modeData;
}

/*============================================================================
 FUNCTION    : variance
 DESCRIPTION : Calculates the variance of the values in the Statistician.
 ARGUMENTS   : Statistician s - Statistician to be analyzed.
 RETURNS     : Returns the variance value.
============================================================================*/

float variance(Statistician s) {
    float meanValue = mean(s);
    float sumSquaredDiff = 0.0;
    int count = 0;

    // Calculate the sum of squared differences from the mean
    while (s != NULL) {
        sumSquaredDiff += (s->item - meanValue) * (s->item - meanValue);
        count++;
        s = s->next;
    }

    // Calculate the variance
    return sumSquaredDiff / count;
}

/*============================================================================
 FUNCTION    : standardDeviation
 DESCRIPTION : Calculates the standard deviation of the values in the Statistician.
 ARGUMENTS   : Statistician s - Statistician to be analyzed.
 RETURNS     : Returns the standard deviation value.
============================================================================*/

float standardDeviation(Statistician s) {
    // Standard deviation is the square root of the variance
    return sqrt(variance(s));
}
