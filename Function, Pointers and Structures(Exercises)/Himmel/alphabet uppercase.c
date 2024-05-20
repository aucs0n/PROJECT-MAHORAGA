#include <stdio.h>
#include <stdlib.h>

void printAlphabet(char *alphabet);

int main()
{
    char *alphabet = malloc(sizeof(char));
    *alphabet = 'A';
    printAlphabet(alphabet);

    return 0;
}

void printAlphabet(char *alphabet)
{
    while(*alphabet <= 'Z')
    {
        printf("%c\n", *alphabet);
        (*alphabet)++;
    }
}
