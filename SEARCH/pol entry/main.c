/*============================================================================
 FILE        : main.c
 AUTHOR      : Paul Andrew F. Parras
 DESCRIPTION : contains the main function of the program
 REVISION HISTORY
 Date: 			By: 		Description:
 2/24/2024      Paul		added function details
 ============================================================================*/
#include"search.h"


/*============================================================================
 FUNCTION    : main
 DESCRIPTION : Execute the main module
 ARGUMENTS   : none
 RETURNS     : int - returns exit code
 ============================================================================*/
int main()
{
   	List *a = malloc(sizeof(List));
    a->count = 0;
    a->head = a->tail = NULL;
	int key, location = 0;



	for(;;)
	{
		char choice;
		do
		{
			system("cls");
			printf("==============================\n");
			printf("[1] Create List\n[2] Display List\n[3] Linear Search\n[4] Binary Search\n[5] Exit\n");
			printf("==============================\n");
			choice = getch();
		} while (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5');

		switch(choice)
		{
			case '1':

			if(a->head == NULL)
			{
				createList(a);
				system("cls");
				printf("LIST CREATED");
				getch();
				break;
			}
			else
			{
				system("cls");
				printf("Sorry, there is already a list created");
				getch();
				break;
			}
			case '2':
			system("cls");
			if(a->head == NULL)
			{
				system("cls");
				printf("NO DATA YET");
				getch();
				break;

			}
			else{
			printf("LOCATION:\n");
			for(int i = 0; i < a->count; i++)
			{
				printf("%d\t", i);
			}
			printf("\nDATA:\n");
			displayList(a);
			getch();
			break;}
			case '3':
      if(a->head == NULL)
			{
				system("cls");
				printf("NO DATA YET");
				getch();
				break;

			}
			printf("Enter number to search: ");
                scanf("%d", &key);
                if(linear_search(a, key, &location) == true) {
                    printf("Number found at location %d.\n", location);
                } else {
                    printf("Number not found.\n");
                }
				getch();
            break;
			case '4':
      if(a->head == NULL)
			{
				system("cls");
				printf("NO DATA YET");
				getch();
				break;

			}
			printf("Enter number to search: ");
                scanf("%d", &key);

                if(binary_search(a, key, &location) == true) {
                    printf("Number found at location %d.\n", location);
                } else {
                    printf("Number not found.\n");
                }
				getch();
            break;
			case '5':
			system("cls");
			printf("Thank you for using our program!");
			getch();
			exit(0);
			default:
			printf("Invalid Choice");
			getch();


		}
	}

	return 0;
}
