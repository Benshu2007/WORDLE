//
// Created by Magshimim on 10/11/2023.
//

#ifndef WORDLE_WORDS_H
#define WORDLE_WORDS_H

#define WORD_LEN 5

typedef struct letter {
    char letter;
    int state;
} letter;

typedef struct word {
    letter* chars;
} word;

char* rndmWord(void);
/**
 * Function randomizing a random word from the word list
 * */
word* checkStatus(char* word, char* guess);
/**
 * Function checks the guess correctness
 * */
int printWord(word* guess, int len);
/**
 * Function prints the checked guess and returns the number of correct letters
 * */

#endif //WORDLE_WORDS_H
