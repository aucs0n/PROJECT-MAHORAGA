/*============================================================================
 FILE        : search.h
 AUTHOR      : Paul Andrew F. Parras
 DESCRIPTION : contains the function prototypes and structs for the program
 REVISION HISTORY
 Date: 			By: 		Description:
 2/24/2024      Paul		added function prototypes and struct declarations
 ============================================================================*/
#ifndef SEARCH_H
#define SEARCH_H


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<unistd.h>
#include<conio.h>
#include<windows.h>
#include<ctype.h>
#include<math.h>
#include<time.h>

typedef struct node
{
    int data;
    struct node *prev, *next;   // struct declarations
}node;

typedef struct List
{
    int count;
    struct node *head, *tail;
}List;

void add(List *data, int x);
void displayList(List *data);
node* getTail(node* cur);
node* partition(node* head, node* end, node** newHead, node** newEnd);  // function protoypes
node* quickSortRecur(node* head, node* end);
void quickSort(node** headRef);
bool linear_search(List* data, int key, int *location);
bool binary_search(List* data, int key, int* location);
void createList(List *data);

#endif
