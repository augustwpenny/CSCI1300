#ifndef CANDYSTORE_H
#define CANDYSTORE_H

// CSCI 1300 Fall 2023
// Author: August Penny
// TA: Guarav Roy
// CandyStore.h

#include"Player.h"

using namespace std;

class CandyStore{
    private:
    Candy _candies[3];
    int _position;

    public:
    CandyStore(); // Default constructor

    void removeCandy(string); // Removes a candy based on a string
    void addCandy(Candy, int); // Adds a candy to the store
    void displayCandy(); // Displays the names of the candies in the store
    Candy getCandy(int); // returns a candy at a position
    void printCandies(); // Prints out the candies in the store abd their information
    int getPosition(); // returns the position of the candy store
    void setPosition(int); // sets the positon of the candy store

    void shop();

};

#endif