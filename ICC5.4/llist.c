#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

/**
 * Create a new linked list with a NULL head pointer.
 */
struct llist *llist_new(void)
{
    struct llist *new = malloc(sizeof(struct llist));
    new->head = NULL;
    return new;
}

/**
 * Free all the nodes in the linked list and free the linked list
 * itself.
 */
void llist_free(struct llist *llist)
{
    llist_drain(llist);
    free(llist);
}

/**
 * Remove all the items from a linked list.
 */
void llist_drain(struct llist *llist)
{
    struct node *n = llist->head;
    struct node *p;
    while(n != NULL)
    {
        p = n;
        n = n->next;
        free(p);
    }
    llist->head = NULL;
}

/**
 * Insert a new value in the linked list.
 */
void llist_insert(struct llist *llist, int value)
{
    struct node *n = malloc(sizeof(struct node));
    n->value = value;
    n->next = llist->head;
    llist->head = n;
}

/**
 * Print a linked list.
 */
void llist_print(struct llist *llist)
{
    if (llist->head == NULL)
        printf("[empty]");
    else
        for (struct node *n = llist->head; n != NULL; n = n->next)
            printf("(%d)%s", n->value, n->next == NULL? "": " -> ");

    putchar('\n');
}