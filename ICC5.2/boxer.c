#include <stdio.h>

void draw_box(int width, int height)
{
    for(int h = 0; h < height; h++)
    {
        for(int w = 0; w < width; w++)
        {
            printf("#");
        }
        printf("\n");
    }
}