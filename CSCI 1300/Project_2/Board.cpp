#include "Board.h"

// CSCI 1300 Fall 2023
// Author: August Penny
// TA: Guarav Roy
// Board.cpp

using namespace std;



Board::Board()
{
    resetBoard();
    // _candyStores[0]=c1;
    // _candyStores[1]=c2;
    // _candyStores[2]=c3;
    // addCandyStore(c1.getPosition());
    // addCandyStore(c2.getPosition());
    // addCandyStore(c3.getPosition());
}

void Board::resetBoard()
{
    const int COLOR_COUNT = 3;
    const string COLORS[COLOR_COUNT] = {MAGENTA, GREEN, BLUE};
    Tile new_tile;
    string current_color;
    for (int i = 0; i < _BOARD_SIZE - 1; i++)
    {
        current_color = COLORS[i % COLOR_COUNT];
        new_tile = {current_color, "regular tile"};
        _tiles[i] = new_tile;
    }
    new_tile = {ORANGE, "regular tile"};
    _tiles[_BOARD_SIZE - 1] = new_tile;

    // _candy_store_count = 0;
    // for (int i = 0; i < _NUM_CANDY_STORES; i++)
    // {
    //     _candy_store_position[i] = -1;
    // }

    _positions[0]=0;
    _positions[1]=0;
}

void Board::displayTile(int position)
{
    if (position < 0 || position >= _BOARD_SIZE)
    {
        return;
    }
    Tile target = _tiles[position];
    cout << target.color << " ";
    if (position == _positions[0])
    {
        cout << 1;
    }
    else if (position == _positions[1])
    {
        cout << 2;
    }
    else
    {
        cout << " ";
    }
    cout << " " << RESET;
}

void Board::displayBoard()
{
    // First horizontal segment
    for (int i = 0; i <= 23; i++)
    {
        displayTile(i);
    }
    cout << endl;
    // First vertical segment
    for (int i = 24; i <= 28; i++)
    {
        for (int j = 0; j < 23; j++)
        {
            cout << "   ";
        }
        displayTile(i);
        cout << endl;
    }
    // Second horizontal segment
    for (int i = 52; i > 28; i--)
    {
        displayTile(i);
    }
    cout << endl;
    // Second vertical segment
    for (int i = 53; i <= 57; i++)
    {
        displayTile(i);
        for (int j = 0; j < 23; j++)
        {
            cout << "   ";
        }
        cout << endl;
    }
    // Third horizontal segment
    for (int i = 58; i < _BOARD_SIZE; i++)
    {
        displayTile(i);
    }
    cout << ORANGE << "Castle" << RESET << endl;
}

bool Board::setPlayerPosition(int new_position, int player)
{
    
    if (new_position >= 0 && new_position < _BOARD_SIZE)
    {
        _positions[player] = new_position;
        return true;
    }
    return false;
}

int Board::getBoardSize() const
{
    return _BOARD_SIZE;
}

// int Board::getCandyStoreCount() const
// {
//     return _candy_store_count;
// }

int Board::getPlayerPosition(int player) const
{
    return _positions[player];
}

// bool Board::addCandyStore(int position)
// {
//     if (_candy_store_count >= _NUM_CANDY_STORES)
//     {
//         return false;
//     }
//     _candy_store_position[_candy_store_count] = position;
//     _candy_store_count++;
//     return true;
// }

// bool Board::isPositionCandyStore(int board_position) // Checks to see if a players position is a candy store
// {
//     for (int i = 0; i < _candy_store_count; i++)
//     {
//         if(_candy_store_position[i] == board_position)
//         {
//             return true;
//         }
//     }
//     return false;
// }

bool Board::movePlayer(int newPos, int player)
{
    
    if(newPos < 0 || newPos >= _BOARD_SIZE)
    {
        return false;
    }
    _positions[player] = newPos;
    return true;
}
// void Board::setGummyTrap(int position)
// {
//     _gummySquares.push_back
// }
