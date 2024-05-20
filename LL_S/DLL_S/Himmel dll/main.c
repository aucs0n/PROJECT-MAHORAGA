/*============================================================================
 FILE        : main.c
 AUTHOR      : himmel
 DESCRIPTION : This is the Main function of the program
 REVISION HISTORY
 Date: 2/06/2024 			By: Ghemarson John D. Nacua		Description: Organizing the main file
 ============================================================================*/
#include"dLL.h"
/*============================================================================
 FUNCTION    : main
 DESCRIPTION : Execute the main module
 ARGUMENTS   : none
 RETURNS     : int - returns exit code
 ============================================================================*/
int main()
{
    struct list *L = (struct list *)malloc(sizeof(struct list));
    L->count = 0;
    L->head = L->tail = NULL;

    insertFront(L, 3);  printList(L);

    insertFront(L, 2);  printList(L);

    insertFront(L, 1);  printList(L);

    insertRear(L, 5);  printList(L);

    insertRear(L, 6);  printList(L);

    insertAt(L, 4, 3);  printList(L);

    insertAt(L, 7, 6);  printList(L);

    insertAt(L, 0, 0);  printList(L);

    removeFront(L); printList(L);

    removeRear(L);  printList(L);

    removeRear(L);  printList(L);

    insertAt(L, 8, 2); printList(L);

    removeAt(L, 2);  printList(L);

    printMirror(L);

    return 0;
}
