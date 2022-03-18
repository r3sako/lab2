#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {
    struct stack *pt = newStack(5);
    char c;
    printf("Input: ");
    do {
        scanf("%c", &c);
        if (c == '0' || c == '1') {
            char *c_alloc = malloc(sizeof(char));
            *c_alloc = c;
            push(pt, c_alloc);
        } else if (c == '!') {
            if (size(pt) < 1) {
                printf("Invalid input\n");
                free_stack(pt);
                return 0;
            }
            char c1 = pop(pt);
            int i1 = c1 - '0';
            i1 = (i1 + 1) % 2;
            i1 += '0';
            char *c_alloc = malloc(sizeof(char));
            *c_alloc = i1;
            push(pt, c_alloc);
        } else if (c == '|' || c == '&') {
            scanf("%c", &c);
            if ((c != '|' && c != '&') || size(pt) < 2) {
                printf("Invalid input\n");
                free_stack(pt);
                return 0;
            }

            char c1 = pop(pt);
            char c2 = pop(pt);
            int i1 = c1 - '0';
            int i2 = c2 - '0';
            char *c_alloc = malloc(sizeof(char));
            if (c == '|') {
                *c_alloc = (i1 || i2) + '0';
            } else {
                *c_alloc = (i1 && i2) + '0';
            }
            push(pt, c_alloc);
        } else if (c != '\n'){
            printf("Invalid input\n");
            free_stack(pt);
            return 0;
        }
    } while (c != '\n');

    printf("Answer: %c\n", pop(pt));
    free_stack(pt);
    return 0;
}