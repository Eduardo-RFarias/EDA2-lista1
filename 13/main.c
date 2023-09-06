#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// There will be 140000 numbers in my hash table
// i want to 140000 to occupy only 70% of the table so that i can avoid collisions
// 140000 / 0.7 = 200000
// the closest prime number to 200000 is 200003
#define HASHSIZE 200003
#define PRIME 31
#define NULL_VALUE -1
#define MAX_COLLISIONS 20

// Auxiliary macros
#define HASH(x) (x % HASHSIZE)
#define HASH2(x) (PRIME + (x % (HASHSIZE - PRIME)))
#define JUMP(x, y) ((x + y) % HASHSIZE)

// HashTable implementation
void insert(int *table, int x)
{
    int hash;
    int offset;
    int collisions;

    // Loop until we find a free position or we reach the maximum number of collisions,
    // in which loop we jump to the next position using the offset which is a second hash function
    for (hash = HASH(x), offset = HASH2(x), collisions = 0;
         table[hash] != NULL_VALUE && collisions < MAX_COLLISIONS;
         hash = JUMP(hash, offset), collisions++)
    {
        // If the number is already in the table, we don't need to insert it again
        if (table[hash] == x)
        {
            return;
        }
    }

    // If we reached the maximum number of collisions, we don't insert the number
    if (collisions == MAX_COLLISIONS)
    {
        return;
    }

    table[hash] = x;
}

bool contains(int *table, int x)
{
    // Loop until we find the number or we reach the maximum number of collisions,
    // in which loop we jump to the next position using the offset which is a second hash function
    for (int hash = HASH(x), offset = HASH2(x), collisions = 0;
         collisions < MAX_COLLISIONS;
         hash = JUMP(hash, offset), collisions++)
    {
        if (table[hash] == x)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    // Create a hash table with HASHSIZE positions and initialize it with NULL_VALUE
    int table[HASHSIZE];
    memset(table, NULL_VALUE, sizeof(int) * HASHSIZE);

    int N;
    scanf("%d", &N);

    for (int x, i = 0; i < N; i++)
    {
        scanf("%d", &x);
        insert(table, x);
    }

    int P;
    while (scanf("%d", &P) != EOF)
    {
        if (contains(table, P))
        {
            printf("sim\n");
        }
        else
        {
            printf("nao\n");
        }
    }

    return 0;
}