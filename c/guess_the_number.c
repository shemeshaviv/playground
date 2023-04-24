#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ATTEMPTS 5
#define MAX_GUESS 20

int main()
{
    srand(time(NULL));
    int r = rand() % (MAX_GUESS+1);
    int number;
    printf("Guess the number I chose between 0 and %d\n", MAX_GUESS);
    for(int i=ATTEMPTS; i >= 0; i--)
    {
        printf("You have %d attempts left\n", i);
        for(;;)
        {

            printf("Guess a number: ");
            scanf("%d", &number);
            if(number >= 0 && number <= MAX_GUESS)
                break;
            else
                printf("Please choose a number between 0 and %d", MAX_GUESS);
        }
        if(number > r)
            printf("You guessed a number bigger than what I chose\n");
        else if(number < r)
            printf("You guessed a number smaller than what I chose\n");
        else
        {
            printf("You guessed CORRECTLY!\n");
            break;
        }
    }
    return 0;
}
