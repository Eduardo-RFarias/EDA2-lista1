#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    // declare a bool array of 1000001 elements (10^6 + 1) with all elements set to false
    bool *histogram = (bool *)calloc(1000001, sizeof(bool));

    int numberOfEntries;
    scanf("%d", &numberOfEntries);

    int number_of_distinct_elements = 0;

    for (int i = 0; i < numberOfEntries; i++)
    {
        int studentCode;
        scanf("%d", &studentCode);

        if (histogram[studentCode] == false)
        {
            number_of_distinct_elements++;
            histogram[studentCode] = true;
        }
    }

    printf("%d\n", number_of_distinct_elements);

    free(histogram);

    return 0;
}