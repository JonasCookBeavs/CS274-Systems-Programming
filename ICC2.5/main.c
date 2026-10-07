#include <stdio.h>
#include <ctype.h>


int main(int argc, char *argv[])
{
    if(argc < 2) {
        printf("usage: main string\n");
        return 1;
    }

    int lower = 0;
    int upper = 0;
    int alph = 0;
    int num = 0;
    int punc = 0;
    
    for(int i = 0; argv[1][i] != 0; i++)
    {
        if(islower(argv[1][i])) lower++;
        if(isupper(argv[1][i])) upper++;
        if(isalpha(argv[1][i])) alph++;
        if(isdigit(argv[1][i])) num++;
        if(ispunct(argv[1][i])) punc++;
    }
    
    printf("Upper: %d\n", upper);
    printf("Lower: %d\n", lower);
    printf("Alphabetic: %d\n", alph);
    printf("Numeric: %d\n", num);
    printf("Punctation: %d\n", punc);
}