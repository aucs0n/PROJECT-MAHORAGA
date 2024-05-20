/*============================================================================
 FILE        : main.c
 AUTHOR      : Paul Andrew F. Parras
 DESCRIPTION : contains the main function of the program
 REVISION HISTORY
 Date: 			By: 		Description:
 ============================================================================*/

#include"header.h"

/*============================================================================
 FUNCTION    : main
 DESCRIPTION : the main function of the program
 ARGUMENTS   : none
 RETURNS     : 0 - exit code
 ============================================================================*/
int main()
{
    int n;
    printf("Enter value of n: ");
    scanf("%d", &n);

    printf("Factorial series using non-recursive function.\n");
    for(int i = 1; i <= n; i++)
    {
        int f = factIterate(i);
        printf("%d ", f);

    }
    printf("\nFactorial series using recursive function.\n");
    for(int i = 1; i <= n; i++)
    {
        int f = factIterate(i);
        printf("%d ", f);

    }
    printf("\nFibonacci series using non-recursive function.\n");
    fibIterate(n);
    printf("\nFibonacci series using recursive function.\n");
    for(int i = 1; i <= n; i++)
    {
        printf("%d ", fibRecurse(i));

    }
    printf("\nSum series using non-recursive function.\n");
    for(int i = 2; i <= n+1; i++)
    {
        printf("%d ", sumIterate(i));

    }
    printf("\nSum series using recursive function.\n");
    for(int i = 1; i <= n; i++)
    {
        int s = sumRecurse(i);
        printf("%d ", s);

    }


    return 0;
}
