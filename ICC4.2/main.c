#include <stdio.h>

/*
1: sizeof a is the size of the entire array that the compiler knows, but sizeof p would just be the size of a pointer, that
    pointer doesn't know how big the array its pointing to is
2: In all cases, x is just a pointer to a space in memory, and since its always a pointer 
    it will always return the same size
*/

void f1(int *x)
{
    printf("f1: sizeof x = %zu\n", sizeof x);
}

void f2(int x[])
{
    printf("f2: sizeof x = %zu\n", sizeof x);
}

void f3(int x[5])
{
    printf("f3: sizeof x = %zu\n", sizeof x);
}

int main(void)
{
    char a[12];
    int b[4];

    printf("%zu, %zu\n", sizeof(char), sizeof(int));
    printf("%zu, %zu\n", sizeof a, sizeof b);
    printf("%d\n", sizeof b / sizeof b[0]);
    printf("%d\n", sizeof b / sizeof(int));

    char *p = &a[0];
    int  *q = &b[0];
    printf("%zu, %zu\n", sizeof p, sizeof q);

    f1(b);
    f2(b);
    f3(b);
}