/* Author: Marissa Montano
   CSCI 1300 - 111 Spring
   Assignment 8*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#include "Guess.h"

using namespace std;

//asks user for the word being guessed and how many guesses the other player gets (up to 7)
Guess::Guess()
{
    players = 1;
}

//takes the word being guessed and how many guesses the other user gets
Guess::Guess(string GuessWord, int numPlayers)
{
    players = numPlayers;
    word = GuessWord;
    StripWord(GuessWord);
}

//reads in a random file for single players
bool Guess::ReadRandomFile(string fileName)
{
    string Rand;
    int i=0;
    bool success = true;
    ifstream file;

    file.open(fileName);

    //if you successfully open
    if (file.is_open())
    {
        while (!file.eof())
        {
            getline(file, Rand);
            random[i] = Rand;
            i++;
        }

        file.close();

    }
    else
        success = false;

return success;
}

//picks a random word
string Guess::PickRandWord()
{
    int ArrayIndex = 0;
    srand (time(NULL));
    ArrayIndex = rand() % 2961;
    word = random [ArrayIndex];
    length = word.length();
    return word;
}

//strip word of caps and punct and adds it to array
string  Guess::StripWord(string str)
{
    string fix;
    for(int i = 0; i < str.length(); i++)
    {
        if(!ispunct(str[i]))
        fix += str[i];
    }
    for (int j = 0; j< fix.length(); j++)
        fix[j] = tolower(fix[j]);

    word = fix;
    length = word.length();
    return word;
}

//strip word of caps and punct.
char Guess::StripGuesss(char g)
{
    guess = tolower(g);
}

//gets int length
 int Guess::GetLength()
 {
     return length;
 }

 //gets char guess
 char Guess::GetGuess()
 {
     return guess;
 }

 //gets string word
 string Guess::GetWord()
 {
     return word;
 }

