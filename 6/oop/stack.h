#ifndef STACK_H
#define STACK_H

#define MAX_STACK_STR 110

struct Node
{
    char str[MAX_STACK_STR];
    struct Node *next;
};

struct Stack
{
    // attributes
    struct Node *head;

    // constructor
    void (*init)(struct Stack *self);

    // destructor
    void (*destroy)(struct Stack *self);

    // void add(char *str)
    void (*add)(struct Stack *self, char *str);

    // void unstack(char *destiny)
    void (*unstack)(struct Stack *self, char *destiny);
};

void init(struct Stack *self);
void destroy(struct Stack *self);
void add(struct Stack *self, char *str);
void unstack(struct Stack *self, char *destiny);

#endif