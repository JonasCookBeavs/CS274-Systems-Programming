#include <stdio.h>
#include <stdlib.h>

void main(void) {
    int x = 5;
    float f;

    f = 3+4/(2*3*4)-4/(4*5*6)+4/(6*7*8)-4/(8*9*10)+4/(10*11*12);

    printf("%d wow its an int\n", x);
    printf("%f wow its a float\n", f);

    float g = 3+4.0/(2*3*4)-4.0/(4*5*6)+4.0/(6*7*8)-4.0/(8*9*10)+4.0/(10*11*12);

    printf("%f wow its another float\n", g);
    int g2 = g;
    printf("%d wow its another int\n", g2);
    printf("%f wow its another another float\n", g);
    printf("22 / 7 = %f\n", 22.0/7.0);

    char *s = "This is a test";
    printf("The string is: %s\n", s);

}