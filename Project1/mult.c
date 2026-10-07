#include <stdio.h>

int main(void)
{
    for (int i = 1; i < 13; i++)
    {
        for (int j = 1; j < 13; j++)
        {
            if (j == 12)
            {
                printf("%3d \n", i * j);
            }
            else
            {
                printf("%3d ", i * j);
            }
        }
    }
}