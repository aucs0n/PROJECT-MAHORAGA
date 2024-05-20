/*============================================================================
 FILE        : dLL.c
 AUTHOR      : himmel
 DESCRIPTION : Functions that Inserts front, rear, and specific positions. Deletes front, rear,
               and specific positions
 REVISION HISTORY
 Date: 			By: 		Description:
 ============================================================================*/
#include "dLL.h"
/*============================================================================
 FUNCTION    : insertFront
 DESCRIPTION : inserts new node at the front
 ARGUMENTS   : struct list *L (a pointer that points to a specific struct list.)
                int x (a number data (variable) for the list.)
 RETURNS     : void
 ============================================================================*/

void insertFront(struct list *L, int x)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->prev = newNode-> next = NULL;

    if (L->head == NULL)
    {
        L->head = L->tail = newNode;
    }
    else
    {
        newNode->next = L->head;
        L->head->prev = newNode;
        L->head = newNode;
    }
    L->count++;
}

/*============================================================================
 FUNCTION    : insertRear
 DESCRIPTION : inserts new node at the rear
 ARGUMENTS   : struct list *L: (a pointer that points to a specific struct list.)
                int x  (a number data (variable) for the list.)
 RETURNS     : void
 ============================================================================*/

void insertRear(struct list *L, int x)
{
   struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->prev = newNode-> next = NULL;

    if (L->tail == NULL)
    {
        L->head = L->tail = newNode;
    }
    else
    {
        newNode->prev = L->tail;
        L->tail->next = newNode;
        L->tail = newNode;
    }
    L->count++;
}

/*============================================================================
 FUNCTION    : insertAt
 DESCRIPTION : inserts new node at a specific position
 ARGUMENTS   : struct list *L (a pointer that points to a specific struct list.)
                int x (a number data (variable) for the list.)
                int p (the position of the node that can be changed basing on the condition given.)
 RETURNS     : void
 ============================================================================*/
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
    }
    else if (p == L->count)
    {
        insertRear(L, x);
    }
    else
    {
        struct node *newNode = malloc(sizeof(struct node));
        newNode->data = x;
        newNode->prev = newNode->next = NULL;
        struct node *current = L->head;

        for (int i = 0; i < p - 1; i++)
        {
            current = current->next;
        }

        newNode->prev = current;
        newNode->next = current->next;
        current->next->prev = newNode;
        current->next = newNode;
        L->count++;
    }
}

/*============================================================================
 FUNCTION    : removeFront
 DESCRIPTION : deletes node at the front
 ARGUMENTS   : struct list *L (Pointer that points to a specific struct list.)
 RETURNS     : void
 ============================================================================*/

void removeFront(struct list *L)
{
    if (L->head == NULL)
    {
        printf("The list is empty\n");
        return;
    }

    struct node *temp = L->head;

    if (L->count == 1)
    {
        L->head = L->tail = NULL;
    }
    else
    {
        L->head = L->head->next;
        L->head->prev = NULL;
    }
    free(temp);

    L->count--;
}

/*============================================================================
 FUNCTION    : removeRear
 DESCRIPTION : deletes node at the rear
 ARGUMENTS   : struct list *L (Pointer that points to a specific struct list.)
 RETURNS     : void
 ============================================================================*/
void removeRear(struct list *L)
{
    if (L->tail == NULL)
    {
        printf("The list is empty\n");
        return;
    }

    struct node *temp = L->tail;

    if (L->count == 1)
    {
        L->head = L->tail = NULL;
    }
    else
    {
        L->tail = L->tail->prev;
        L->tail->next = NULL;
    }
    free(temp);

    L->count--;
}

/*============================================================================
 FUNCTION    : removeAt
 DESCRIPTION : deletes node at a specific position
 ARGUMENTS   : struct list *L (Pointer that points to a specific struct list.)
                int p (the position of the node that can be changed basing on the condition given.)
 RETURNS     : void
 ============================================================================*/
void removeAt(struct list *L, int p)
{
    if (p < 0 || p >= L->count)
    {
        printf("Invalid p\n");
        return;
    }

    if (p == 0)
    {
        removeFront(L);
    }
    else if (p == L->count - 1)
        {
        removeRear(L);
        }
    else
    {
        struct node *current = L->head;
        for (int i = 0; i < p; i++)
        {
            current = current->next;
        }

        current->prev->next = current->next;
        current->next->prev = current->prev;
        free(current);
        L->count--;
    }
}

/*============================================================================
 FUNCTION    : printList
 DESCRIPTION : displays all of the nodes
 ARGUMENTS   : struct list *L (Pointer that points to a specific struct list.)
 RETURNS     : void
 ============================================================================*/

void printList(struct list *L)
{
    struct node *current = L->head;
    while (current != NULL)
    {
        printf("%d ", current->data);

        current = current->next;
    }
    printf("\n\n");
}

/*============================================================================
 FUNCTION    : printMirror
 DESCRIPTION : prints the mirror or reverse  of the list
 ARGUMENTS   : struct list *L (Pointer that points to a specific struct list.)
 RETURNS     : void
 ============================================================================*/

void printMirror(struct list *L)
{
    struct node *current = L->tail;
    printf("Mirror/Reverse: ");
    while (current != NULL)
    {

        printf(" %d ", current->data);
        current = current->prev;
    }
    printf("\n\n");
}


