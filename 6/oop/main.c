#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int main()
{
    struct Stack stack;
    // Add constructor to the struct
    stack.init = init;
    // Call the constructor
    stack.init(&stack);

    // str size must be 100 + 2 + 8 because of the '\0' and '\n' characters
    // and the keywords "desfazer" and "inserir " (with the space) that have
    // 8 characters and will precede the string.
    char str[MAX_STACK_STR];

    while (fgets(str, MAX_STACK_STR, stdin) != NULL)
    {
        // remove the '\n' character
        str[strlen(str) - 1] = '\0';

        // if the string starts with "desfazer"
        if (strncmp(str, "desfazer", 8) == 0)
        {
            // unstack the string and print it
            char unstackedStr[MAX_STACK_STR];
            stack.unstack(&stack, unstackedStr);
            printf("%s\n", unstackedStr);
        }
        else
        {
            // remove the "inserir " keyword and stack the string
            stack.add(&stack, str + 8);
        }
    }

    stack.destroy(&stack);

    return 0;
}
