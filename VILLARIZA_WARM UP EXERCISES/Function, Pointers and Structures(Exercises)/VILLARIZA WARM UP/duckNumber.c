#include <stdio.h>
#include <windows.h>


void checkDuck(char *num);

int main()
{
    char *num = (char*) malloc(50*sizeof(char));
    system("cls");
    printf("Enter a number: ");
    scanf("%s", num);
    checkDuck(num);
    free(num);
    return 0;
}

void checkDuck(char *num)
{
    int len = strlen(num), count = 0;
    if(*num == '0')
    {
        printf("This number is not a duck number");
    }
    else
    {
        for(int i = 1; i < len; i++)
        {
            if(*(num+i) == '0')
            {
                count++;
            }
            else{continue;}
        }
        if(count >= 1)
        {
            printf("This number is a duck number");
        }
        else
        {
            printf("This number is not a duck number");
        }
    }
}