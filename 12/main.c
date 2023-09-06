#include <stdio.h>
#include <stdlib.h>

#define INPUT_MAX 100000

struct Info
{
    int count;
    char value;
    int indexOf;
};

// compare function for qsort()
// sort by the count of each character in descending order
// if two characters have the same count, sort them by the index of the first occurrence in ascending order.
int compare(const void *a, const void *b)
{
    struct Info *infoA = (struct Info *)a;
    struct Info *infoB = (struct Info *)b;

    if (infoA->count == infoB->count)
    {
        return infoA->indexOf - infoB->indexOf;
    }
    else
    {
        return infoB->count - infoA->count;
    }
}

int main()
{
    struct Info *arr = (struct Info *)calloc(INPUT_MAX, sizeof(struct Info));
    int arrSize = 0;

    int count;
    char readChar;
    char currentChar = '\n';

    // read input character by character until a newline, EOF is encountered
    // or until the maximum number of characters is reached.
    for (count = 0, readChar = getchar();
         count < INPUT_MAX && readChar != '\n' && readChar != EOF;
         count++, readChar = getchar())
    {
        // if the read character is different from the current character, add it to the array
        // and set the current character to the read character.
        //
        // in the first iteration, the current character will always be different from the read character
        if (readChar != currentChar)
        {
            arr[arrSize].count = 1;
            arr[arrSize].value = readChar;
            arr[arrSize].indexOf = count;
            arrSize++;
            currentChar = readChar;
        }
        // else, increment the count of the current character (the last character in the array)
        else
        {
            arr[arrSize - 1].count++;
        }
    }

    qsort(arr, arrSize, sizeof(struct Info), compare);

    for (int i = 0; i < arrSize; i++)
    {
        struct Info info = arr[i];
        printf("%d %c %d\n", info.count, info.value, info.indexOf);
    }

    free(arr);
    return 0;
}