/*============================================================================
 FILE        : main.c
 AUTHOR      : Paul Andrew F. Parras , Jack David R. Pollo, Vaun Michael C. Pace
 DESCRIPTION : executes the main program of the project
 REVISION HISTORY
 Date: 			By: 		Description:
 01/29/30		Paul		added file and fuction details, included ponters for
                            structs
 ============================================================================*/
#include <stdio.h>
#include "vending.h"
#include "cashregister.h"
#include "dispenser.h"
/*============================================================================
 FUNCTION    : main
 DESCRIPTION : Execute the main module
 ARGUMENTS   : none
 RETURNS     : int - returns exit code
 ============================================================================*/
int main()
{
    Item items[4] = {
        {"Candy", 5, 100},
        {"Chips", 15, 100},
        {"Cookies", 30, 100},
        {"Soda", 45, 100}

    };

    loadData(items);
    while (1)
    {
        clrscrn();
        sellProduct(items);
        saveData(items);
    }

    return 0;
}
