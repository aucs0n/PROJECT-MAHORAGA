#include<stdio.h>
#include<stdlib.h>
#include "list_headers.h"

void insertFront(struct list *L, int x)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = NULL;
    if (L->head == NULL)
    {
        L->head = L->tail = newNode;
    } else
    {
        newNode->next = L->head;
        L->head = newNode;
    }
    L->count++;
}


void insertRear(struct list *L, int x)
{
   struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = NULL;
    if (L->tail == NULL)
    {
        L->head = L->tail = newNode;
    } else
    {
        L->tail->next = newNode;
        L->tail = newNode;
    }
    L->count++;
}


void insertAt(struct list *L, int x, int p)
{
    if (p < 0 || p > L->count)
    {
        printf("Invalid p\n");
        return;
    }

    if (p == 0)
    {
        insertFront(L, x);
    } else if (p == L->count)
    {
        insertRear(L, x);
    } else {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = x;
        newNode->next = NULL;
        struct node *curr = L->head;

        for (int i = 1; i < p; i++)
        {
            curr = curr->next;
        }

        newNode->next = curr->next;
        curr->next = newNode;
        L->count++;
    }
}


void deleteFront(struct list *L) {
    if (L->head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = L->head;
    L->head = L->head->next;
    free(temp);
    L->count--;

    if (L->head == NULL) {
        L->tail = NULL;
    }
}


void deleteEnd(struct list *L) {
    if (L->head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (L->head == L->tail) {
        free(L->head);
        L->head = L->tail = NULL;
        L->count = 0;
        return;
    }

    struct node *curr = L->head;
    while (curr->next != L->tail) {
        curr = curr->next;
    }

    free(L->tail);
    L->tail = curr;
    L->tail->next = NULL;
    L->count--;
}


void removeAtNode(struct list *L, int p) {
    if (p < 0 || p >= L->count) {
        printf("Invalid p\n");
        return;
    }

    if (p == 0) {
        deleteFront(L);
    } else if (p == L->count - 1) {
        deleteEnd(L);
    } else {
        struct node *curr = L->head;
        for (int i = 1; i < p; i++) {
            curr = curr->next;
        }

        struct node *temp = curr->next;
        curr->next = temp->next;
        free(temp);
        L->count--;
    }
}


void wholeDisp(struct list *L) {
    if (L->head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *curr = L->head;
    while (curr != NULL) {
        printf("%d ->", curr->data);
        curr = curr->next;
    }
    printf("\n");
}


