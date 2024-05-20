/*============================================================================
 FILE        : dll.c
 AUTHOR      : Paul Andrew F. Parras
 DESCRIPTION : contains the functions that insert and remove nodes at spcecific
                coordinates
 REVISION HISTORY
 Date: 			By: 		Description:

 ============================================================================*/
#include"dll.h"


// Function to insert element at the front/start/first of the list
void insertFront(struct list *L, int x) {
    struct node *real = malloc(sizeof(struct node));
    real->data = x;
    real->prev = real->next = NULL;

    if (L->head == NULL) {
        L->head = L->tail = real;
    } else {
        real->next = L->head;
        L->head->prev = real;
        L->head = real;
    }

    L->count++;
}

// Function to insert element at the rear/end/last of the list
void insertRear(struct list *L, int x) {
    struct node *real = malloc(sizeof(struct node));
    real->data = x;
    real->prev = real->next = NULL;

    if (L->tail == NULL) {
        L->head = L->tail = real;
    } else {
        real->prev = L->tail;
        L->tail->next = real;
        L->tail = real;
    }

    L->count++;
}

// Function to insert element at a specified position in the list
void insertAt(struct list *L, int x, int p) {
    if (p < 0 || p > L->count) {
        printf("Invalid position\n");
        return;
    }

    if (p == 0) {
        insertFront(L, x);
    } else if (p == L->count) {
        insertRear(L, x);
    } else {
        struct node *real = malloc(sizeof(struct node));
        real->data = x;
        real->prev = real->next = NULL;
        struct node *current = L->head;

        for (int i = 0; i < p - 1; i++) {
            current = current->next;
        }

        real->prev = current;
        real->next = current->next;
        current->next->prev = real;
        current->next = real;

        L->count++;
    }
}

// Function to remove element at the front/start/first of the list
void removeFront(struct list *L) {
    if (L->head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = L->head;

    if (L->count == 1) {
        L->head = L->tail = NULL;
    } else {
        L->head = L->head->next;
        L->head->prev = NULL;
    }

    free(temp);
    L->count--;
}

// Function to remove element at the rear/end/last of the list
void removeRear(struct list *L) {
    if (L->tail == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node *temp = L->tail;

    if (L->count == 1) {
        L->head = L->tail = NULL;
    } else {
        L->tail = L->tail->prev;
        L->tail->next = NULL;
    }

    free(temp);
    L->count--;
}

// Function to remove element at a specified position in the list
void removeAt(struct list *L, int p) {
    if (p < 0 || p >= L->count) {
        printf("Invalid position\n");
        return;
    }

    if (p == 0) {
        removeFront(L);
    } else if (p == L->count - 1) {
        removeRear(L);
    } else {
        struct node *current = L->head;

        for (int i = 0; i < p; i++) {
            current = current->next;
        }

        current->prev->next = current->next;
        current->next->prev = current->prev;

        free(current);
        L->count--;
    }
}

// Function to display all elements in the list from front to rear
void printList(struct list *L) {
    struct node *current = L->head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to display all elements in the list from rear to front
void printMirror(struct list *L) {
    struct node *current = L->tail;

    printf("Mirror:  ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}
