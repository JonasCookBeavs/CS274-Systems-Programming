#include <stdio.h>

// Compiler might warn on a being unused, but ignore it.
void bad_increment(int a)
{
    a++;
}

void good_increment(int* a)
{
    (*a)++;
}

int main(void)
{
    int x = 12;

    bad_increment(x); // This doesn't work because we pass by value
    printf("%d\n", x);  // 12, boo

    good_increment(&x); // This does work because we pass by reference
    printf("%d\n", x);  // 13, yay!

}