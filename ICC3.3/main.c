#include <stdio.h>

void printstr(char *s)
{
    for(int i = 0; s[i] != '\0'; i++)
    {
        putchar(s[i]);
    }
    
    while(*s != '\0')
    {
        putchar(*s);
        s++;
    }

    
}

int main(void)
{
    char *a = "Hello, world!\n";
    char b[128] = "The Magic Words are Squeamish Ossifrage\n";

    printstr(a);
    printstr(b);
    printstr("String literal!\n");
}