/*============================================================================
 FILE        : main.c
 AUTHOR      : Paul Andrew F. Parras
 DESCRIPTION : contains main function of the program
 REVISION HISTORY
 Date: 			By: 		Description:
 2/14/2024		Paul		added file and function details
 2/15/2024      Paul        transferred displayList() function to main
 2/15/2024      Desiree     modified main function and corrected spellings
============================================================================*/


#include "statistics.h"



/*============================================================================
 FUNCTION    : main
 DESCRIPTION : Execute the main module
 ARGUMENTS   : none
 RETURNS     : int - returns exit code
============================================================================*/
int main()
{
    bool statCreated = false;
    int x;
    Statistician s;
    char c;
    for (;;)
    {
        do
        {
            system("cls");
            menu();
            c = getch();
        } while (c != '1' && c != '2' && c != '3' && c != '4' && c != '5' && c != '6');
        switch (c)
        {
        case '1':
            system("cls");
            if (statCreated == true)
            {
                system("cls");
                printf("Sorry, statistician is already created");
                getch();
                break;
            }
            s = newStatistician();
            printf("Creating statistician ");
            for (int i = 0; i < 5; i++)
            {
                printf(". ");
                sleep(1);
            }
            printf("\nNew statistician created");
            statCreated = true;
            getch();
            break;
        case '2':
            if (statCreated == false)
            {
                system("cls");
                printf("NO STATISTICIAN CREATED YET");
                getch();
                break;
            }
            else
            {

                system("cls");
                destroyStatistician(&s);
                printf("Destroying ");
                for (int i = 0; i < 5; i++)
                {
                    printf(". ");
                    sleep(1);
                }
                printf("\nSuccessfully destroyed statistician!");
                statCreated = false;
                getch();
                break;
            }
        case '3':
            if (statCreated == false)
            {
                system("cls");
                printf("NO STATISTICIAN YET");
                getch();
                break;
            }
            else
            {
                system("cls");
                displayList(&s);
                printf("Enter data: ");
                scanf("%d", &x);
                add(&s, x);
                printf("Data Added");
                getch();
                break;
            }
        case '4':
            if (statCreated == false)
            {
                system("cls");
                printf("NO STATISTICIAN YET");
                getch();
                break;
            }
            else
            {
                if (isEmpty(&s) == true)
                {
                    system("cls");
                    printf("NO DATA YET");
                    getch();
                    break;
                }
                else
                {

                    system("cls");
                    displayList(&s);
                    printf("Enter data to be removed: ");
                    scanf("%d", &x);
                    removeStats(&s, x);
                    getch();
                    break;
                }
            }

        case '5':
            if (statCreated == true)
            {
                if (isEmpty(&s) == true)
                {
                    system("cls");
                    printf("NO DATA YET");
                    getch();
                    break;
                }
                else
                {
                    displayData(&s);
                    break;
                }
            }
            else
            {
                system("cls");
                printf("NO STATISTICIAN CREATED YET");
                getch();
                break;
            }

        case '6':
            system("cls");
            printf("Thankyou for using our program!");
            getch();
            exit(0);
        default:
            system("cls");
            printf("Incorrect choice! Try again");
        }
    }
}

/*============================================================================
 FUNCTION    : menu
 DESCRIPTION : displays the menu
 ARGUMENTS   : none
 RETURNS     : void
 ============================================================================*/
void menu()
{
    printf("=================================\n");
    printf("[1] New Statistician\n");
    printf("[2] Destroy Statistician\n");
    printf("[3] Add Data\n");
    printf("[4] Delete Data\n");
    printf("[5] Display Statistics\n");
    printf("[6] QUIT\n");
    printf("=================================\n");
    return;
}
