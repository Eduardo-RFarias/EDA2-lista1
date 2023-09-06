#include <stdio.h>

int main()
{
    int qtd = 0;
    int n;

    while (scanf("%d", &n) != EOF)
    {
        qtd++;
    }

    printf("%d\n", qtd);

    return 0;
}
