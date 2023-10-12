#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "words.h"
#include "system.h"

int main(void) {
    printRules();
    int stopFlag = 1;

    do {
        int numOfTries = getNumOfTries();
        char* secretWord = (char*)malloc(sizeof(char) * WORD_LEN);
        strcpy(secretWord, rndmWord());
        *(secretWord + WORD_LEN) = '\0';

        int winFlag = 0;
        do {
            char *guess = getUserGuess();
            word *guessStatus = checkStatus(secretWord, guess);
            winFlag = printWord(guessStatus, WORD_LEN);
            numOfTries--;
            printf("Tries left: %d\n", numOfTries);
        } while (winFlag != WORD_LEN && numOfTries != 0);

        if (winFlag == WORD_LEN) {
            printf("\nYou did it!!!\n");
        }
        if (numOfTries == 0) {
            printf("You lost :(\n");
        }
        printf("Do you want to play again: 0 for yes any for no:\n");
        scanf("%d", &stopFlag);
        getchar();

        free(secretWord);
    } while (!stopFlag);

    printf("Thanks for playing:) GoodBye!");
    return 0;
}
