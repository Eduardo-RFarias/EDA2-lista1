#include <stdio.h>

int main()
{
    int currentDay = 0;
    int chosenCode;
    int greatestRank;

    int numberOfRestaurantsInCurrentDay;

    // For each line
    while (scanf("%d", &numberOfRestaurantsInCurrentDay) != EOF)
    {
        chosenCode = -1;
        greatestRank = -1;
        currentDay++;

        // For each pair of numbers in the current line
        for (int i = 0; i < numberOfRestaurantsInCurrentDay; i++)
        {
            int currCode, currRank;
            scanf("%d %d", &currCode, &currRank);

            // The first restaurant of the day will always execute this if
            // statement, because greatestRank is initialized with -1.
            if (currRank > greatestRank)
            {
                chosenCode = currCode;
                greatestRank = currRank;
            }
            // At this point, we know that chosenCode is not -1 anymore, so we can
            // compare currCode with chosenCode.
            else if (currRank == greatestRank && currCode < chosenCode)
            {
                chosenCode = currCode;
                greatestRank = currRank;
            }
        }

        printf("Dia %d\n%d\n\n", currentDay, chosenCode);
    }

    return 0;
}
