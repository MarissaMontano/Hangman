/* Author: Marissa Montano
   CSCI 1300 - 111 Spring
   Assignment 8*/

#include <iostream>
#include "Guess.h"
#include "Guess.cpp"
#include "Graphics.h"
#include "Graphics.cpp"
using namespace std;


int main()
{
    int playerss;
    string p1Word;
    char p2Guess;
    int helper1 =0;
    bool helper2;
    char helper3;
    string helper4;
    string secret_word;


    //Get users needed info
    cout<< "Hello! Welcome to the wonderful game of hangman"<<endl;
    cout<< "To start off I need to ask you a couple of questions..."<<endl;
    cout<< "How many people are playing, 1 or 2? (please enter a number)"<<endl;
    cin>> playerss;

    while ((playerss != 1)&&(playerss != 2))
    {
        cout<< "I'm sorry, this is a game for 1 or 2 players please try again"<<endl;
        cin>> playerss;
    }

    if (playerss == 2)
    {
        cout<< "player one, please enter a single word that player two has to guess: "<<endl;
        cin>> p1Word;
    }

    cout<< "Awesome, let's begin!" <<endl;

//Set up the game
    if (playerss == 1)
    {
        Guess game;
        game.ReadRandomFile("SoloPlayer.txt");
        game.PickRandWord();
        helper1 = game.GetLength();
        secret_word = game.GetWord();

        Graphics board(secret_word);
        board.DeletBody();
        board.AddSpace(helper1);
        helper2 = board.GetWin();
        helper3 = game.GetGuess();
        helper4 = game.GetWord();

        //Begin playing
        while (helper2 == false)
        {
            cout<< "Player, guess one letter that might be in the word I picked for you: (please enter a single letter)"<<endl;
            cin>>p2Guess;
            game.StripGuesss(p2Guess);
            helper3 = game.GetGuess();
            board.Check(helper1,helper3,helper4);
            helper2 = board.GetWin();
            board.fillBody();
            helper2 = board.GetWin();
        }
    }
    else
    {
        Guess game(p1Word, playerss);
        helper1 = game.GetLength();
        secret_word = game.GetWord();
        Graphics board(secret_word) ;
        board.DeletBody();
        board.AddSpace(helper1);
        helper2 = board.GetWin();
        helper3 = game.GetGuess();
        helper4 = game.GetWord();

        //Begin playing
        while (helper2 == false)
        {
            cout<< "Player two, guess one letter that might be in the word player one picked for you: (please enter a single letter)"<<endl;
            cin>>p2Guess;
            game.StripGuesss(p2Guess);
            helper3 = game.GetGuess();
            helper2 = board.GetWin();
            board.Check(helper1,helper3,helper4);
            helper2 = board.GetWin();
            board.fillBody();
            helper2 = board.GetWin();
        }
    }

return 0;
}
