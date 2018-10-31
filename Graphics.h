/* Author: Marissa Montano
   CSCI 1300 - 111 Spring
   Assignment 8*/

#include <iostream>
#include <string>
#include "Guess.h"

using namespace std;
#ifndef GRAPHICS_H
#define GRAPHICS_H

class Graphics : public Guess
{
//Data members
public:
    char Body[6][9]; //initial body at start of game (maybe from a file)
    string werd; //word being guessed
    char GameSpace[20]; //reveals the word being guessed
    bool correct; //checks the players guess
    int chances=0; //How many guesses they have taken
    bool Win = false; //checks if player won

//Constructors
public:
    Graphics();
    Graphics(string);

//Methods
public:
    void fillBody();//when someone guesses wrong it fills the body takes in the number of guesses)
    void Check(int, char, string);//checks if you got the letter correct or won
    void DeletBody();//clears the body for another game
    void AddSpace(int);//spaces for the word to be filled
    bool Report(string); //writes to a file game statistics
    bool GetWin();//gets bool Win
};
#endif
