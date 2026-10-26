// #include <stdio.h>


// PART 1
#if 0
int add(int x, int y)
{
    return x + y;
}

int main(void)
{
    printf("1 + 2 = %d\n", add(1, 2));
}
#endif


// PART 2
#if 0
int add(int, int);

int main(void)
{
    printf("1 + 2 = %d\n", add(1, 2));
}

int add(int x, int y)
{
    return x + y;
}
#endif

// PART 3
#if 0
int main(void)
{
    puts("Hello, world");
}
// This gives a implicit declaration warning as well as "do you want to include <stdio.h>?"
// I assume that <stdio.h> has a definition of 'puts' in it somewhere
#endif