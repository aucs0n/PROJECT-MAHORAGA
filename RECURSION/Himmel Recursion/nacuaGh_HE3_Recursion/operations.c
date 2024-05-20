/*
================================================================================
FILE        : operations.c
AUTHOR      : himmel
DESCRIPTION : Iterative and Recursive functions for operations.
COPYRIGHT   : February 19 2024
REVISION HISTORY
Date: 			By: 		Description:
================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

/*
================================================================================
FUNCTION    : i_factorial
DESCRIPTION : Iterative function that displays the factorial of the number
ARGUMENTS   : int n - the number
RETURNS     : void
================================================================================
*/
void i_factorial(long n)
{
	long i, fac=1;
	for(i=1;i<=n;i++)
    {
		fac*=i;
		printf("   %li", fac);
	}
	if(n==0){
		printf("   1");
	}
}

/*
================================================================================
FUNCTION    : r_factorial
DESCRIPTION : Recursive function that displays the factorial of the number
ARGUMENTS   : int n - the number
RETURNS     : long int - returns the current value of the factorial
================================================================================
*/
long r_factorial(long n)
{
	if(n==0||n==1)
    {
		n=1;
	}
	else
    {
		n = (n*r_factorial(n-1));
	}
	printf("   %li", n);
	return n;
}

/*
================================================================================
FUNCTION    : i_fibonacci
DESCRIPTION : Iterative function that displays fibonacci sequence until nth digit
ARGUMENTS   : int n - the number
RETURNS     : void
================================================================================
*/
void i_fibonacci(long n)
    {
	int i, f=1, s=0, temp;
	if(n==0)
    {
		printf("   NA");
	}
	for(i=0;i<n;i++)
	{
		printf("   %d", f);
		temp = f;
		f=s+f;
		s=temp;
	}
}

/*
================================================================================
FUNCTION    : r_fibonacci
DESCRIPTION : Recursive function that returns nth digit of the fibonacci sequence
ARGUMENTS   : int n - the number
RETURNS     : long int - returns the nth value of the fibonnacci series
================================================================================
*/
long r_fibonacci(long n)
{
	long f;
	if(n==0)
    {
		return 0;
	}
	if(n==1)
	{
		return 1;
	}
	else
    {
		return r_fibonacci(n-1)+r_fibonacci(n-2);
	}
}

/*
================================================================================
FUNCTION    : i_sum
DESCRIPTION : Iterative function that displays the sum series until nth digit
ARGUMENTS   : int n - the number
RETURNS     : void
================================================================================
*/
void i_sum(long n)
    {
	long i, fac=0;
	for(i=1;i<=n;i++)
    {
		fac+=i;
		printf("   %d", fac);
	}
	if(n==0)
	{
		printf("   NA");
	}
}

/*
================================================================================
FUNCTION    : r_sum
DESCRIPTION : Recursive function that displays the sum series until nth digit
ARGUMENTS   : int n - the number
RETURNS     : long int - returns the nth value of the sum series
================================================================================
*/
long r_sum(long n)
    {
	if(n==0)
    {
		printf("   NA");
	}
	else if(n==1)
    {
		n=1;
		printf("   %d", n);
	}
	else
    {
		n = (n+r_sum(n-1));
		printf("   %d", n);
	}
	return n;
}
