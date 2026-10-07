#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("usage: pi iterations\n");
        return 1;
    }
    int iter = atoi(argv[1]);
    int sign = 1;
    float sum = 0;
    for (int i = 0; i < iter; i++)
    {
        sum += (1.0 / (2 * i + 1) * sign);
        sign *= -1;
    }

    printf("%f\n", sum * 4);
}