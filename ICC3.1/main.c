#include <stdio.h>

int main(void)
{
    int value1 = 37;
    int value2 = 3490;

    int *p;
    int *q;

    p = &value1;
    printf("Value 1: %d\n", value1); // 37
    printf("Value 1's address is %p\n", (void*)&value1); // p
    printf("P: %p\n", p); // p
    printf("Thing that P points to: %d\n", *p); // 37

    q = &value2;
    printf("Value 2: %d\n", value2); // 3490
    printf("Value 2's address is %p\n", (void*)&value2); // q
    printf("Q: %p\n", q); // q
    printf("Thing that Q points to: %d\n", *q); // 3490

    *p ^= *q;
    *q ^= *p;
    *p ^= *q;

    printf("Value 1: %d, Value 2: %d\n", value1, value2); // 3490, 37
    p = q;
    printf("Thing that P points to: %d, Thing that Q points to: %d\n", *p, *q); // 37, 37
}