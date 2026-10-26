#include <stdio.h>
#include "boxer.h" 
#include "mather.h"
void main(void)
{
    printf("2 + 2 = %d\n", add(2, 2));
    printf("4 + 2 = %d\n", sub(4, 2));
    draw_box(4, 4);
}