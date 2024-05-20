/*============================================================================
 FILE        : list.c
 AUTHOR      : Ghemarson John D. Nacua, Remy Gabriel Cordero, Vincent Michael Villariza
 DESCRIPTION : Handles the functions (create, display, and delete)
 REVISION HISTORY
 Date: 		        	By: 	        	Description:
 ============================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "list.h"
#include "search.h"
/* ================================================================================
 FUNCTION        : displayList
 DESCRIPTION     : Displays the list containing the data
 ARGUMENTS       : LIST *L - pointer to the LIST
 RETURNS         : void
 ================================================================================ */
void displayList(LIST *L)
{
	NODE *walker =L->head;

	if(walker==NULL)
    {
		printf("\n LIST IS EMPTY \n");
	}
	else
    {
		printf("\n LOCATION	: [ ");
		while(walker)
		{
			printf("%4d", walker->i);
			walker = walker->n;
		}
		printf("]\n");

		walker =L->head;

		printf(" LIST		: [ ");
		while(walker)
        {
			printf("%4d", walker->x);
			walker = walker->n;
		}
		printf("]\n");
	}

}
/* ================================================================================
 FUNCTION        : createList
 DESCRIPTION     : Creates the list of data
 ARGUMENTS       : LIST *L - pointer to the LIST
                   int ndata - the no. of data to be made in the LIST
 RETURNS         : void
 ================================================================================ */
void createList(LIST *L, int ndata)
{
	int i, n;

	if((L->count)>0)
    {
		destroyList(L);
	}

	time_t t;
	srand((unsigned) time(&t));

	for(i=0;i<ndata;i++)
    {
		n = rand() % 101;
		insertEnd(L, n);
	}
}
/* ================================================================================
 FUNCTION        : insertEnd
 DESCRIPTION     : Inserts a specific data at the end of the list.
 ARGUMENTS       : LIST *L - pointer to the LIST
                   int Data - the data to be added to the list
 RETURNS         : void
 ================================================================================ */
void insertEnd(LIST *L, int Data)
{
    // Allocate memory for the new node
    NODE *newNode = (NODE*)malloc(sizeof(NODE));
    if (newNode == NULL)
    {
        printf("Memory allocation failed. Exiting.\n");
        exit(EXIT_FAILURE); // Handle memory allocation failure
    }

    // Initialize the new node
    newNode->i = L->count;
    newNode->x = Data;
    newNode->n = NULL;
    newNode->p = NULL;

    // If the list is empty, set the new node as both head and tail
    if (L->count == 0)
    {
        L->head = newNode;
        L->tail = newNode;
    }
    else
    {
        // If the list is not empty, insert the new node at the end
        if (L->tail == NULL)
        {
            printf("Error: Tail pointer is NULL. Exiting.\n");
            exit(EXIT_FAILURE); // Handle invalid tail pointer
        }
        L->tail->n = newNode;
        newNode->p = L->tail;
        newNode->n = NULL;
        L->tail = newNode;
    }
    (L->count)++;
}

/* ================================================================================
 FUNCTION        : destroyList
 DESCRIPTION     : Terminates the list
 ARGUMENTS       : LIST *L - pointer to the LIST
 RETURNS         : void
 ================================================================================ */
void destroyList(LIST *L)
{
	NODE *walker = L->tail;


	while(L->head!=L->tail)
    {
		L->tail=L->tail->p;
		free(walker);
		walker = L->tail;
	}

	free(L->head);

	L->head=NULL;
	L->tail=NULL;
	L->count=0;
}
/* ================================================================================
 FUNCTION        : selectionSort
 DESCRIPTION     : Sorts the data inside the list
 ARGUMENTS       : LIST *L - pointer to the LIST
 RETURNS         : void
 ================================================================================ */
void selectionSort(LIST *L)
{
    NODE *walker_a = L->head;
    NODE *walker_b; // Declare walker_b without initializing it
    int temp;

    while (walker_a != NULL)
    {
        walker_b = walker_a->n; // Initialize walker_b inside the loop
        while (walker_b != NULL) {
            if (walker_a->x > walker_b->x)
            {
                temp = walker_a->x;
                walker_a->x = walker_b->x;
                walker_b->x = temp;
            }
            walker_b = walker_b->n;
        }
        walker_a = walker_a->n;
    }
}

