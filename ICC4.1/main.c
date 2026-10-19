#include <stdio.h>

/*
1: 3.14 is either a long or a double
2: 12 is an int
3: All pointers are the same size because they are all ints
*/

int main(void)
{
    char c = 'a';
    short s = 1;
    int i = 2;
    long l = 3;

    printf("%zu, %zu, %zu, %zu\n", sizeof c, sizeof s, sizeof i, sizeof l);
    printf("%zu\n", sizeof(i + l));
    printf("%zu, %zu, %zu\n", sizeof 12, sizeof 20, sizeof 3.14);
    printf("%zu, %zu, %zu, %zu, %zu\n", sizeof(char), sizeof(int), sizeof(long), sizeof(float), sizeof(double));

    int *p = &i;
    long *q = &l;

    printf("%zu, %zu\n", sizeof p, sizeof q);
    printf("%zu, %zu, %zu, %zu\n", sizeof(char*), sizeof(int*), sizeof(long*), sizeof(double*));

}