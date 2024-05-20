
/*============================================================================
 FILE        : dispenser.c
 AUTHOR      : Paul Andrew F. Parras , Jack David R. Pollo, Vaun Michael C. Pace
 DESCRIPTION : contains the functions that make up the dispenser of the vending
               machine
 REVISION HISTORY
 Date: 			By: 		Description:
 01/29/30		Paul		added file and fuction details, included ponters for
                            structs
 ============================================================================*/
#include "vending.h"
#include "cashregister.h"
#include "dispenser.h"
/*============================================================================
 FUNCTION    : mgetCount
 DESCRIPTION : determines the amount of pcs(stock) left for the item
 ARGUMENTS   : int choice - the users choice of item
               Item *items - pointer for the struct array
 RETURNS     : int - returns items->pcs
 ============================================================================*/
int getCount(int choice, Item *items)
{
    return items->pcs;
}
/*============================================================================
 FUNCTION    : getProductCost
 DESCRIPTION : determinse the total cost of the transaction
 ARGUMENTS   : int choice - the users choice of item
               int quantity - users preferred amount of quantity of item
               Item *items - pointer for struct array
 RETURNS     : int cost - total cost of transaction
 ============================================================================*/
int getProductCost(int choice, int quantity, Item *items)
{
    int cost = quantity * items->cost;
    return cost;
}
/*============================================================================
 FUNCTION    : makeSale
 DESCRIPTION : handles the function which asks the user for payments
 ARGUMENTS   : int choice - users choice of item
                int quantity - users preferred amount of quantity for item
                Item *items - pointer for struct
 RETURNS     : void
 ============================================================================*/
void makeSale(int choice, int quantity, Item *items)
{
    int due = getProductCost(choice, quantity, &items[choice]);
    int payment;
    printf("Please deposit %d pesos: ", due);
    scanf("%d", &payment);

    if (payment >= due)
    {
        acceptMoney(choice, quantity, &items[choice], due, payment);
        return;
    }
    else if (payment < due)
    {
        int additional;
        printf("The money you deposited is not enough, please add more\n");
        printf("Enter remaining balance %d pesos: ", (currentBalance(due,payment)));
        scanf("%d", &additional);
        payment = payment + additional;
        if (payment >= due)
        {
            acceptMoney(choice, quantity, &items[choice], due, payment);
            return;
        }
        else if (payment < due)
        {
            printf("Sorry, the deposited amount is still not enough and you have already reached 2 tries\n");
            printf("Transaction Terminated\n");
            printf("Your payment of %d pesos will be returned to you now", payment);
            getch();
            return;
        }
    }
}
