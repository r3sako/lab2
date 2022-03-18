struct stack* newStack(int capacity);
int size(struct stack *pt);
int isFull(struct stack *pt);
void push(struct stack *pt, char *x);
char pop(struct stack *pt);
void free_stack(struct stack *pt);
