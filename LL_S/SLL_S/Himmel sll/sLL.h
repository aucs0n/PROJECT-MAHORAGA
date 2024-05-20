#ifndef sLL_H
#define sLL_H

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct list {
    int count;
    struct node *head, *tail;
};

void insertFront(struct list *L, int x);
void insertRear(struct list *L, int x);
void insertAt(struct list *L, int x, int p);
void deleteFront(struct list *L);
void deleteRear(struct list *L);
void deleteAt(struct list *L, int p);
void displayAll(struct list *L);

#endif
