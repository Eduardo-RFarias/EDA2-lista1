#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 110

struct Node
{
    char str[MAX];
    struct Node *next;
};

struct Node *stack(struct Node *head, const char *str)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->next = head;
    strcpy(newNode->str, str);

    return newNode;
}

struct Node *unstackAndPrint(struct Node *head)
{
    if (head == NULL)
    {
        printf("NULL\n");
        return NULL;
    }

    struct Node *aux = head;
    head = head->next;

    printf("%s\n", aux->str);

    free(aux);

    return head;
}

void freeStack(struct Node *head)
{
    struct Node *aux;

    while (head != NULL)
    {
        aux = head;
        head = head->next;
        free(aux);
    }
}

int main()
{
    struct Node *stackHead = NULL;

    // str size must be 100 + 2 + 8 because of the '\0' and '\n' characters
    // and the keywords "desfazer" and "inserir " (with the space) that have
    // 8 characters and will precede the string.
    char str[MAX];

    while (fgets(str, MAX, stdin) != NULL)
    {
        // remove the '\n' character
        str[strlen(str) - 1] = '\0';

        // if the string starts with "desfazer"
        if (strncmp(str, "desfazer", 8) == 0)
        {
            stackHead = unstackAndPrint(stackHead);
        }
        else
        {
            // remove the "inserir " keyword
            char *p = str + 8;
            stackHead = stack(stackHead, p);
        }
    }

    freeStack(stackHead);

    return 0;
}
