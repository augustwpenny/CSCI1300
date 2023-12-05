#ifndef CANDYLAND_H
#define CANDYLAND_H

#include <iostream>
#include <vector>
#include"Player.h"
#include"Board.h"
// #include"CandyStore.h"


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
        Candy _candies[30]; // I couldnt find anything giving me a max number of possible candies, so i am going to assume 30
        int _numCandies=0;
        Player _players[2];
        Character _characters[4];
        // CandyStore _c1,_c2,_c3,_firststore;
        int _stores[3];
        
        Board _board;


        int _firstPos[10] = {0,3,8,9,12,15,18,21,24,27};
        int _secondPos[9] = {29,32,35,38,41,44,47,50,53};
        int _thirdPos[9] = {58,61,64,67,70,73,76,79,82};

        int _magenta[28] ={0,3,6,9,12,15,18,21,24,27,30,33,36,39,42,45,48,51,54,57,60,63,66,69,72,75,78,81};
        int _green[27] ={1,4,7,10,13,16,19,22,25,28,31,34,37,40,43,46,49,52,55,58,61,64,67,70,73,76,79};
        int _blue[27] ={2,5,8,11,14,17,20,23,26,29,32,35,38,41,44,47,50,53,56,59,62,65,68,71,74,77,80};

    public:
        CandyLand();
        CandyLand(string, string);

        
        void loadCharacters(string); // Good
        void loadCandies(string); // Good
        

        void printCharacters();
        void printBoard(); // for testing

        // void setupPlayer(int, int, string);
        // void setupBoard(); // called in the setupGame function to set up the board (Place stores, traps etc.)
        // void setupStores();
        // int checkStore(int); // returns 0 if no store, then 1-3 based on which store it is at

        void startGame(); // starts the game
        void specialTile(int);

        // int showTurn();
        
        int useCard(string);

        void chooseCharacter(int); // done
        void printInfo(int); //testing purpouses
        bool checkSkipTurn(int); // Returns true if the player has a turn to be skipped. decrements their turn to be skipped. also accounts for stamina

        void chooseCard(int);
            string move(Card, int); //Uses drawCard to draw a card and getColor to determine current color. works. int is player number. .move(c.drawCard(),<0 or 1>) << endl;
                Card drawCard();
                int getColor(int);

    
        void useCandy(int);
        // int checkIsStore(int);


        Candy getCandy(string); // Works. gets candy from the list of candies
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