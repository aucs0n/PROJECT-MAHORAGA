#ifndef CASHREGISTER_H
#define CASHREGISTER_H

#include "vending.h"

double currentBalance(double netCost, double netPaid);
void acceptMoney(int productSelect,int productQuantity,Product *products,double netPayment,double paid);

#endif  // CASHREGISTER_H