#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    // Read and discard the newline character after N
    getchar();

    for (int i = 0; i < N; i++)
    {
        int soma = 0;

        // Read a character at a time until a newline or EOF is found
        for (char c = getchar(); c != '\n' && c != EOF; c = getchar())
        {
            // If the character is a digit, add it to the sum
            if (c >= '0' && c <= '9')
            {
                soma += c - '0';
            }
        }

        printf("%d\n", soma);
    }

    return 0;
}