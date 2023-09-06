#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

void init(struct Stack *self)
{
    self->head = NULL;

    self->destroy = destroy;
    self->add = add;
    self->unstack = unstack;
}

void destroy(struct Stack *self)
{
    struct Node *aux;

    while (self->head != NULL)
    {
        aux = self->head;
        self->head = self->head->next;
        free(aux);
    }
}

void add(struct Stack *self, char *str)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->next = self->head;
    strcpy(newNode->str, str);

    self->head = newNode;
}

void unstack(struct Stack *self, char *destiny)
{
    if (self->head == NULL)
    {
        strcpy(destiny, "NULL");
        return;
    }

    struct Node *aux = self->head;
    self->head = self->head->next;

    strcpy(destiny, aux->str);
    free(aux);
}