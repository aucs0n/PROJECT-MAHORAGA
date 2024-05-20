
#ifndef DLL_H
#define DLL_H

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

// List structure
struct list {
    int count;
    struct node *head, *tail;
};

// Function prototypes

void insertFront(struct list *L, int x);
void insertRear(struct list *L, int x);
void insertAt(struct list *L, int x, int p);
void removeFront(struct list *L);
void removeRear(struct list *L);
void removeAt(struct list *L, int p);
void printList(struct list *L);
void printMirror(struct list *L);

#endif
