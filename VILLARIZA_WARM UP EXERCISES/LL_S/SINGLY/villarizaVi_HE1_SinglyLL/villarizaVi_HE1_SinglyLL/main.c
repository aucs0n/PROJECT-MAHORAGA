#include<stdio.h>
#include<stdlib.h>
#include"list_headers.h"


int main() {
    struct list *L = (struct list *)malloc(sizeof(struct list));
    L->count = 0;
    L->head = L->tail = NULL;


    insertFront(L, 2);
    wholeDisp(L);

    insertFront(L, 1);
    wholeDisp(L);

    insertFront(L, 0);
    wholeDisp(L);

    insertRear(L, 3);
    wholeDisp(L);

    insertRear(L, 5);
    wholeDisp(L);

    insertAt(L, 4, 4);
    wholeDisp(L);

    deleteFront(L);
    wholeDisp(L);


    deleteEnd(L);
    wholeDisp(L);


    insertAt(L, 88, 2);
    wholeDisp(L);

    removeAtNode(L, 2);
    wholeDisp(L);

    return 0;
}
