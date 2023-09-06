#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

void mescla_listas(celula *l1, celula *l2, celula *l3)
{
    celula *currentL3 = l3;

    // Loop while both lists have nodes remaining
    for (celula *currentL1 = l1->prox, *currentL2 = l2->prox;
         currentL1 != NULL || currentL2 != NULL;
         currentL3 = currentL3->prox)
    {
        // If l1 doesn't have a node remaining, then l2 must be added
        if (currentL1 == NULL)
        {
            currentL3->prox = currentL2;
            currentL2 = currentL2->prox;
        }
        // If l2 doesn't have a node remaining, then l1 must be added
        else if (currentL2 == NULL)
        {
            currentL3->prox = currentL1;
            currentL1 = currentL1->prox;
        }
        // If both lists have nodes remaining, then add the smallest one
        else if (currentL1->dado < currentL2->dado)
        {
            currentL3->prox = currentL1;
            currentL1 = currentL1->prox;
        }
        else
        {
            currentL3->prox = currentL2;
            currentL2 = currentL2->prox;
        }
    }

    // Terminate the list
    currentL3->prox = NULL;
}

/*
// Test functions

#include <stdio.h>

void add(celula *head, int value)
{
    celula *new = malloc(sizeof(celula));

    new->dado = value;
    new->prox = NULL;

    celula *current = head;
    while (current->prox != NULL)
    {
        current = current->prox;
    }

    current->prox = new;
}

void free_list(celula *head)
{
    celula *current = head->prox;
    while (current != NULL)
    {
        celula *next = current->prox;
        free(current);
        current = next;
    }
    free(head);
}

int main()
{
    celula *l1 = malloc(sizeof(celula));
    celula *l2 = malloc(sizeof(celula));
    celula *l3 = malloc(sizeof(celula));

    add(l1, 1);
    add(l1, 7);
    add(l1, 9);
    add(l1, 10);

    add(l2, 2);
    add(l2, 3);
    add(l2, 8);

    mescla_listas(l1, l2, l3);

    for (celula *current = l3->prox; current != NULL; current = current->prox)
    {
        printf("%d ", current->dado);
    }
    printf("\n");

    free_list(l3);
    free(l1);
    free(l2);

    return 0;
}
*/