#include <stdio.h>
#include <windows.h>

void Triangle(int num);
int main()
{
    int num;
    printf("Enter num: ");
    scanf("%d", &num);

    Triangle(num);

    return 0;
}

void Triangle(int num)
{
    int count = 1, i = 1;
    for(; i <= num; count++)
    {
        for(int j = 1; j < count; j++, i++)
        {
            printf("%d ", i);
        }
        printf("\n");
    }
}
