#ifndef CANDYLAND_H
#define CANDYLAND_H

#include <iostream>
#include <vector>
#include"Player.h"
#include"Board.h"
#include"CandyStore.h"


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
};



// // Rand on [1,3]
// //1=pink, 2=green, 3=blue

class CandyLand
{
    private:
        Candy _candies[30]; // I couldnt find anything giving me a max number of possible candies, so i am going to assume 30
        int _numCandies=0;
        Player t1, t2;
        Player _players[2]= {t1, t2};
        Character _characters[4];
        CandyStore _c1,_c2,_c3,_firststore;
        int _stores[3];
        
        Board _board;


        int _firstPos[10] = {0,3,8,9,12,15,18,21,24,27};
        int _secondPos[9] = {29,32,35,38,41,44,47,50,53};
        int _thirdPos[9] = {58,61,64,67,70,73,76,79,82};

    public:
        CandyLand();
        CandyLand(string, string);

        
        void loadCharacters(string); // Will make an array of characters than can be printed out. when a character is selected, copy its data to the player info
        void loadCandies(string);
        

        void printCharacters();

        void setupPlayer(int, int, string);
        void setupBoard(); // called in the setupGame function to set up the board (Place stores, traps etc.)
        void setupStores();

        void startGame(); // starts the game

        int showTurn();
        Card drawCard();
        void move(Player, Card, int);
        void useCandy(int);
        int checkIsStore(int);


        Candy getCandy(string); // Gets a candy of a certain name from a list of strings
        Candy randomCandy(); // Returns a random candy from the list.
};

#endif

// /**
//  * Structs -> candy, card
//  * class -> Player, Board, Tile, CandyLand
//  * Events, Riddle, CandyStore
//  * 
//  * 0. Setup the game
//  *      Set up the board -> num tiles
//  *      Place candy stores -> number and location
//  *      place special tiles
//  *      ...
//  * 
//  * 1. Load candy from file -> could be in candyland class
//  * 2. Visit Candystore -> in the board or candland class
//  * 3. Load characters from a file ->candyland class
//  * 4. Choose a character -> player class
//  * 5. Choose number of players
// */