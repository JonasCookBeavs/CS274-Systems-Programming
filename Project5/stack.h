#ifndef STACK_H
#define STACK_H

struct node {
    float value;
    struct node *next;
};

struct stack {
    struct node *node;
};

void push(struct stack *top, float value);
float pop(struct stack *top);
int can_pop(struct stack *top);

#endif