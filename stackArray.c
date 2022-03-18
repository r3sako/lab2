#include <stdio.h>
#include <stdlib.h>

struct stack {
    int maxSize;
    int top;
    char *items;
};
 
struct stack* newStack(int capacity) {
    struct stack *pt = (struct stack*)malloc(sizeof(struct stack));
 
    pt->maxSize = capacity;
    pt->top = -1;
    pt->items = (char*)malloc(sizeof(char) * capacity);
 
    return pt;
}

int size(struct stack *pt) {
    return pt->top + 1;
}
 
int isFull(struct stack *pt) {
    return pt->top == pt->maxSize - 1;
}

void resize(struct stack *pt) {
    pt->maxSize *= 2;
    pt->items = realloc(pt->items, pt->maxSize * sizeof(char));
}

void push(struct stack *pt, char *x) {
    if (isFull(pt)) resize(pt);
    pt->items[++pt->top] = *x;
    free(x);
}
 
char pop(struct stack *pt) {
    return pt->items[pt->top--];
}

void free_stack(struct stack *pt) {
    free(pt->items);
    free(pt);
}
