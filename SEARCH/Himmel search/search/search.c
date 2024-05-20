/*============================================================================
 FILE        : search.c
 AUTHOR      : himmel
 DESCRIPTION : Handles the searching function (linear and binary search)
 REVISION HISTORY
 Date: 		        	By:         	Description:
 ============================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"
#include "search.h"

/* ================================================================================
 FUNCTION        : linearSearch
 DESCRIPTION     : Looks for a specific data in linear search method.
 ARGUMENTS       : LIST *data - Pointer to the list to be searched
                   int key - The value to be searched for in the list
                   int *location - Pointer to an integer where the index of the found key will be stored
 RETURNS         : bool - Returns 1 if the key is found in the list, 0 if not
 ================================================================================ */
bool linearSearch(LIST *data, int key, int*location)
{
    NODE *walker = data->head;
    bool f = 0;
    while(walker && f == 0)
    {
        if(walker->x == key)
        {
            *location = walker->i;
            f = 1;
        }
        walker = walker->n;
    }
    return f;
}
/* ================================================================================
 FUNCTION        : binarySearch
 DESCRIPTION     : Looks for a specific data in binary search method.
 ARGUMENTS       : LIST *data - Pointer to the list to be searched
                   int key - The value to be searched for in the list
                   int *location - Pointer to an integer where the index of the found key will be stored
 RETURNS         : bool - Returns 1 if the key is found in the list, 0 if not
 ================================================================================ */
bool binarySearch(LIST *data, int key, int *location)
{
    bool f = false;
    NODE *first = data->head;
    NODE *last = data->tail;
    NODE *mid;
    int midIndex;

    while (first != NULL && last != NULL && first != last->n)
    {
        mid = first;
        int count = 0;
        while (mid != NULL && count < (last->i - first->i) / 2)
        {
            mid = mid->n;
            count++;
        }
        midIndex = mid->i;

        if (mid->x == key)
        {
            f = true;
            *location = mid->i;
            break;
        }
        else if (key < mid->x)
        {
            last = mid->p;
        }
        else
        {
            first = mid->n;
        }
    }
    return f;
}

