/*============================================================================
 FILE        : search.h
 AUTHOR      : himmel
 DESCRIPTION : The header filesfor search.c
 REVISION HISTORY
 Date:	        	By: 	        Description:
 ============================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#ifndef SEARCH
#define SEARCH


bool linearSearch(LIST *data, int key, int*location);
bool binarySearch(LIST *data, int key, int*location);

#endif
