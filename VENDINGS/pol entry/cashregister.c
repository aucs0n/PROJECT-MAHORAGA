
/*============================================================================
 FILE        : cashregister.c
 AUTHOR      : Paul Andrew F. Parras , Jack David R. Pollo, Vaun Michael C. Pace
 DESCRIPTION : Contains the cash register functions of the project
 REVISION HISTORY
 Date: 			By: 		Description:
 01/29/30		Paul		added file and fuction details, included ponters for
                            structs
 ============================================================================*/
#include "vending.h"
#include "cashregister.h"
#include "dispenser.h"

/*============================================================================
 FUNCTION    : currentBalance
 DESCRIPTION : calculates the remaining amount to be paid
 ARGUMENTS   : int due - total amount to be paid
               int payment - intitial payment made
 RETURNS     : int - due - payment
 ============================================================================*/
int currentBalance(int due, int payment)
{
    return due-payment;
}
/*============================================================================
 FUNCTION    : acceptMoney
 DESCRIPTION : Eexecutes a succesfull transaction
 ARGUMENTS   : int choice - users choice of item
               int quantity - users preferred amount of quantity for item
               Item *items - pointer for strucy array
               int due - total cost of transaction
               int payment - total payment made
 RETURNS     : void
 ============================================================================*/
void acceptMoney(int choice, int quantity, Item *items, int due, int payment)
{
    if (payment > due)
    {
        for (int i = 0; i < quantity; i++)
        {
            items->pcs--;
        }
        printf("Transaction Successful\nYour change is: %d pesos\nPlese claim your item below", payment - due);
        getch();
        return;
    }
    for (int i = 0; i < quantity; i++)
    {
        items->pcs--;
    }
    printf("Transaction Successful\nPlese claim your item below");
    getch();
    return;
}
