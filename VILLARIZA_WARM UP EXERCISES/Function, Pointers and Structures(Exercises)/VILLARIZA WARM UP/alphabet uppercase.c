#include <stdio.h>
#include <stdlib.h>

void printabc(char *alphabet);

int main()
{
    char *alphabet = malloc(sizeof(char));
    *alphabet = 'A';
    printabc(alphabet);

    return 0;
}

void printabc(char *alphabet)
{
    while(*alphabet <= 'Z')
    {
        printf("%c\n", *alphabet);
        (*alphabet)++;
    }
}
