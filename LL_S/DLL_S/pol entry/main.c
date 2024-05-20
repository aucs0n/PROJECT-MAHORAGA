/*============================================================================
 FILE        : main.c
 AUTHOR      : Paul Andrew F. Parras
 DESCRIPTION : contains the main function
 REVISION HISTORY
 Date: 			By: 		Description:

 ============================================================================*/

#include"dll.h"

int main() {
    struct list *L = (struct list *)malloc(sizeof(struct list));
    L->count = 0;
    L->head = L->tail = NULL;

    // Insert operations
    insertFront(L, 3);
    printList(L);

    insertFront(L, 2);
    printList(L);

    insertFront(L, 1);
    printList(L);

    insertRear(L, 5);
    printList(L);

    insertRear(L, 6);
    printList(L);

    insertAt(L, 4, 3);
    printList(L);

    insertAt(L, 7, 6);
    printList(L);

    insertAt(L, 0, 0);
    printList(L);

    // Remove operations
    removeFront(L);
    printList(L);

    removeRear(L);
    printList(L);

    removeRear(L);
    printList(L);

    // Insert and remove operations
    insertAt(L, 8, 2);
    printList(L);

    removeAt(L, 2);
    printList(L);

    // Display from rear to front
    printMirror(L);

    return 0;
}
