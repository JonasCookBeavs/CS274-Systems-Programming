#include <stdio.h>
#include <stdarg.h>
#include <string.h> // Don't use anything from here!

/**
 * Compute string length.
 */
int string_len(char *s)
{
    int len = 0;
    for (; *s != '\0'; s++, len++)
        ;
    return len; // Fix me
}

/**
 * Get a pointer to the first occurrence of `c` in `s`, or `NULL`.
 */
char *string_chr(char *s, char c)
{
    for (; *s != '\0'; s++)
    {
        if (*s == c)
        {
            return s;
        }
    }
    return NULL;
}

/**
 * Get a pointer to the last occurrence of `c` in `s`, or `NULL`.
 */
char *string_rchr(char *s, char c)
{
    char *temp = NULL;
    for (; *s != '\0'; s++)
    {
        if (*s == c)
        {
            temp = s;
        }
    }
    return temp; // Fix me
}

/**
 * Return the index of the first occurrence of `c` in `s`, or -1.
 */
int string_chr_index(char *s, char c)
{
    for(int i = 0;*s != '\0'; s++, i++)
    {
        if(*s == c)
        {
            return i;
        }
    }
    return -1;
}

/**
 * Copy string `src` into `dest`.
 */
char *string_cpy(char *dest, char *src)
{
    char *temp = dest;
    for(;*src != '\0'; src++, temp++)
    {
        *temp = *src;
    }
    return dest; // Fix me
}

/**
 * Concatenate `s` onto `dest`, returning `dest`.
 */
char *string_cat(char *dest, char *s)
{
    char *temp = dest;
    for(;*temp != '\0'; temp++) ;
    for(;*s != '\0'; s++, temp++)
    {
        *temp = *s;
    }
    temp++;
    *temp = '\0';

    return dest; // Fix me
}

/**
 * Compare two strings. Return a positive number if `s2` > `s1`, a
 * negative number if `s2 < `s1`, or 0.
 */
int string_cmp(char *s1, char *s2)
{
    for(;*s1 != '\0' && *s2 != '\0'; s1++, s2++)
    {
        if(*s1 > *s2) return 1;
        if(*s1 < *s2) return -1;
    }
    return *s1 - *s2;
}

//-----------------------------------------------------------------
// No need to modify below this line.
//-----------------------------------------------------------------

void output(int pass, char *fmt, ...)
{
    va_list va;
    char *red = "\033[91;1m";
    char *green = "\033[92;1m";
    char *reset = "\033[0m";

    if (pass)
        printf("%sPASS%s: ", green, reset);
    else
        printf("%sFAIL%s: ", red, reset);

    va_start(va, fmt);
    vprintf(fmt, va);
    va_end(va);

    putchar('\n');
}

void header(char *s)
{
    char *yellowblue = "\033[93;44;1m"; // bright yellow on blue, bold
    char *whiteblue = "\033[97;44;1m";  // bright white on blue, bold
    char *reset = "\033[0m";

    printf("\n%s>>> %sTesting %s %s\n\n", yellowblue, whiteblue, s, reset);
}

void test_string_len(void)
{
    char *str[] = {
        "Hi!",
        "Hi there!",
        "Hi\0there!",
        "a",
        "Nobody escapes the Spanish Inquisition!",
        "",
        NULL};

    header("string_len");

    for (char **p = str; *p != NULL; p++)
    {
        int expected = strlen(*p);
        int actual = string_len(*p);

        if (expected == actual)
            output(1, "\"%s\": length %d", *p, actual);
        else
            output(0, "\"%s\": got length %d (expected %d)", *p, actual, expected);
    }
}

void test_string_chr(int reverse)
{
    struct
    {
        char *str;
        char c;
    } *p, test[] = {
              {.str = "aaaabaaaaabaaa", .c = 'b'},
              {.str = "abcdef", .c = 'x'},
              {.str = "abc DEF ghi", .c = 'i'},
              {.str = "aaaa", .c = 'a'},
              {.str = "a", .c = 'a'},
              {.str = "", .c = 'a'},
              {.str = NULL, .c = 0},
          };

    header(reverse ? "string_rchr" : "string_chr");

    for (p = test; p->str != NULL; p++)
    {
        char *expected, *actual;

        if (reverse)
        {
            expected = strrchr(p->str, p->c);
            actual = string_rchr(p->str, p->c);
        }
        else
        {
            expected = strchr(p->str, p->c);
            actual = string_chr(p->str, p->c);
        }

        output(expected == actual, "\"%s\", '%c'", p->str, p->c);
    }
}

