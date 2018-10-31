/* Author: Marissa Montano
   CSCI 1300 - 111 Spring
   Assignment 8*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctype.h>
#include "Graphics.h"



//Sets up the body & asks for spaces
Graphics::Graphics(string str)
{
    werd = str;
}
//when someone guesses wrong it fills the body takes in the number of guesses)
void Graphics::fillBody()
{
    if (Win == false)
    {
        if (correct == false)
        {
            if(chances == 1)
            {
                Body[1][7] ='0';
            }
            if(chances  == 2)
            {
                Body[2][7] = '|';
            }
            if(chances  == 3)
            {
                Body[2][6] ='/';
            }
            if(chances  == 4)
            {
                Body[2][8] ='\\';
            }
            if(chances  == 5)
            {
                Body[3][7] ='|';
            }
            if(chances  == 6)
            {
                Body[4][6] ='/';
            }
            if(chances  == 7)
            {
                Body[4][8] ='\\';
                for(int i=0;i<6;i++)
                {
                    for(int j=0; j<9; j++)
                    {
                       cout<< Body[i][j];
                    }
                    cout<<endl;
                }
                cout<< "\nSorry you lost the game... \nThe word you where guessing was: " << werd <<endl;
                Win = true;
            }
        }
        if (Win == false)
        {
            for(int i=0;i<6;i++)
            {
                for(int j=0; j<9; j++)
                {
                   cout<< Body[i][j];
                }
                cout<<endl;
            }
            cout<<endl;
            cout<<endl;
        }
    }
}
//clears the body for another game
void Graphics::DeletBody()
{
    for(int i=0; i<9; i++)
        Body[0][i] ='-';
    for(int j=0; j<9; j++)
        Body[1][j] =' ';
    for(int k=0; k<9; k++)
        Body[2][k] =' ';
    for(int l=0; l<9; l++)
        Body[3][l] =' ';
    for(int m=0; m<9; m++)
        Body[4][m] =' ';
    for(int n=0; n<9; n++)
        Body[5][n] =' ';
    for (int f=1; f<6;f++)
        Body[f][0]= '|';

    for(int g=0;g<6;g++)
    {
        for(int h=0; h<9; h++)
        {
           cout<< Body[g][h];
        }
    cout<<endl;
    }
}
//spaces for the word to be filled
void Graphics::AddSpace(int m)
{
    for (int i=0; i<m; i++)
        GameSpace[i] = '_';

    cout<< "Word you are guessing: ";
    for (int j=0; j<m; j++)
        cout << GameSpace[j] <<" ";
    cout<<endl;
}
//checks if you got the letter correct or won
void Graphics::Check(int v, char ch, string st)
{
    correct = false;
    int z=0;
    for (int i=0; i<v; i++)
        if (ch == st[i])
        {
            GameSpace[i]= ch;
            correct = true;
            //cout <<chances<<"&" <<correct<<endl;
        }
    if(correct == false)
       {
           chances++;
            //cout <<chances<<"&" <<correct<<endl;
        }

    cout<< "Letters you have guessed: ";
    for (int j=0; j<v; j++)
        cout << GameSpace[j]<<" ";
    cout<<endl;

    for (int m=0; m<v; m++)
    {
        if (GameSpace[m] == '_')
        {
            z++;
        }
    }
    if(z==0)
    {
        Win = true;
        cout<< "Congratulations!!! You won the game!!!"<<endl;
        cout<< "The word really was: " << werd << endl;
    }
    else
        z=0;

}

bool Graphics::Report(string fileName)
 {
    bool load = true;
    ofstream file;
    file.open(fileName.c_str(), ios::out);

    //if you successfully open
    if (file.is_open())
    {
        for(int i=0;i<6;i++)
        {
            for(int j=0; j<9; j++)
                file<< Body[i][j];
            file<<endl;
        }

        file.close();
    }
    else
       load = false;
    return load;
 }

 //gets bool Win
 bool Graphics::GetWin()
 {
     return Win;
 }


