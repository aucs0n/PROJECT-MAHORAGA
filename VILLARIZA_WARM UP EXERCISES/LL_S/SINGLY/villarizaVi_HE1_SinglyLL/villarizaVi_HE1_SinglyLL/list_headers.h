#ifndef SLL_H
#define SLL_H



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
void deleteEnd(struct list *L);
void removeAtNode(struct list *L, int p);
void wholeDisp(struct list *L);


#endif
