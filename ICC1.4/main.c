#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
    if(argc < 2) return 1;

    int v0 = atoi(argv[1]);
    int v1 = atoi(argv[2]);

    if(v0 > v1){
        printf("%d is greater than %d\n", v0, v1);
    }
    else if (v1 > v0){
        printf("%d is less than %d\n", v0, v1);
    }
    else printf("%d is equal to %d\n", v0, v1);
}