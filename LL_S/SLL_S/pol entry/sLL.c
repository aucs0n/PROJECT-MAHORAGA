/*============================================================================
 FILE        : sLL.c
 AUTHOR      : Paul Andrew F. Parras
 DESCRIPTION : contains the functions that inserts at the front, rear, and specific
                position as well as their deletion.
 REVISION HISTORY
 Date: 			By: 		Description:

 ============================================================================*/

#include "SLL.h"

/*============================================================================
 FUNCTION    : insertFront
 DESCRIPTION : inserts new node at the front/start of the list
 ARGUMENTS   : struct list *L, int x
 RETURNS     : void
 ============================================================================*/
void insertFront(struct list *L, int x) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node)); // allocating memory creates the node
    newNode->data = x;
    newNode->next = NULL;
    if (L->head == NULL) { //checks if the list is empty ,
        L->head = L->tail = newNode; // if so, set both the head and the tail to the newNode
    } else {
        newNode->next = L->head;
        L->head = newNode;
    }
    L->count++;//increase the count of nodes/ elements of the list
}

/*============================================================================
 FUNCTION    : insertRear
 DESCRIPTION : inserts new node at the rear/end of the list
 ARGUMENTS   : struct list *L, int x
 RETURNS     : void
 ============================================================================*/
void insertRear(struct list *L, int x) {
   struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = NULL;
    if (L->tail == NULL) {// checks if the tail node is the last node
        L->head = L->tail = newNode;
    } else {
        L->tail->next = newNode;
        L->tail = newNode;
    }
    L->count++;
}

/*============================================================================
 FUNCTION    : insertAt
 DESCRIPTION : inserts new node at a specific position of the list
 ARGUMENTS   : struct list *L, int x, int p
 RETURNS     : void
 ============================================================================*/
void insertAt(struct list *L, int x, int p) {
    if (p < 0 || p > L->count) { // checks if the position inputted by user is within the range of the list
        printf("Invalid p\n");
        return;
    }

    if (p == 0) {//if user inputs position 0, is the same as inserting in the front
        insertFront(L, x);
    } else if (p == L->count) {// if user inputs equal to the last node, is the same as inserting in the rear
        insertRear(L, x);
    } else {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));// creates new node
        newNode->data = x;
        newNode->next = NULL;
        struct node *current = L->head;

        for (int i = 1; i < p; i++) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
        L->count++;
    }
}

/*============================================================================
 FUNCTION    : deleteFront
 DESCRIPTION : deletes node at the front/start of the list
 ARGUMENTS   : struct list *L
 RETURNS     : void
 ============================================================================*/

void deleteFront(struct list *L) {
    if (L->head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = L->head;
    L->head = L->head->next;
    free(temp);// freeing deletes the node
    L->count--;// reduce the count/ number of nodes/elements of the list

    if (L->head == NULL) {
        L->tail = NULL;
    }
}

/*============================================================================
 FUNCTION    : deleteRear
 DESCRIPTION : deletes node at the rear/end of the list
 ARGUMENTS   : struct list *L
 RETURNS     : void
 ============================================================================*/
void deleteRear(struct list *L) {
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

    struct node *current = L->head;
    while (current->next != L->tail) {
        current = current->next;
    }

    free(L->tail);
    L->tail = current;
    L->tail->next = NULL;
    L->count--;
}

/*============================================================================
 FUNCTION    : deleteAt
 DESCRIPTION : deletes node at a specific position on the list
 ARGUMENTS   : struct list *L, int p
 RETURNS     : void
 ============================================================================*/
void deleteAt(struct list *L, int p) {
    if (p < 0 || p >= L->count) {
        printf("Invalid p\n");
        return;
    }

    if (p == 0) {
        deleteFront(L);
    } else if (p == L->count - 1) {
        deleteRear(L);
    } else {
        struct node *current = L->head;
        for (int i = 1; i < p; i++) {
            current = current->next;
        }

        struct node *temp = current->next;
        current->next = temp->next;
        free(temp);
        L->count--;
    }
}

/*============================================================================
 FUNCTION    : displayAll
 DESCRIPTION : displays all of the nodes in the linked list
 ARGUMENTS   : struct list *L
 RETURNS     : void
 ============================================================================*/

void displayAll(struct list *L) {
    if (L->head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *current = L->head;
    while (current != NULL) {// while loop to iterrate through the whole list
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}


