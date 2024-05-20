/*
================================================================================
FILE        : main.c
AUTHOR      : himmel
DESCRIPTION : Program that does operations in both recursive and iterative methods
COPYRIGHT   : February 19 2024
REVISION HISTORY
Date: 			By: 		Description:
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include "operations.h"


bool getPosInt(int *n);

/*
================================================================================
FUNCTION    : main
DESCRIPTION : Execute the main program that calls functions for each operation
ARGUMENTS   : void
RETURNS     : int - exit code
================================================================================
*/
int main()
{
	int n, i;
	bool f;
	char c;
	for(;;)
    {
		printf("Input number: ");
		f=getPosInt(&n);
		if(!f)
		{
			printf("Please input positive numbers only");
			getch();
			system("cls");
		}
        else
        {
			printf("\nFactorial series using non-recursive function.\n");
			i_factorial((long)n);

			printf("\nFactorial series using recursive function.\n");
			r_factorial((long)n);

			printf("\nFibonacci series using non-recursive function.\n");
			i_fibonacci((long)n);

			printf("\nFibonacci series using recursive function.\n");
			if(n==0){
					printf("   NA");
			}
			for(i=1;i<=n;i++){
				printf("   %li", r_fibonacci(i));
			}

			printf("\nSum series using non-recursive function.\n");
			i_sum((long)n);

			printf("\nSum series using recursive function.\n");
			r_sum((long)n);

			printf("\n\n\nPress 0 to exit\nPress any key for new input");
			c=getch();
			system("cls");
			if(c=='0')
            {
				printf("GoodBye >:)");
				exit(0);
			}
		}
	}

	return 0;
}

/*
================================================================================
FUNCTION    : getPosInt
DESCRIPTION : accepts a positive input integer
ARGUMENTS   : int *n - pointer to the variable to store data in
RETURNS     : bool - returns 1 if input is successful; returns 0 if not.
================================================================================
*/
bool getPosInt(int *n){
	bool f;
	if(!scanf("%d", n)||*n<0){
		f=0;
		*n=-1;
	}else{
		f=1;
	}
	fflush(stdin);
	return f;
}
