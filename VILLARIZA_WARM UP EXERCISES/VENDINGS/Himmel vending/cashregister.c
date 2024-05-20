/*
=====================================================================================
FILE        : cashregister.h
AUTHOR      : himmel
DESCRIPTION : Contains function prototypes declarations for cash register components
COPYRIGHT   : 30 January 2024
=====================================================================================
*/

#include "vending.h"
#include "cashregister.h"
#include "dispenser.h"

/*
============================================================================
FUNCTION : currentBalance
DESCRIPTION : Calculates the remaining balance.
ARGUMENTS : (list all parameters pass in the function)
double netCost: Total amount to pay.
double netPaid: Total amount the user has paid.

RETURNS : double currentBalance: The current balance after subtracting net cost from net amount.
===========================================================================
*/

double currentBalance(double netCost, double netPaid)
{
    return netCost - netPaid;
}

/*
============================================================================
FUNCTION : acceptMoney
DESCRIPTION : Displays the result of the successful transaction from the vending machine
              and dispenses the item and change.
ARGUMENTS : (list all parameters pass in the function)
int productSelect: Input received from the user after choosing a product.
int productQuantity: Amount of product currently available.
Product *products: Points to the product structure.
double netCost: Total amount to pay.
double netPaid: Total amount the user has paid.

RETURNS : none - void.
===========================================================================
*/

void acceptMoney(int productSelect, int productQuantity, Product *products, double netCost, double netPaid)
{

    for (int i = 0; i < productQuantity; i++) // Remove items from stock
    {
        products[productSelect].stock--;
    }

    if (netPaid > netCost) // Overpayment
    {
        // Gives item/s and change
        printf("Successful Transaction!\nPlease claim your item and change below.");
        printf("\nYour change is PHP %.2lf\n.", netPaid - netCost);
        Sleep(2300);
        printf(".");
        Sleep(2300);
        printf(".");
        Sleep(2400);
    }
    else // Exact Payment
    {
        // Gives item/s
        printf("Successful Transaction!\nPlease claim your item below.\n.");
        Sleep(1000);
        printf(".");
        Sleep(1000);
        printf(".");
        Sleep(1000);
    }
}
