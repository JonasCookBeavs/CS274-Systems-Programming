#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *my_strdup(char *src)
{
    char *new_str = malloc(strlen(src) + 1);
    strcpy(new_str, src);

    return new_str;
}

void upper_string(char *s)
{
    for(int i = 0; i < (int)strlen(s); i++)
        s[i] = toupper(s[i]);
}

int main(void)
{
    char *orig = "And the flowers are still standing!";
    char *s = my_strdup(orig);

    printf("Original : \"%s\"\n", orig);
    printf("Duplicate: \"%s\"\n", s);

    upper_string(s);

    printf("Original : \"%s\"\n", orig);
    printf("Uppercase: \"%s\"\n", s);

    free(s);
}