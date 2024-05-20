/*============================================================================
 FILE        : main.c
 AUTHOR      : HIMMEL
 DESCRIPTION : This is the Main function of the program
 REVISION HISTORY

 ============================================================================*/
#include"sLL.h"
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

    insertFront(L, 2);  displayAll(L);

    insertFront(L, 1);  displayAll(L);

    insertFront(L, 0);  displayAll(L);

    insertRear(L, 3);  displayAll(L);

    insertRear(L, 5);  displayAll(L);

    insertAt(L, 4, 4);  displayAll(L);

    deleteFront(L);  displayAll(L);

    deleteRear(L);  displayAll(L);

    insertAt(L, 88, 2);  displayAll(L);

    deleteAt(L, 2);  displayAll(L);

    return 0;
}
