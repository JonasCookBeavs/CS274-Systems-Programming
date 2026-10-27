#include "stack.h"
#include <stdlib.h>

void push(struct stack *top, float value)
{
    struct node *n = malloc(sizeof(struct node));
    n->value = value;
    n->next = top->node;
    top->node = n;
}

float pop(struct stack *top)
{
    struct node *n = top->node;
    float x = n->value;
    top->node = n->next;
    free(n);
    return x;
}

int can_pop(struct stack *top)
{
    struct node *n1 = top->node;
    if(n1)
    {
        struct node *n2 = n1->next;
        if(n2) return 1;
        else return 0;
    }

    return 0;
}