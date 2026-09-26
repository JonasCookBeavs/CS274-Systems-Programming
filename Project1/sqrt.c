#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("usage: sqrt number [iterations]\n");
        return 1;
    }

    int iter = 20;
    float val = atof(argv[1]);
    if (argc > 2)
    {
        iter = atoi(argv[2]);
    }

    float x = val / 2;
    for (int i = 0; i < iter; i++)
    {
        x = 0.5 * (x + val / x);
    }

    printf("%f\n", x);
}