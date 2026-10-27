#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void do_operator(float x, float y, char operator, struct stack *top)
{

    if (operator == '+')
        push(top, x + y);
    if (operator == '-')
        push(top, x - y);
    if (operator == '*')
        push(top, x * y);
    if (operator == '/')
        push(top, y / x);
}

int op_check(char *str)
{   // strlen check to make sure its not a negative number
    if ((*str == '+' || *str == '-' || *str == '*' || *str == '/') && strlen(str) == 1) 
        return 1;
    return 0;
}

int char_check(char *str)
{
    char *badchar;

    strtof(str, &badchar);

    if (*badchar != '\0')
        return 0;
    else
        return 1;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("usage: rpncalc number/operator ...\n");
        return 1;
    }

    struct stack *stack = malloc(sizeof(struct stack));
    stack->node = NULL;

    for (int i = 1; i < argc; i++)
    {
        if (op_check(argv[i]) == 0) // if not operator
        {
            if (char_check(argv[i]) == 0) // if not number
            {
                printf("rpncalc: error: %s\n", argv[i]); // error, must be invalid input
                return 1;
            }
            else // if number
            {
                push(stack, atof(argv[i])); // push to stack
            }
        }
        else // if operator
        {
            if (can_pop(stack)) // if there are two numbers on the stack
            {
                float val1 = pop(stack);
                float val2 = pop(stack);
                if (*argv[i] == '/' && val1 == 0) // if dividing by 0
                {
                    printf("rpncalc: division by zero\n"); // error, you can't do that
                    return 1;
                }
                do_operator(val1, val2, *argv[i], stack); // perform operation
            }
            else // if one or no numbers on stack
            {
                printf("rpncalc: missing operand for '%s'\n", argv[i]); // error, not enough numbers to do operation
                return 1;
            }
        }
    }

    printf("%f\n", stack->node->value);
    if (stack->node->next != NULL) // there is another item(s) on stack
    {
        printf("rpncalc: warning: extra items remaining on stack\n");
    }
    return 1;
}