/*
=====================================================================================
 FILE        : main.c
 AUTHOR      : himmel
 DESCRIPTION : A program purely for testing purposes.
 COPYRIGHT   : 30 January 2024
=====================================================================================
*/

#include <stdio.h>
#include "vending.h"
#include "dispenser.h"
#include "cashregister.h"

// .c required for VS Compilation

/*
#include "vending.c"
#include "cashregister.c"
#include "dispenser.c"
*/

/*
============================================================================
 FUNCTION    : main
 DESCRIPTION : Executes the main program
 ARGUMENTS   : none
 RETURNS     : int - exit codes
============================================================================
*/

int main()
{
    // Data Structure for products
    Product products[4] = {
        {"Candy", 100, 15},
        {"Chips", 100, 25},
        {"Cookies", 100, 35},
        {"Soda", 100, 50}

    };

    loadData(products);
    while (1)
    {
        system("cls");
        sellProduct(products);
        saveData(products);
    }

    return 0;
}
