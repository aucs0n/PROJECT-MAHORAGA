/*
=====================================================================================
FILE        : vending.h
AUTHOR      : himmel
DESCRIPTION : Contains structure and function prototypes declarations for main and
              common to all other modules.
COPYRIGHT   : 30 January 2024
=====================================================================================
*/

#include "vending.h"
#include "cashregister.h"
#include "dispenser.h"

/*
============================================================================
FUNCTION : showSelection
DESCRIPTION : Shows the products and their remaining stock left and their price.
ARGUMENTS :
Product products[4]:Data structure that contains the items and their details.

RETURNS : none - void.
===========================================================================
*/

void showSelection(Product products[4])
{
    // Display menu
    printf("\tVENDING MACHINE\n\n");
    printf("ID/NAME\t\tSTOCK\tPRICE\n");

    for (int i = 0; i < 3; i++)
    {
        printf("[%d]%s\t%d\tPHP %.2lf\n", i + 1, products[i].name, products[i].stock, products[i].cost);
    }

    printf("[4]%s\t\t%d\tPHP %.2lf\n", products[3].name, products[3].stock, products[3].cost);
    printf("[0]Exit\n");
    return;
}

/*
============================================================================
FUNCTION : sellProduct
DESCRIPTION : Asks the user the number of products they will buy and tells
              them if the item is out of stock.
ARGUMENTS :
Product products[4]:Data structure that contains the items and their details.

RETURNS : none - void.
===========================================================================
*/

void sellProduct(Product products[4])
{
    int productSelect, productQuantity, stockCheck;
    showSelection(products);

    do
    {
        // Asks the user to select an item
        printf("Please enter an item: ");
        scanf("%d", &productSelect);

        if (productSelect == 0) // User selected [0] Exit
        {
            printf("Please come again!\n.");
            Sleep(1000);
            printf(".");
            Sleep(1000);
            printf(".");
            Sleep(1000);
            getchar();
            exit(0);
        }
        else if (productSelect > 4 || productSelect < 0) // User entered a value outside the range of 0-4
        {
            printf("Input out of range, please try again.\n.");
            Sleep(1000);
            printf(".");
            Sleep(1000);
            printf(".");
            Sleep(1000);
            getchar();
            return;
        }

    } while (productSelect > 4); // Loop while the user enters anything other than 0 or numbers from 1-4

    productSelect = productSelect - 1;
    stockCheck = getCount(productSelect, products);

    if (stockCheck == 0) // Item selected is out of stock
    {
        printf("This item is out of stock. Please select another item.\n.");
        Sleep(1000);
        printf(".");
        Sleep(1000);
        printf(".");
        Sleep(1000);
        getchar();
        return;
    }

    // Asks the user how many units they want to buy.
    printf("Stock available: %d\nHow many would you like to purchase? ", stockCheck);
    scanf("%d", &productQuantity);

    if (productQuantity <= 0) // User inputted a number below 1
    {
        printf("Invalid input, returning to item selection\n.");
        Sleep(1000);
        printf(".");
        Sleep(1000);
        printf(".");
        Sleep(1000);
        getchar();
        return;
    }

    int count = getCount(productSelect, products);

    if (productQuantity <= count)
    {
        makeSale(productSelect, productQuantity, products);
    }
    else if (productQuantity > count) // Not enough stock
    {
        printf("Not enough stock, returning to item selection\n.");
        Sleep(1000);
        printf(".");
        Sleep(1000);
        printf(".");
        Sleep(1000);
        getchar();
        return;
    }
}

/*
============================================================================
FUNCTION : saveData
DESCRIPTION : Saves the data and makes the changes to the values after an item is bought
ARGUMENTS :
Product products[4]:Data structure that contains the items and their details.

RETURNS : none - void.
===========================================================================
*/

void saveData(Product products[4])
{
    FILE *fp = fopen("VendingData.txt", "w+");

    for (int i = 0; i < 4; i++) // Update stocks
    {
        fprintf(fp, "%s %d %lf\n", products[i].name, products[i].stock, products[i].cost);
    }
    fclose(fp);
    return;
}

/*
============================================================================
FUNCTION : loadData
DESCRIPTION : Loads the data from the file after changes to the price and stock.
ARGUMENTS :
Product products[4]:Data structure that contains the items and their details.

RETURNS : none - void.
===========================================================================
*/

void loadData(Product products[4])
{
    FILE *fp = fopen("VendingData.txt", "r+"); // Show stocks

    for (int i = 0; i < 5; i++)
    {
        fscanf(fp, "%s %d %lf\n", products[i].name, &products[i].stock, &products[i].cost);
    }
    fclose(fp);
    return;
}

/*
============================================================================
FUNCTION : clrscrn
DESCRIPTION : Clears the screen
ARGUMENTS : none
RETURNS : none - void.
===========================================================================
*/

void clrscrn()
{
    system("cls");
    return;
}
