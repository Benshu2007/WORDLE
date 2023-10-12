//
// Created by Magshimim on 10/11/2023.
//

#ifndef WORDLE_SYSTEM_H
#define WORDLE_SYSTEM_H

int charInsideWord(char ch, char* word);
/**
 * Function checks if char is in a string
 * */
char* getUserGuess(void);
/**
 * Function gets a guess from the user
 * */
void printRules(void);
/**
 * Function prints the game rules
 * */
int getNumOfTries(void);
/**
 * Function gets the choice and returns the number of tries
 * */

int guessAvailability(char* guess);
/**
 * Function checks availability of the choice
 * */

#endif //WORDLE_SYSTEM_H
