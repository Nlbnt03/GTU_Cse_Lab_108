#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int target, guess, guessCount = 0;
    srand(time(0));
    target = rand() % 1000 + 1;
    printf("%d\n",target);

    printf("Welcome to the Guesssing Game!");
    while (guess != target)
    {
        printf("Enter your guess (between 1 and 1000) : ");
        scanf("%d",&guess);
        if(1 <= guess && guess <= 1000)
        {
            if (guess < target)
        {
            printf("Your guess is less than the target;\n");
        }
        else
        {
            printf("Your guess is greater than the target;\n");
        }
        }
        else
        {
            printf("invalid input\n");
        }
        guessCount++;
    }

    printf("Congratulations! You guessed the target number!\n");
    printf("Total guesses made : %d\n",guessCount);
}