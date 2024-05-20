#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void checkDucky(char *num);

int main()
{
    char *num;
    num = (char *)malloc(100 * sizeof(char));
    printf("Enter a number: ");
    scanf("%s", num);
    checkDucky(num);
    return 0;
}

void checkDucky(char *num)
{
    if (num[0] == '-')
        printf("%s is not a duck number!!", num);
    else
    {
        int i = 0, length = strlen(num), count = 0;
        while (i < length && num[i] == '0')
            i++;
        while (i < length && count == 0)
        {
            if (num[i] == '0')
                count = 1;
            i++;
        }
        if (count == 1)
            printf("%s is a duck number!!", num);
        else
            printf("%s is not a duck number!!", num);
    }
}
