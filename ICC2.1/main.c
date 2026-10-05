#include <stdio.h>

#define INT_COUNT 15

int a[INT_COUNT] = {0};

int main(void)
{
    for (int i = 0; i < INT_COUNT; i++)
    {
        a[INT_COUNT - i - 1] = i * 10;
    }

    for (int i = 1; i < INT_COUNT + 1; i++)
    {
        printf("a[%d] = %d\n", INT_COUNT-i, a[INT_COUNT-i]);
    }

    return 0;
}