/*
=====================================================================================
FILE        : dispenser.h
AUTHOR      : himmel
DESCRIPTION : Contains function prototypes declarations for dispenser components
COPYRIGHT   : 30 January 2024
=====================================================================================
*/

#include "vending.h"
#include "cashregister.h"
#include "dispenser.h"

/*
============================================================================
FUNCTION : getCount
DESCRIPTION : Checks the amount of stock of a certain item.
ARGUMENTS :
int productSelect: Input received from the user after choosing a product.
Product *products: Points to the product structure.

RETURNS : products[productSelect].stock: Returns the value of the stock of a specific item.
===========================================================================
*/

int getCount(int productSelect, Product *products)
{
    return products[productSelect].stock;
}

/*
============================================================================
FUNCTION : getProductCost
DESCRIPTION : Calculates the total cost of the product by multiplying the quantity of a specific item and its cost.
ARGUMENTS :
int productSelect: Input received from the user after choosing a product.
int productQuantity: Amount of product currently available.
Product *products: Pointer that points to the product structure.
RETURNS : double price: Returns the cost to be paid after multiplying productQuantity with products[productSelect].cost
===========================================================================
*/

double getProductCost(int productSelect, int productQuantity, Product *products)
{
    double price = productQuantity * products[productSelect].cost;
    return price;
}

/*
============================================================================
FUNCTION : makeSale
DESCRIPTION : Prompts the user the amount needed to pay and
              includes conditions if the user pays the sufficient or insufficient amount.
ARGUMENTS :
int productSelect: Input received from the user after choosing a product.
int productQuantity: Amount of product currently available.
Product *products: Pointer that points to the product structure.
RETURNS : none - void
===========================================================================
*/

void makeSale(int productSelect, int productQuantity, Product *products)
{
    double netPaid;
    double netCost = getProductCost(productSelect, productQuantity, products);

    // Asks the user to pay
    printf("Total Price: PHP %.2lf\nPlease pay below.\nPHP ", netCost);
    scanf("%lf", &netPaid);
    getchar();

    if (netPaid < 0) // If the input is negative number
    {
        printf("Invalid input for payment detected. This transaction has been terminated.\n.");
        Sleep(1000);
        printf(".");
        Sleep(1000);
        printf(".");
        Sleep(1000);
        return;
    }

    if (netPaid >= netCost) // Exact or overpayment
    {
        acceptMoney(productSelect, productQuantity, products, netCost, netPaid);
        return;
    }
    else if (netPaid < netCost) // Insuffient Payment
    {
        double addedPayment;

        // Asks the user for additional payment
        printf("Remaining Payment: PHP %.2lf\nPlease pay the remaining amount.\nPHP ", currentBalance(netCost, netPaid));
        scanf("%lf", &addedPayment);
        getchar();

        if (addedPayment < 0) // If additional payment is also negative
        {
            printf("Invalid input for payment detected. This transaction has been terminated.\n");
            printf("PHP %.2lf has been returned.\n.", netPaid);
            Sleep(1700);
            printf(".");
            Sleep(1600);
            printf(".");
            Sleep(1600);
            return;
        }

        netPaid = netPaid + addedPayment;

        if (netPaid >= netCost) // Added payment enough to cover cost
        {
            acceptMoney(productSelect, productQuantity, products, netCost, netPaid);
            return;
        }
        else if (netPaid < netCost) // Insufficient additional payment
        {
            printf("Insufficient payments made. This transaction has been terminated.\n");
            printf("PHP %.2lf has been returned.\n.", netPaid);
            Sleep(1700);
            printf(".");
            Sleep(1600);
            printf(".");
            Sleep(1600);
            return;
        }
    }
}
