//
// Created by Magshimim on 10/11/2023.
//

#include "words.h"
#include "system.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

enum state {WRONG_LETTER = 0, WRONG_INDEX, CORRECT};
char words[][WORD_LEN] = {"light", "apple", "great", "break", "melon", "lemon", "brake", "leave", "alone", "grade", "phone"};

char* rndmWord(void) {
    int randIndex = 0;
    srand(time(NULL));
    randIndex = rand() % WORD_LEN;
    return words[randIndex];
}

word* checkStatus(char* secWord, char* guess) {
    word* wordState = (word*)malloc(sizeof(word));
    if (!wordState) {
        printf("Unsuccessful malloc!\n");
        return NULL;
    }
    wordState->chars = (letter*) malloc(sizeof(letter) * WORD_LEN);
    if (!(wordState->chars)) {
        printf("Unsuccessful malloc!\n");
        return NULL;
    }
    for (int i = 0; i < strlen(guess); ++i) {
        if (guess[i] == secWord[i]) {
            (wordState->chars + i)->state = CORRECT;
        } else if (charInsideWord(guess[i], secWord)) {
            (wordState->chars + i)->state = WRONG_INDEX;
        } else {
            (wordState->chars + i)->state = WRONG_LETTER;
        }
        (wordState->chars + i)->letter = guess[i];
    }
    return wordState;
}

int printWord(word* guess, int len) {
    int correctCount = 0;
    int halfCount = 0;
    for (int i = 0; i < len; ++i) {
        switch ((guess->chars + i)->state) {
            case 0:
                printf("[] ");
                break;

            case 1:
                printf("[] ");
                halfCount++;
                break;

            case 2:
                printf("[%c] ", (guess->chars + i)->letter);
                correctCount++;
                break;
        }
    }
    if (halfCount) {
        printf("+ ");
        for (int i = 0; i < len; ++i) {
            if ((guess->chars + i)->state == 1) {
                printf("%c ", (guess->chars + i)->letter);
            }
        }
    }
    printf("\n");
    return correctCount;
}