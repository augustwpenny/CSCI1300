#ifndef CANDYLAND_H
#define CANDYLAND_H

#include <iostream>
#include <vector>
#include"Player.h"
#include"Board.h"
#include"CandyStore.h"
// CSCI 1300 Fall 2023
// Author: August Penny
// TA: Guarav Roy
// CandyLand.h


using namespace std;




struct Card
{
    string name;
    string color;
    bool dbl=false;
};

struct Character // Characters are read in from a file and store data until a player chooses them
{
    string name;
    int gold;
    int stamina;
    Candy candies[9]; 
    int numCandies;
};





// // Rand on [1,3]
// //1=pink, 2=green, 3=blue

class CandyLand
{
    private:
        Candy _candies[30]; // I couldnt find anything giving me a max number of possible candies, so i am going to assume 30. this array contains all the candies loaded from a file
        int _numCandies=0; // int tracking how many candies were loaded
        Player _players[2]; // Array containing the two players
        Character _characters[4]; // Array of the 4 characters that can be chosen from
        string _outputFileName; // Name of the file that the info is written to
        
        Board _board; // the board object for the game
        
        string _winner; // string that stores the winners name


        int _firstPos[10] = {0,3,8,9,12,15,18,21,24,27}; // List of possible positons for the first store
        int _secondPos[9] = {29,32,35,38,41,44,47,50,53}; // List of possible positions for the second store
        int _thirdPos[9] = {58,61,64,67,70,73,76,79,82}; // List of possible positions for the thrird store

        int _magenta[30] ={0,3,6,9,12,15,18,21,24,27,30,33,36,39,42,45,48,51,54,57,60,63,66,69,72,75,78,81,84,87}; // list of every magenta tile
        int _green[29] ={1,4,7,10,13,16,19,22,25,28,31,34,37,40,43,46,49,52,55,58,61,64,67,70,73,76,79,82,85}; // list of every green tile
        int _blue[29] ={2,5,8,11,14,17,20,23,26,29,32,35,38,41,44,47,50,53,56,59,62,65,68,71,74,77,80,83,86}; // list of every blue tile

    public:
        CandyLand(); // default and only constructor
        
        void loadCharacters(string); // Loacs characters from a file
        void loadCandies(string); //Loads all candies from a file into a 
        void setOutputFile(string); // Sets the file the final stats are written to
        void setupStores(); // sets up 3 random stores in random places with random candies(wintin the constraints of the writeup)
        
        void printCharacters();// prints out the characters for player to choose from
        void printBoard();// displays the board
        void printInfo(int);// Prints the players inventory
        void writeGameInfo(string);//Writes the games info to a file
        void chooseCharacter(int); //prints out the characters to choose from and then translates that characters info to the player based on their selection

        void takeTurn(int); // Method that executes all aspects of each turn and calls appropriate methods within it
        void specialTile(int); // checks if a player is on a special tile, and if they are it moves them accordingly
        bool checkSkipTurn(int); // Returns true if the player has a turn to be skipped. decrements their turn to be skipped. also accounts for stamina

        
        void startGame(); //contains the execution of the game

        void chooseCard(int); // Handles drawing a card, moving a player
        string move(Card, int); //Uses drawCard to draw a card and move a player appropiatley
        Card drawCard(); // Generates a card based on probabilities
        int getColor(int); // returns the tile color at the given position

        void useCandy(int); //Prompts a player what candy they want to use then execute that candy's effects
        Candy getCandy(string); // returns a candy object from the list of candies based on a string name inputted to it
        Candy randomCandy(); // Returns a random candy from the list of candies. used for making stores

        void checkStore(int); // Checks if a tile has a store and if it does it initiates the store sequence

        bool endGame(); // Checks the players positions to see if one has won the game
        


        
};

#endif