void test_string_chr_index(void)
{
    struct
    {
        char *str;
        int index;
    } *p, test[] = {
              {.str = "aaaabaaaaabaaa", .index = 4},
              {.str = "abcdef", .index = -1},
              {.str = "abc DEF ghi", .index = 10},
              {.str = "aaaa", .index = 0},
              {.str = "a", .index = 0},
              {.str = "", .index = -1},
              {.str = NULL, .index = 0},
          };

    header("string_chr_index");

    for (p = test; p->str != NULL; p++)
    {
        char *charloc = p->index >= 0 ? p->str + p->index : NULL;
        char c = charloc != NULL ? *charloc : 'X';
        int expected = p->index;
        int result = string_chr_index(p->str, c);

        if (expected == result)
            if (expected == -1)
                output(1, "\"%s\": '%c' not found", p->str, c);
            else
                output(1, "\"%s\": found '%c' at position %d", p->str, c, p->index);
        else
            output(0, "\"%s\", '%c': got %d (expected %d)", p->str, c, result, expected);
    }
}

void test_string_cpy(void)
{
    char *str[] = {
        "Hi!",
        "Hi there!",
        "Hi\0there!",
        "a",
        "We are the knights who say Ni!",
        "",
        NULL};

    char dest[4096];

    header("string_cpy");

    for (char **p = str; *p != NULL; p++)
    {
        memset(dest, 0, sizeof dest);
        char *actual = string_cpy(dest, *p);

        if (actual != dest)
            output(0, "\"%s\": did not return the destination pointer", *p);
        else if (strcmp(dest, *p) == 0)
            output(1, "\"%s\"", *p);
        else
            output(0, "\"%s\": copied as \"%s\"", *p, dest);
    }
}

void test_string_cat(void)
{
    char *str[][2] = {
        {"Hi!", " again!"},
        {"Hi there!", " This is another test!"},
        {"Hi\0there!", " there!"},
        {"We are the knights who say ", "Ni!"},
        {"a", "b"},
        {"", "Antelope"},
        {"Antelope", ""},
        {"", ""},
        {NULL, NULL}};

    char dest[4096], model[4096];

    header("string_cat");

    for (int i = 0; str[i][0] != NULL; i++)
    {
        memset(dest, 0, sizeof dest);
        strcpy(dest, str[i][0]);
        char *actual = string_cat(dest, str[i][1]);
        strcpy(model, str[i][0]);
        strcat(model, str[i][1]);

        if (actual != dest)
            output(0, "\"%s\"+\"%s\": did not return the destination pointer", str[i][0], str[i][1]);
        else if (strcmp(dest, model) == 0)
            output(1, "\"%s\"+\"%s\"", str[i][0], str[i][1]);
        else
            output(0, "\"%s\"+\"%s\": concatenated to \"%s\"", str[i][0], str[i][1], dest);
    }
}

void test_string_cmp(void)
{
    char *str[][2] = {
        {"Hi!", "Hi!"},
        {"Hi!", "Hi!!"},
        {"Hi!", "Hi"},
        {" Wombats rule", " Wombats rule"},
        {" Wombats rule", "Wombats rule"},
        {"123", "1234"},
        {"1234", "123"},
        {"!", " "},
        {" ", "!"},
        {"", "abc"},
        {"abc", ""},
        {"", "a"},
        {"a", ""},
        {"", ""},
        {NULL, NULL}};

    header("string_cmp");

    char *cmps[] = {"<", "==", ">"};

    for (int i = 0; str[i][0] != NULL; i++)
    {
        int actual = string_cmp(str[i][0], str[i][1]);
        int expected = strcmp(str[i][0], str[i][1]);

        // normalize to -1, 0, 1
        expected = expected < 0 ? -1 : expected > 0 ? 1
                                                    : 0;
        actual = actual < 0 ? -1 : actual > 0 ? 1
                                              : 0;

        if (actual == expected)
            output(1, "\"%s\" %s \"%s\"", str[i][0], cmps[actual + 1], str[i][1]);
        else
            output(0, "expected \"%s\" %s \"%s\", got \"%s\" %s \"%s\"",
                   str[i][0], cmps[expected + 1], str[i][1],
                   str[i][0], cmps[actual + 1], str[i][1]);
    }
}

int main(void)
{
    test_string_len();
    test_string_chr(0);
    test_string_chr(1); // string_rchr
    test_string_chr_index();
    test_string_cpy();
    test_string_cat();
    test_string_cmp();
}
