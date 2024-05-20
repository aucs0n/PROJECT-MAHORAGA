/*============================================================================================================
FILENAME        : Statistician.h
DESCRIPTION     : The header file for all the functions
AUTHOR          : himmel
CREATED ON      : February 14, 2024
REVISION HISTORY
Date:  	        		By:                     	Description:
============================================================================================================*/

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

// Define a Boolean type for clarity
typedef int Boolean;

// Define a structure for a node in the linked list
typedef struct node *nodePtr;
struct node {
    int item;
    nodePtr next;
};

// Define types for Statistician and DataStore
typedef nodePtr Statistician;
typedef Statistician DataStore;

// Function prototypes
Statistician newStatistician();
void destroyStatistician(Statistician *s);
void add(Statistician *s, int x);
void removeData(Statistician *s, int x);
void displayData(Statistician s);
Boolean isEmpty(Statistician s);
int minimum(Statistician s);
int maximum(Statistician s);
int range(Statistician s);
float mean(Statistician s);
float median(Statistician s);
DataStore mode(Statistician s);
float variance(Statistician s);
float standardDeviation(Statistician s);
int compare(const void *a, const void *b);

