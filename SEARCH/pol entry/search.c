/*============================================================================
 FILE        : search.c
 AUTHOR      : Paul Andrew F. Parras
 DESCRIPTION : contains the functions that deals with creating the list,
                sorting the list, and searching through the list
 REVISION HISTORY
 Date: 			By: 		Description:
 2/24/2024      Paul		added file and fuction details, remove text
 							functions, modify function prototypes
 ============================================================================*/
#include"search.h"

/*============================================================================
 FUNCTION    : add
 DESCRIPTION : adds an integer to the linked list
 ARGUMENTS   : List *data - the list of nodes
               int x - the data to be added to the list
 RETURNS     : void
 ============================================================================*/
void add(List *data, int x)
{
    node *newNode = malloc(sizeof(node));
    newNode->data = x;
    newNode->prev = newNode->next = NULL;

    if(data->head == NULL)
    {
        data->head = data->tail = newNode;
    }
    else
    {
        newNode->prev = data->tail;
        data->tail->next = newNode;
        data->tail = newNode;
    }
    data->count++;
}
/*============================================================================
 FUNCTION    : displayList
 DESCRIPTION : displays the linked list
 ARGUMENTS   : List *data - the linked list
 RETURNS     : void
 ============================================================================*/
void displayList(List *data)
{
    node *temp = data->head;
    while(temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}
/*============================================================================
 FUNCTION    : getTail
 DESCRIPTION : returns the tail node of a linked list
 ARGUMENTS   : node* cur - the current node
 RETURNS     : node* - the tail node
============================================================================*/
node* getTail(node* cur) {
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}

/*============================================================================
 FUNCTION    : partition
 DESCRIPTION : partitions the linked list for quicksort
 ARGUMENTS   : node* head - the head node of the list
               node* end - the end node of the list
               node** newHead - pointer to the new head node after partition
               node** newEnd - pointer to the new end node after partition
 RETURNS     : node* - the pivot node
============================================================================*/
node* partition(node* head, node* end, node** newHead, node** newEnd) {
    node* pivot = end;
    node* prev = NULL, *cur = head, *tail = pivot;

    while (cur != pivot) {
        if (cur->data < pivot->data) {
            if ((*newHead) == NULL)
                (*newHead) = cur;
            prev = cur;
            cur = cur->next;
        } else {
            if (prev)
                prev->next = cur->next;
            node* tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    if ((*newHead) == NULL)
        (*newHead) = pivot;

    (*newEnd) = tail;

    return pivot;
}

/*============================================================================
 FUNCTION    : quickSortRecur
 DESCRIPTION : recursively sorts a linked list using quicksort
 ARGUMENTS   : node* head - the head node of the list
               node* end - the end node of the list
 RETURNS     : node* - the new head node after sorting
============================================================================*/
node* quickSortRecur(node* head, node* end) {
    if (!head || head == end)
        return head;

    node* newHead = NULL, *newEnd = NULL;

    node* pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        node* tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;

        newHead = quickSortRecur(newHead, tmp);

        tmp = getTail(newHead);
        tmp->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}
/*============================================================================
 FUNCTION    : quickSort
 DESCRIPTION : initiates quicksort on a linked list
 ARGUMENTS   : node** headRef - pointer to the head node of the list
 RETURNS     : void
============================================================================*/
void quickSort(node** headRef) {
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
    return;
}

/*============================================================================
 FUNCTION    : linear_search
 DESCRIPTION : performs linear search on a linked list
 ARGUMENTS   : List* data - the list of nodes
               int key - the value to search for
               int* location - pointer to store the location if found
 RETURNS     : bool - true if key is found, false otherwise
============================================================================*/
bool linear_search(List* data, int key, int *location) {
    node* temp = data->head;
    int i = 0;
    while(temp != NULL) {
        if(temp->data == key) {
            return true;
        }
        i++;
        *(location) = i;
        temp = temp->next;
    }
    return false;
}
/*============================================================================
 FUNCTION    : binary_search
 DESCRIPTION : performs binary search on a linked list
 ARGUMENTS   : List* data - the list of nodes
               int key - the value to search for
               int* location - pointer to store the location if found
 RETURNS     : bool - true if key is found, false otherwise
============================================================================*/
bool binary_search(List* data, int key, int* location) {
    if (data->count == 0) {
        return false;
    }

    int left = 0, right = data->count - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        node* temp = data->head;
        for (int i = 0; i < mid; i++) {
            temp = temp->next;
        }
        if (temp->data == key) {
            *location = mid;
            return true;
        }
        if (temp->data < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false;
}
/*============================================================================
 FUNCTION    : createList
 DESCRIPTION : generates a random list of 10 elements for testing
 ARGUMENTS   : List *data - the list of nodes
 RETURNS     : void
============================================================================*/
void createList(List *data)
{
    int n, i;

	time_t t;
	srand((unsigned) time(&t));

	for(i=0; i<10; i++)
	{
		n = rand() % 101;
		add(data,n);
	}
}
