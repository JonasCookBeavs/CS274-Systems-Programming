#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/**
 * Collapse spaces in a string. Assumes the passed-in string is mutable.
 *
 * Returns a pointer to the collapsed string.
 */
char *collapse(char *s)
{
    char *src = s;
    char *dest = s;

    // Cut off leading whitespace
    while (*src != '\0' && !isalpha(*src))
    {
        src++;
    }
    dest = src;
    s = dest;

    // Collapse inner whitespace
    bool in_space = false;
    while (*src != '\0')
    {
        if (isspace(*src))            // skip all spaces
        {
            in_space = true;          // remember we saw whitespace, don't write yet
        }
        else
        {
            if (in_space)             // get here if *src isn't a space but we've been seeing spaces
            {
                *dest++ = ' ';        // emit one space before the next word
                in_space = false;     // no longer seeing spaces
            }
            *dest++ = *src;           // write the non-space character
        }
        src++;
    }


    *dest = '\0';
    return s;
}

// -----------------------------------
// Please don't modify below this line
// -----------------------------------

/**
 * Run an individual test.
 */
void test(char *input, char *expected)
{
    char sa[128];
    char *red = "\033[1;91m"; // ANSI escape sequences
    char *green = "\033[1;92m";
    char *reset = "\033[0m";

    // Can't mutate string literals, so we copy to an array
    strncpy(sa, input, sizeof sa);

    char *result = collapse(sa);

    if (strcmp(result, expected) != 0)
        printf("%sFAIL%s: \"%s\" -> \"%s\"\n", red, reset, input, result);
    else
        printf("%sPASS%s: \"%s\" -> \"%s\"\n", green, reset, input, result);
}

/**
 * Main--run a bunch of tests.
 */
int main(void)
{
    char *teststr[][2] = {
        {"hi   ", "hi"},
        {"    hi", "hi"},
        {"        hi   ", "hi"},
        {"hi   there", "hi there"},
        {"  hi   there", "hi there"},
        {"hi   there   ", "hi there"},
        {"  hi   there   ", "hi there"},
        {"  hi   there     again   ", "hi there again"},
        {" a b       c d      ef   g", "a b c d ef g"},
        {"a", "a"},
        {"     ", ""},
        {"", ""},
        {NULL, NULL}};

    for (char *(*p)[2] = teststr; (*p)[0] != NULL; p++)
        test((*p)[0], (*p)[1]);
}