#include <stdio.h>
#include <stdlib.h>

struct node {
    char *items;
    struct node *next;
};

struct stack {
    struct node *head;
};

struct stack* newStack(int capacity) {
    struct stack *pt = (struct stack*)malloc(sizeof(struct stack));
    pt->head = NULL;
    return pt;
}
int size(struct stack *pt) {
    int size = 0;
    struct node *tmp = pt->head;
    while (tmp) {
        tmp = tmp->next;
        size += 1;
    }
    return size;
}

void push(struct stack *pt, char *x) {
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->next = pt->head;
    n->items = x;
    pt->head = n;
}

char pop(struct stack *pt) {
    char c = *((pt->head)->items);
    free((pt->head)->items);
    struct node *tmp = pt->head;
    pt->head = (pt->head)->next;
    free(tmp);
    return c;
}

void free_stack(struct stack *pt) {
    while (pt->head) {
        free((pt->head)->items);
        struct node *tmp = pt->head;
        pt->head = (pt->head)->next;
        free(tmp);
    }
    free(pt->head);
    free(pt);
}