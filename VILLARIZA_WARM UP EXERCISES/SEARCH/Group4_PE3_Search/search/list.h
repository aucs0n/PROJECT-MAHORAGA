/*============================================================================
 FILE        : list.h
 AUTHOR      : Ghemarson John D. Nacua, Remy Gabriel Cordero, Vincent Michael Villariza
 DESCRIPTION : The header file and data structures for list.c
 REVISION HISTORY
 Date: 		        	By: 	        Description:
 ============================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef LIST_H
#define LIST_H


typedef struct node{
	int x;
	int i;
	struct node *n;
	struct node *p;
}NODE;


typedef struct list{
	struct node *head;
	struct node *tail;
	int count;
}LIST;


void displayList(LIST *L);
void createList(LIST *L, int ndata);
void insertEnd(LIST *L, int Data);
void destroyList(LIST *L);
void selectionSort(LIST *L);

#endif
