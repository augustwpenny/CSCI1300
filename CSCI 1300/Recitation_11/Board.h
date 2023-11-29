#ifndef BOARD_H
#define BOARD_H

// CSCI 1300 Fall 2023
// Author: August Penny
// TA: Guarav Roy
// Board.h
#include <iostream>
#include <vector>
#define RED "\033[;41m"     /* Red */
#define GREEN "\033[;42m"   /* Green */
#define BLUE "\033[;44m"    /* Blue */
#define MAGENTA "\033[;45m" /* Magenta */
#define CYAN "\033[;46m"    /* Cyan */
#define ORANGE "\033[48;2;230;115;0m"  /* Orange (230,115,0)*/
#define RESET "\033[0m"

using namespace std;



struct Tile
{
    string color;
    string tile_type;
};


class Board
{
private:
    const static int _BOARD_SIZE = 83;
    Tile _tiles[_BOARD_SIZE];
    const static int _MAX_CANDY_STORE = 3;
    int _candy_store_position[_MAX_CANDY_STORE];
    int _candy_store_count;
    int _player_position[2];

public:
    Board();

    void resetBoard();
    void displayTile(int, int);
    void displayBoard();

    bool setPlayerPosition(int, int);

    int getBoardSize() const;
    int getCandyStoreCount() const;
    int getPlayerPosition(int player) const;

    bool addCandyStore(int);
    bool isPositionCandyStore(int); 

    bool movePlayer(int tile_to_move_forward, int);
};

#endif
