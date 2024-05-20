
#ifndef VENDING_H
#define VENDING_H

#include "dispenser.h"
#include "cashregister.h"

int getCount(int choice, Item *items);
int getProductCost(int choice, int quantity, Item *items);  //function prortypes
void makeSale(int choice, int quantity, Item *items);


#endif
