//
// Created by Magshimim on 10/11/2023.
//

#include "system.h"
#include "words.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int charInsideWord(char ch, char* word) {
    for (int i = 0; i < strlen(word); ++i) {
        if (ch == word[i]) {
            return 1;
        }
    }
    return 0;
}

char* getUserGuess(void) {
    char* guess = (char*)malloc(sizeof(char) * WORD_LEN);
    do {
        printf("Enter your guess: ");
        fgets(guess, sizeof(guess), stdin);
        guess[strcspn(guess, "\n")] = 0;
        if (!guessAvailability(guess)) {
            printf("You just broke a rule. Please try again.\n");
        }
    } while (!guessAvailability(guess));
    return guess;
}

void printRules(void) {
    printf("|||| WORDLE ||||\n\n");
    printf("Rules:\n");
    printf("*) Every secret word contains 5 letters\n");
    printf("*) Every secret word is in lowercase\n");
    printf("*) Every secret word is in english\n");
    printf("*) Every secret word has only letters (no special characters)\n");
    printf("*) A guess which will not be in english + 5 letters will not be considered as a try\n\n");
    printf("Choose your difficulty level:\n");
    printf("1) easy - 50\n");
    printf("2) normal - 20\n");
    printf("3) hard - 15\n");
    printf("4) novice - 10\n");
    printf("5) expert - 5\n");
}

int getNumOfTries(void) {
    int diffChoice = 0;
    do {
        printf("Please type your level: ");
        scanf("%d", &diffChoice);
        getchar();
        if (diffChoice < 1 || diffChoice > 5) {
            printf("You just broke a rule! Please try again.\n");
        }
    } while (diffChoice < 1 || diffChoice > 5);

    switch (diffChoice) {
        case 1:
            return 50;

        case 2:
            return 20;

        case 3:
            return 15;

        case 4:
            return 10;

        case 5:
            return 5;

        default:
            return 50;
    }
}

int guessAvailability(char* guess) {
    if (strlen(guess) != 5) {
        return 0;
    }
    for (int i = 0; i < WORD_LEN; ++i) {
        if (*(guess + i) >= 65 && *(guess + i) <= 90) {
            *(guess + i) = *(guess + i) + 32;
        }
        if (guess[i] < 97 || guess[i] > 122) {
            return 0;
        }
    }
    return 1;
}