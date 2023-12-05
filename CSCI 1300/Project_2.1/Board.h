#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include"CandyStore.h"
#define RED "\033[;41m"     /* Red */
#define GREEN "\033[;42m"   /* Green */
#define BLUE "\033[;44m"    /* Blue */
#define MAGENTA "\033[;45m" /* Magenta */
#define CYAN "\033[;46m"    /* Cyan */
#define ORANGE "\033[48;2;230;115;0m"  /* Orange (230,115,0)*/
#define RESET "\033[0m"



using namespace std;





struct Tile // Struct for each tile on the board. can store the color of the tile and the type of the tile(if it has a store or not)
{
    string color;
    string tile_type;
    int player;
    int special;
};


class Board
{
private:
    const static int _BOARD_SIZE = 83; // Number of tiles
    Tile _tiles[_BOARD_SIZE];
    const static int _NUM_CANDY_STORES = 3; // Number of candy stores
    int _candy_store_position[_NUM_CANDY_STORES];
    CandyStore _candyStores[_NUM_CANDY_STORES];
    int _positions[2];
    // vector<int> _gummySquares();

public:
    Board();
    
    void resetBoard();
    void displayTile(int);
    void displayBoard();
    void setSpecials();
    int getSpecial(int); // return special type at the tile at int
    int getPosition(int); // Return the int of the players location
    void addStores(CandyStore, int, int);
    CandyStore getStore(int);
    // int isStore(int);

    bool setPlayerPosition(int, int);

    int getBoardSize() const;
    // int getCandyStoreCount() const;
    int getPlayerPosition(int) const;
    // void setGummyTrap(int);

    // bool addCandyStore(int); 
    // bool isPositionCandyStore(int); 

    void movePlayer(int, int);

};

#endif
