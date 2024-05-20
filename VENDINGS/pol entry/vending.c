/*============================================================================
 FILE        : vending.c
 AUTHOR      : Paul Andrew F. Parras , Jack David R. Pollo, Vaun Michael C. Pace
 DESCRIPTION : handles the vending components of the project
 REVISION HISTORY
 Date: 			By: 		Description:
 01/29/30		Paul		added file and fuction details, included ponters for
                            structs
 ============================================================================*/
#include "vending.h"
#include "cashregister.h"
#include "dispenser.h"

/*============================================================================
 FUNCTION    : showSelection
 DESCRIPTION : display the menu
 ARGUMENTS   : Item items - struct array for items
 RETURNS     : void
 ============================================================================*/
void showSelection(Item items[4])
{
    printf("WELCOME TO SNACKSARAP VENDING MACHINE\n");
    printf("==========================================\n");
    printf("#ITEM\t\tCOST\tQUANTITY\n");
    for (int i = 0; i < 3; i++)
    {

        printf("[%d]%s\t%d\t%d\n", i + 1, items[i].name, items[i].cost, items[i].pcs);
    }
    printf("[4]%s\t\t%d\t%d\n", items[3].name, items[3].cost, items[3].pcs);
    printf("[5] Quit\n");
    printf("==========================================");
    return;
}
/*============================================================================
 FUNCTION    : sellProduct
 DESCRIPTION : function that initiates the selling sequence
 ARGUMENTS   : Item items - struct array for items
 RETURNS     : void
 ============================================================================*/

void sellProduct(Item items[4])
{
    int choice, quantity, due, totalPayment, initial, checkStock;
    showSelection(items);
    do
    {
        printf("\nWhich one would you like(1-5)?: ");
        scanf("%d", &choice);
        if (choice == 5)
        {
            printf("Thank you for  shopping!");
            getch();
            exit(0);
        }
        if (choice > 5)
        {
            printf("Invalid choice please try again");
            getch();
            return;
        }
    } while (choice > 5);
    choice = choice - 1;
    checkStock = getCount(choice, &items[choice]);
    if (checkStock == 0)
    {
        printf("Sorry there is not enough stock of this item");
        getch();
        return;
    }
    printf("How many pcs would you like?: ");
    scanf("%d", &quantity);
    int count = getCount(choice, &items[choice]);
    if (quantity <= count)
    {

        makeSale(choice, quantity, items);
    }
    else if (quantity > count)

    {
        printf("Sorry there is not enough stock of this item");
        getch();
        return;
    }
}
/*============================================================================
 FUNCTION    : saveData
 DESCRIPTION : contains file handling to save the data of the vending machine
 ARGUMENTS   : Item items - struct array for items
 RETURNS     : void
 ============================================================================*/
void saveData(Item items[4])
{
    FILE *fp = fopen("Data.txt", "w+");

    for (int i = 0; i < 4; i++)
    {
        fprintf(fp, "%s %d %d\n", items[i].name, items[i].cost, items[i].pcs);
    }
    fclose(fp);
    return;
}
/*============================================================================
 FUNCTION    : loadData
 DESCRIPTION : contains file handling to load the data from file for the
               vending machine
 ARGUMENTS   : Item items - struct array for items
 RETURNS     : void
 ============================================================================*/
void loadData(Item items[4])
{
    FILE *fp = fopen("Data.txt", "r+");

    for (int i = 0; i < 5; i++)
    {
        fscanf(fp, "%s %d %d\n", items[i].name, &items[i].cost, &items[i].pcs);
    }
    fclose(fp);
    return;
}
/*============================================================================
 FUNCTION    : clrscrn
 DESCRIPTION : clears the screen
 ARGUMENTS   : none
 RETURNS     : return
 ============================================================================*/
void clrscrn()
{
    system("cls");
    return;
}

// gcc -o main vending.c cashregister.c dispenser.c main.c
