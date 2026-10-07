#include <stdio.h>

void print_str(char a[])
{
    int i = 0;
    while (a[i] != 0)
    {
        putchar(a[i]);
        i++;
    }
}

int length_str(char a[])
{
    int i = 0;
    while (a[i] != 0) i++;
    return i;
}

void alpha_index(char a[])
{
    for (int i = 0; a[i] != 0; i++)
    {
        printf("%c: %d\n", a[i], a[i] - 'A' + 1);
    }
}

int main(void)
{
    char alph[] = "ABCD\n";
    printf("Characters in alph:\n");
    printf("%c\n", alph[0]);
    printf("%c\n", alph[1]);
    printf("%c\n", alph[2]);
    printf("Character values in alph:\n");
    printf("%d\n", alph[0]);
    printf("%d\n", alph[1]);
    printf("%d\n", alph[2]);
    printf("%d\n", alph[4]);
    printf("%d\n", alph[5]);

    print_str(alph);
    printf("Length of alph: %d\n", length_str(alph));
    alpha_index("WOMBAT");
}