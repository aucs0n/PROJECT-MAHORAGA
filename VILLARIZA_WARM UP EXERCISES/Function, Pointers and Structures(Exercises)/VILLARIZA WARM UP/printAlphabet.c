#include<stdio.h>
#include<windows.h>

int main()
{
    system("cls");
    char *c = (char*) malloc(sizeof(char));
    for(*c = 'A'; *c <= 'Z'; (*c)++)
    {
        printf("%c ", *c);
    }
    free(c);
    
    return 0;
}