#include <stdio.h>
#include <string.h>

#define MAX_STUDENT_NAME_LENGTH 21

int main()
{
    int currentInstance = 0;

    int lesserGrade;
    char chosenName[MAX_STUDENT_NAME_LENGTH];

    int numberOfStudentsInCurrentInstance;

    // For each line
    while (scanf("%d", &numberOfStudentsInCurrentInstance) != EOF)
    {
        currentInstance++;

        // grade = 11 is greater than any possible grade
        lesserGrade = 11;

        for (int i = 0; i < numberOfStudentsInCurrentInstance; i++)
        {
            char currStudent[MAX_STUDENT_NAME_LENGTH];
            int currGrade;

            // Read student name and grade (Don't support spaces in names)
            scanf("%s %d", currStudent, &currGrade);

            // In the first iteration, the current grade will always be lesser than the lesser grade (11)
            if (currGrade < lesserGrade)
            {
                lesserGrade = currGrade;
                strcpy(chosenName, currStudent);
            }
            // If the current grade is equal to the lesser grade and the current name
            // is lexicographically greater than the chosen name.
            else if (currGrade == lesserGrade && strcmp(currStudent, chosenName) > 0)
            {
                strcpy(chosenName, currStudent);
            }
        }

        printf("Instancia %d\n%s\n\n", currentInstance, chosenName);
    }

    return 0;
}
