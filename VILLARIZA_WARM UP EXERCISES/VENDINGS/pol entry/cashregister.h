
#ifndef CASHREGISTER_H
#define CASHREGISTER_H

#include "vending.h"

int currentBalance(int due, int payment);
void acceptMoney(int choice, int quantity, Item *items, int due, int payment);  // function prototypes

#endif
