/*============================================================================
 FILE        : statistician.c
 AUTHOR      : Paul Andrew F. Parras
 DESCRIPTION : contains the functions that are connected to the statisticians list'
               creation, deletion, addition and subtraction of data, and displaying the data
 REVISION HISTORY
 Date: 			By: 		Description:
 2/14/2024		Paul		added file and function details
 2/15/2024      Kyle        added file and function details
 2/15/2024      Kyle        modified the add and remove functions
 2/15/2024      Paul        modified add and remove function
 ============================================================================*/

#include "statistics.h"

/*============================================================================
 FUNCTION    : newStatistician
 DESCRIPTION : initializes the Statistician list for the program
 ARGUMENTS   : none
 RETURNS     : *s - the intitialized Statistician list
 ============================================================================*/
Statistician newStatistician()
{
    Statistician *s = malloc(sizeof(Statistician));
    s->count = 0;
    s->head = s->tail = NULL;

    return *s;
}

/*============================================================================
 FUNCTION    : destroyStatistician
 DESCRIPTION : deletes/ frees the current statistcian list and data
 ARGUMENTS   : Statistician *s - List pointer for statistician
 RETURNS     : void
 ============================================================================*/
void destroyStatistician(Statistician *s)
{

    node *current = s->head;
    node *next;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    s->count = 0;
    s->head = NULL;
    s->tail = NULL;

}

/*============================================================================
 FUNCTION    : add
 DESCRIPTION : adds data to the statistician list
 ARGUMENTS   : Statistician *s - List pointer for statistician
               int x - the integer to be added to the list
 RETURNS     : void
 ============================================================================*/

void add(Statistician *s, int x)
{
    node *newNode = malloc(sizeof(node));
    newNode->item = x;
    newNode->next = NULL;
    if (isEmpty(s))
    {
        s->head = s->tail = newNode;
    }
    else
    {
        s->tail->next = newNode;
        s->tail = newNode;
    }
    s->count++;

}

/*============================================================================
 FUNCTION    : removeStats
 DESCRIPTION : removes data to the statistician list
 ARGUMENTS   : Statistician *s - List pointer for statistician
               int x - the integer to be added to the list
 RETURNS     : void
 ============================================================================*/
void removeStats(Statistician *s, int x)
{

     node *temp = s->head;
    node *prev = NULL;

    // Find the position of the data in the list
    int pos = 0;
    while (temp != NULL)
    {
        if (temp->item == x)
        {
            break;
        }
        pos++;
        prev = temp;
        temp = temp->next;
    }

    // Check if the data is not found
    if (temp == NULL)
    {
        system("cls");
        printf("Error, Data not found in the list");
        getch();
        return;
    }

    // Remove the data from the list
    if (prev == NULL)
    {
        // Data is at the head of the list
        s->head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    // Display the current list after removing data


    printf("\nSuccessfully removed %d", x);

    // Free the memory of the removed node
    free(temp);

    // Update the count of elements in the list
    s->count--;
}
/*============================================================================
 FUNCTION    : displayData
 DESCRIPTION : displays the statistics for the statistician
 ARGUMENTS   : Statistician *s - List pointer for statistician
 RETURNS     : void
 ============================================================================*/

void displayData(Statistician *s)
{
        printf("STATISTICIAN DATA: ");
        node *temp = s->head;
        while (temp != NULL)
        {
            printf("%d ", temp->item);
            temp = temp->next;
        }
        printf("\nMinimum: %d\n", minimum(s));
        printf("Maximum: %d\n", maximum(s));
        printf("Range: %d\n", range(s));
        printf("Mean(Average): %.2f\n", mean(s));
        printf("Median: %.2f\n", median(s));
        mode(s);
        printf("\n");
        printf("Variance: %.2f\n", variance(s));
        printf("Standard Deviation: %.2f\n", standardDeviation(s));
        getch();

}

/*============================================================================
 FUNCTION    : isEmpty
 DESCRIPTION : checks if the statistician has data or not
 ARGUMENTS   : Statistician *s - List pointer for statistician
 RETURNS     : 1 - condition is true
               0 -condition is false
 ============================================================================*/
Boolean isEmpty(Statistician *s)
{
    if (s->head == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*============================================================================
 FUNCTION    : displayList
 DESCRIPTION : Displays the current elements in the Statistician list
 ARGUMENTS   : Statistician *s - List pointer for the statistician
 RETURNS     : void
 ============================================================================*/
void displayList(Statistician *s)
{
    system("cls");
    printf("Current List: ");
    node *temp = s->head;
    while (temp != NULL)
    {
        printf("%d ", temp->item);
        temp = temp->next;
    }
    printf("\n");
}


