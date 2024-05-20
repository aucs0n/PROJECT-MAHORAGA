/*============================================================================
 FILE        : main.c
 AUTHOR      : himmel
 DESCRIPTION : This is the Main function of the program
 REVISION HISTORY
 Date: 2/22/2024 			By: Ghemarson John D. Nacua		Description: Organizing the main file
 ============================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include "list.h"
#include "search.h"
#define TRUE	1
#define FALSE	0

void displayMenu();

/* ================================================================================
 FUNCTION        : main
 DESCRIPTION     : Executes the whole program where it sets head and tail to NULL,
                   it also performs switch case depending on the choice of the user
 ARGUMENTS       : none
 RETURNS         : int - returns 0 to exit
 ================================================================================ */
int main()
{
	char ch;
	int ndata, key, location;
	bool start = FALSE, found = FALSE;

	LIST *data = (LIST*)malloc(sizeof(LIST));
	data->head=NULL;
	data->tail=NULL;
    data->count = 0;
	for(;;)
    {
		displayMenu();
		ch=getche();

		switch(ch)
		{
		case '1':
			printf("\nHow many values: ");
			if(scanf("%d",&ndata)==1&&ndata>1&&ndata<11)
            {
				createList(data,ndata);
				selectionSort(data);
				start=TRUE;
				printf("\nLIST CREATED\n");
			}
			else
            {
				printf("\nNot a valid number\n");
				fflush(stdin);
			}
			break;
		case '2':
			if(start==TRUE)
            {
				displayList(data);
			}
			else
            {
				printf("\nPlease create list first");
			}
			break;
		case '3':
			if(start==TRUE)
            {
				printf("\nInput data to be searched: ");
				if(scanf("%d", &key))
				{
					found=binarySearch(data, key, &location);
					if(found)
					{
						printf("\nSEARCH FOUND in location : %d", location);
					}
					else
                    {
                        printf("\nSEARCH NOT FOUND");
					}
				}
                else
                {
					printf("\nNot a valid number\n");
					fflush(stdin);
				}
			}
			else
            {
				printf("\nPlease create list first");
			}
			break;
		case '4':
			if(start==TRUE)
            {
				printf("\nInput data to be searched: ");
				if(scanf("%d", &key))
				{
					found=linearSearch(data, key, &location);
					if(found)
					{
						printf("\nSEARCH Found in location : %d", location);
					}
                    else
                    {
						printf("\nSEARCH NOT FOUND");
					}
				}
                else
                {
					printf("\nNot a valid number\n");
					fflush(stdin);
				}
			}
			else
            {
				printf("\nPlease create list first");
			}
			break;
		case '5':
			exit(0);
			break;
		}
		getch();
		system("cls");
	}
	return 0;
}
/* ================================================================================
 FUNCTION        : displayMenu
 DESCRIPTION     : Displays the main menu of the program
 ARGUMENTS       : none
 RETURNS         : void
 ================================================================================ */
void displayMenu()
{
    printf("[LINEAR AND BINARY SEARCH] \n");
	printf("[1]- Create List \n");
	printf("[2]- Display List \n");
	printf("[3]- Binary Search \n");
	printf("[4]- Linear Search \n");
	printf("[5]- Exit \n");
}
