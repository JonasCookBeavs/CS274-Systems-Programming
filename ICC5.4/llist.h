#ifndef LLIST_H
#define LLIST_H

struct node {
    int value;
    struct node *next;
};

struct llist {
    struct node *head;
};

struct llist *llist_new(void);
void llist_free(struct llist *llist);
void llist_drain(struct llist *llist);
void llist_insert(struct llist *llist, int value);
void llist_print(struct llist *llist);

#endif