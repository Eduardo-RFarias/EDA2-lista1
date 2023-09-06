#include <stdlib.h>

typedef struct celula
{
    char matricula[10];
    double mediaAtividades;
    double mediaProvas;
    struct celula *prox;
} celula;

void relatorioMediaAtividades(celula *le, celula *l1, celula *l2, double media)
{
    le = le->prox;

    while (le != NULL)
    {
        celula *aux = le->prox;

        if (le->mediaAtividades <= media)
        {
            l1->prox = le;
            l1 = l1->prox;
            l1->prox = NULL;
        }
        else
        {
            l2->prox = le;
            l2 = l2->prox;
            l2->prox = NULL;
        }

        le = aux;
    }
}

/*
// Test functions
#include <stdio.h>
#include <string.h>

void freeList(celula *ptr)
{
    celula *aux = ptr;

    while (ptr != NULL)
    {
        aux = ptr->prox;
        free(ptr);
        ptr = aux;
    }
}

int main()
{
    celula *head = (celula *)malloc(sizeof(celula));

    celula *le = (celula *)malloc(sizeof(celula));

    head->prox = le;

    strcpy(le->matricula, "140164006");
    le->mediaAtividades = 10.0;
    le->mediaProvas = 8.0;

    le->prox = (celula *)malloc(sizeof(celula));
    strcpy(le->prox->matricula, "160016169");
    le->prox->mediaAtividades = 4.0;
    le->prox->mediaProvas = 2.0;

    le->prox->prox = (celula *)malloc(sizeof(celula));
    strcpy(le->prox->prox->matricula, "170062465");
    le->prox->prox->mediaAtividades = 9.5;
    le->prox->prox->mediaProvas = 8.5;

    le->prox->prox->prox = (celula *)malloc(sizeof(celula));
    strcpy(le->prox->prox->prox->matricula, "190262661");
    le->prox->prox->prox->mediaAtividades = 5.0;
    le->prox->prox->prox->mediaProvas = 7.0;

    le->prox->prox->prox->prox = NULL;

    celula *l1 = (celula *)malloc(sizeof(celula));
    celula *l2 = (celula *)malloc(sizeof(celula));

    relatorioMediaAtividades(head, l1, l2, 6);

    printf("l1 -> ");
    for (celula *current = l1->prox; current != NULL; current = current->prox)
    {
        printf("{%s, %lf, %lf} -> ", current->matricula, current->mediaAtividades, current->mediaProvas);
    }
    printf("NULL\n");

    printf("\nl2 -> ");
    for (celula *current = l2->prox; current != NULL; current = current->prox)
    {
        printf("{%s, %lf, %lf} -> ", current->matricula, current->mediaAtividades, current->mediaProvas);
    }
    printf("NULL\n");

    freeList(l1);
    freeList(l2);
    free(head);

    return 0;
}
*/