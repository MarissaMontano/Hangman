/* Author: Marissa Montano
   CSCI 1300 - 111 Spring
   Assignment 8*/

#include <iostream>
#include <string>

using namespace std;
#ifndef GUESS_H
#define GUESS_H

class Guess
{
//Data members
public:
    string word; //Word player is guessing (no caps or punct)
    int players; //Two player game
    int length; //length of the word being guessed
    char guess; // The guess they made (ie. the letter they chose)
    string random [2961]; //lets single players play by them selfs with a random word from a file

//constructors
public:
    Guess();
    Guess(string, int); //takes the word being guessed and number of players

//Methods
public:
    int GetLength();//gets int length
    char GetGuess();//gets char guess
    string GetWord();//gets string word
    string StripWord(string); //strip word of caps and punct.
    char StripGuesss(char); //strips guess of caps
    string PickRandWord(); //picks word from the random file
    bool ReadRandomFile(string); //reads in a random file for single players
};
#endif
