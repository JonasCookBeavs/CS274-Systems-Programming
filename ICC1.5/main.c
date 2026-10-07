#include <stdio.h>

void main(void)
{
    for(int i = 0; i < 10; i++)
    {
        printf("%d ", i);
    }
    printf("\n");

    for(int i = 0; i < 9; i+=2)
    {
        printf("%d ", i);
    }

    printf("\n");
    for(int i = 9; i > -1; i--)
    {
        printf("%d ", i);
    }

    printf("\n");
    for(int i = 20; i > -1; i-=4)
    {
        printf("%d ", i);
    }
    printf("\n");
}