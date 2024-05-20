#ifndef VENDING_H
#define VENDING_H

#include "cashregister.h"

int getCount(int productSelect, Product *products);
double getProductCost(int productSelect, int productQuantity, Product *products);
void makeSale(int productSelect, int productQuantity, Product *products);

#endif // VENDING_H
