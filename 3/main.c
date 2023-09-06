#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    int soma = 0;

    for (int i = 0; i < N; i++)
    {
        int X;
        scanf("%d", &X);

        soma += X;
    }

    printf("%d\n", soma);

    return 0;
}
