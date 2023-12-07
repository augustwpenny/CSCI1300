#include<iostream>
#include"CandyLand.h"

// CSCI 1300 Fall 2023
// Author: August Penny
// TA: Guarav Roy
// CandyLandDriver.cpp

using namespace std;

int main()
{

    CandyLand c; // create candy land object
    c.loadCandies("candies.txt"); // Loads the candies from a file
    c.loadCharacters("characters.txt"); // Loads the characters from a file
    c.setOutputFile("outfile.txt"); // Sets the file that the game stats will be printed to
    c.setupStores(); // sets up the stores for the game
    c.startGame(); // runs the game
    return 0;
}
