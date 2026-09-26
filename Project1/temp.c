#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("usage: temp value\n");
        return 1;
    }

    float temp = atof(argv[1]);
    float c = (temp - 32) * 5 / 9;
    float f = temp * 9 / 5 + 32;

    printf("%f F is %f C\n", temp, c);
    printf("%f C is %f F\n", temp, f);
}