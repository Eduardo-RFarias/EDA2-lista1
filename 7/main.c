#include <stdio.h>

int main()
{
    int N, count = 0;

    // we need to read the first N before the loop
    // because we need to check if it's 0 before
    // printing the first "Teste %d"
    scanf("%d", &N);

    while (N != 0)
    {
        printf("Teste %d\n", ++count);

        int diff = 0;

        for (int i = 0; i < N; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);

            diff += a - b;

            printf("%d\n", diff);
        }

        printf("\n");

        // read the next N after the logic is done
        // so we can check if it's 0 before the next loop
        scanf("%d", &N);
    }

    return 0;
}