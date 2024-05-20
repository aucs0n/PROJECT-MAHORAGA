/*============================================================================
 FILE        : iterate.c
 AUTHOR      : Paul Andrew F. Parras
 DESCRIPTION : contains the functions that has the iterative functions for the program
 REVISION HISTORY
 Date: 			By: 		Description:

 ============================================================================*/

#include"header.h"
/*============================================================================
 FUNCTION    : int factIterate
 DESCRIPTION : iterative function to solve for factorial
 ARGUMENTS   : int n = number of integers
 RETURNS     : int f - the factorial
 ============================================================================*/
int factIterate(int n)
{
    int f = 1;
    for(int i = 1; i <= n; i++)
    {
        f *= i;
    }
    return f;
}

/*============================================================================
 FUNCTION    : int fibIterate
 DESCRIPTION : iterative function to solve and print the fibonacci sequence
 ARGUMENTS   : int n = number of integers
 RETURNS     : void
 ============================================================================*/
void fibIterate(int n)
{
    int prev = 0, prev2 = 1;
    printf("%d ", 1);
    for(int i = 3; i <= n+1; i++)
    {
        int next = prev + prev2;
        printf("%d ", next);
        prev = prev2;
        prev2 = next;
    }
}
/*============================================================================
 FUNCTION    : int sumIterate
 DESCRIPTION : iterative function to solve for sum
 ARGUMENTS   : int n = number of integers
 RETURNS     : int s - the sum
 ============================================================================*/
int sumIterate(int n)
{
    int s = 0;
    for(int i = 0; i < n; i++)
    {
        s += i;
    }
    return s;
}
