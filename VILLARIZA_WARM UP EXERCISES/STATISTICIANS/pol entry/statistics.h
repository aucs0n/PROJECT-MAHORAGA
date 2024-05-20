/*===================================================================================
 FILE        : statistics.h
 AUTHOR      : Paul Andrew F. Parras
 DESCRIPTION : header file that contains all the neccessary function prototypes
               and other needed libraries, structs, and constants for the program
 REVISION HISTORY
 Date: 			By: 		Description:
 2/14/2024		Paul		removed some typedef declarations, changed Datastore
                            mode() to void mode(), added new struct for statistician.
 ===================================================================================*/

#ifndef STATISTICS_H
#define STATISTICS_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<conio.h>
#include<windows.h>
#include<ctype.h>
#include<math.h>

#define TRUE 1
#define FALSE 0
typedef bool Boolean;

typedef struct node {
    int item;
    struct node *next;
}node;

typedef struct statistician{
    int count;
    struct node *head,*tail;
}Statistician;

void menu();
void displayList(Statistician *s);
Statistician newStatistician();
void destroyStatistician(Statistician *s);
void add(Statistician *s, int x);
void removeStats(Statistician *s, int x);
void displayData(Statistician *s);
Boolean isEmpty(Statistician *s);
int minimum(Statistician *s);
int maximum(Statistician *s);
int range(Statistician *s);
float mean(Statistician *s);
float median(Statistician *s);
void mode(Statistician *s);
float variance(Statistician *s);
float standardDeviation(Statistician *s);


#endif
