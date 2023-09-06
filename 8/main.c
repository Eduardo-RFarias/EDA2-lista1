#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *next;
};

// Linked Stack implementation
struct LinkedStackContainer
{
    struct Node *head;
};

void stack(struct LinkedStackContainer *container, int value)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));

    new->value = value;
    new->next = container->head;

    container->head = new;
}

int unstack(struct LinkedStackContainer *container)
{
    int value = container->head->value;

    struct Node *next = container->head->next;
    free(container->head);
    container->head = next;

    return value;
}

void freeStack(struct LinkedStackContainer *container)
{
    while (container->head != NULL)
    {
        struct Node *next = container->head->next;
        free(container->head);
        container->head = next;
    }
}

int stackIsEmpty(struct LinkedStackContainer *container)
{
    return container->head == NULL;
}
// End of stack implementation

// Linked queue implementation
struct LinkedQueueContainer
{
    struct Node *head;
    struct Node *tail;
};

void enqueue(struct LinkedQueueContainer *container, int value)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));

    new->value = value;
    new->next = NULL;

    // if queue is empty head and tail will be the same
    if (container->head == NULL)
    {
        container->head = new;
    }
    // else just add the new node to the end of the queue
    else
    {
        container->tail->next = new;
    }

    // in both cases the tail will be the new node
    container->tail = new;
}

int dequeue(struct LinkedQueueContainer *container)
{
    // if queue is empty return -1
    if (container->head == NULL)
    {
        return -1;
    }

    int value = container->head->value;

    struct Node *next = container->head->next;
    free(container->head);

    // if queue has only one element, head and tail will be NULL
    if (next == NULL)
    {
        container->tail = NULL;
    }

    container->head = next;

    return value;
}

void freeQueue(struct LinkedQueueContainer *container)
{
    while (container->head != NULL)
    {
        struct Node *next = container->head->next;
        free(container->head);
        container->head = next;
    }
}

int queueIsEmpty(struct LinkedQueueContainer *container)
{
    return container->head == NULL;
}
// End of queue implementation

int main()
{
    struct LinkedStackContainer linkedStack;
    linkedStack.head = NULL;

    struct LinkedQueueContainer linkedQueue;
    linkedQueue.head = NULL;
    linkedQueue.tail = NULL;

    // read the first value before the loop starts
    int n;
    scanf("%d", &n);

    // enqueue all values until 0 is read
    while (n != 0)
    {
        enqueue(&linkedQueue, n);
        scanf("%d", &n);
    }

    // read the limit
    int limit;
    scanf("%d", &limit);

    int sum = 0;

    // dequeue all values and sum them
    while (!queueIsEmpty(&linkedQueue))
    {
        int value = dequeue(&linkedQueue);
        sum += value;

        // if sum is greater than the limit, stack the value and reset the sum
        if (sum > limit)
        {
            stack(&linkedStack, value);
            sum = 0;
        }
    }

    // unstack all values and print them
    while (!stackIsEmpty(&linkedStack))
    {
        int value = unstack(&linkedStack);
        printf("%d\n", value);
    }

    freeStack(&linkedStack);
    freeQueue(&linkedQueue);

    return 0;
}
