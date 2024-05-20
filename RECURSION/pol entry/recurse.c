/*============================================================================
 FILE        : recurse.c
 AUTHOR      : Paul Andrew F. Parras
 DESCRIPTION : contains the functions that has the recursive functions for the program
 REVISION HISTORY
 Date: 			By: 		Description:
 ============================================================================*/

#include"header.h"

/*============================================================================
 FUNCTION    : int factRecurse
 DESCRIPTION : recursive function to solve for factorial
 ARGUMENTS   : int n = number of integers
 RETURNS     : 1 or n *factRecurse(n-1)
 ============================================================================*/
int factRecurse(int n)
{
    if(n == 1)
    {
        return 1;
    }
    else
    {
        return n*factRecurse(n-1);
    }

}

/*============================================================================
 FUNCTION    : int fibRecurse
 DESCRIPTION : recursive function to solve for fibonacci sequence
 ARGUMENTS   : int n = number of integers
 RETURNS     : int f = the fibonacci number
 ============================================================================*/
int fibRecurse(int n)
{
    int f;
    if(n <= 1)
    {
        f = n;
    }
    else
    {
        f = fibRecurse(n - 1) + fibRecurse(n-2);
    }

    return f;
}

/*============================================================================
 FUNCTION    : int sumRecurse
 DESCRIPTION : recursive function to solve sum
 ARGUMENTS   : int n = number of integers
 RETURNS     : int s = sum
 ============================================================================*/
int sumRecurse(int n)
{
    int s;
    if(n == 0)
    {
        s = 0;
    }
    else
    {
        s = n +(sumRecurse(n-1));
    }
    return s;
}
