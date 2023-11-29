// #include "Board.h"

// // CSCI 1300 Fall 2023
// // Author: August Penny
// // TA: Guarav Roy
// // Board.cpp

// Board::Board()
// {
//     resetBoard();
// }

// void Board::resetBoard()
// {
//     const int COLOR_COUNT = 3;
//     const string COLORS[COLOR_COUNT] = {MAGENTA, GREEN, BLUE};
//     Tile new_tile;
//     string current_color;
//     for (int i = 0; i < _BOARD_SIZE - 1; i++)
//     {
//         current_color = COLORS[i % COLOR_COUNT];
//         new_tile = {current_color, "regular tile"};
//         _tiles[i] = new_tile;
//     }
//     new_tile = {ORANGE, "regular tile"};
//     _tiles[_BOARD_SIZE - 1] = new_tile;

//     _candy_store_count = 0;
//     for (int i = 0; i < _MAX_CANDY_STORE; i++)
//     {
//         _candy_store_position[i] = -1;
//     }

//     _player_position = 0;
// }

// void Board::displayTile(int position)
// {
//     if (position < 0 || position >= _BOARD_SIZE)
//     {
//         return;
//     }
//     Tile target = _tiles[position];
//     cout << target.color << " ";
//     if (position == _player_position)
//     {
//         cout << "X";
//     }
//     else
//     {
//         cout << " ";
//     }
//     cout << " " << RESET;
// }

// void Board::displayBoard()
// {
//     // First horizontal segment
//     for (int i = 0; i <= 23; i++)
//     {
//         displayTile(i);
//     }
//     cout << endl;
//     // First vertical segment
//     for (int i = 24; i <= 28; i++)
//     {
//         for (int j = 0; j < 23; j++)
//         {
//             cout << "   ";
//         }
//         displayTile(i);
//         cout << endl;
//     }
//     // Second horizontal segment
//     for (int i = 52; i > 28; i--)
//     {
//         displayTile(i);
//     }
//     cout << endl;
//     // Second vertical segment
//     for (int i = 53; i <= 57; i++)
//     {
//         displayTile(i);
//         for (int j = 0; j < 23; j++)
//         {
//             cout << "   ";
//         }
//         cout << endl;
//     }
//     // Third horizontal segment
//     for (int i = 58; i < _BOARD_SIZE; i++)
//     {
//         displayTile(i);
//     }
//     cout << ORANGE << "Castle" << RESET << endl;
// }

// bool Board::setPlayerPosition(int new_position)
// {
//     if (new_position >= 0 && new_position < _BOARD_SIZE)
//     {
//         _player_position = new_position;
//         return true;
//     }
//     return false;
// }

// int Board::getBoardSize() const
// {
//     return _BOARD_SIZE;
// }

// int Board::getCandyStoreCount() const
// {
//     return _candy_store_count;
// }

// int Board::getPlayerPosition() const
// {
//     return _player_position;
// }

// bool Board::addCandyStore(int position)
// {
//     if (_candy_store_count >= _MAX_CANDY_STORE)
//     {
//         return false;
//     }
//     _candy_store_position[_candy_store_count] = position;
//     _candy_store_count++;
//     return true;
// }

// bool Board::isPositionCandyStore(int board_position)
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

// bool Board::movePlayer(int tile_to_move_forward)
// {
//     int new_player_position = tile_to_move_forward + _player_position;
//     if(new_player_position < 0 || new_player_position >= _BOARD_SIZE)
//     {
//         return false;
//     }
//     _player_position = new_player_position;
//     return true;
// }




#include "Board.h"

// CSCI 1300 Fall 2023
// Author: August Penny
// TA: Guarav Roy
// Board.cpp

Board::Board()
{
    resetBoard();
}

// Board::Board(CandyStore c1, CandyStore c2, CandyStore c3)
// {
//     resetBoard();
//     _candyStores[0]=c1;
//     _candyStores[1]=c2;
//     _candyStores[2]=c3;
//     addCandyStore(c1.getPosition());
//     addCandyStore(c2.getPosition());
//     addCandyStore(c3.getPosition());
// }

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

    _candy_store_count = 0;
    for (int i = 0; i < _MAX_CANDY_STORE; i++)
    {
        _candy_store_position[i] = -1;
    }

    _player_position[0] = 0;
    _player_position[1] = 0;
}



void Board::displayTile(int position, int turn)
{
    if (position < 0 || position >= _BOARD_SIZE)
    {
        return;
    }
    Tile target = _tiles[position];
    cout << target.color << " ";
    if (position == _player_position[0])
    {
        cout << 1;
    }
    else if(position == _player_position[1])
    {
        cout << 2;
    }
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
        displayTile(i, i%2);
    }
    cout << endl;
    // First vertical segment
    for (int i = 24; i <= 28; i++)
    {
        for (int j = 0; j < 23; j++)
        {
            cout << "   ";
        }
        displayTile(i, i%2);
        cout << endl;
    }
    // Second horizontal segment
    for (int i = 52; i > 28; i--)
    {
        displayTile(i, i%2);
    }
    cout << endl;
    // Second vertical segment
    for (int i = 53; i <= 57; i++)
    {
        displayTile(i, i%2);
        for (int j = 0; j < 23; j++)
        {
            cout << "   ";
        }
        cout << endl;
    }
    // Third horizontal segment
    for (int i = 58; i < _BOARD_SIZE; i++)
    {
        displayTile(i, i%2);
    }
    cout << ORANGE << "Castle" << RESET << endl;
}

bool Board::setPlayerPosition(int new_position, int player)
{
    
    if (new_position >= 0 && new_position < _BOARD_SIZE)
    {
        _player_position[player] = new_position;
        return true;
    }
    return false;
}

int Board::getBoardSize() const
{
    return _BOARD_SIZE;
}

int Board::getCandyStoreCount() const
{
    return _candy_store_count;
}

int Board::getPlayerPosition(int player) const
{
    return _player_position[player];
}

bool Board::addCandyStore(int position)
{
    if (_candy_store_count >= _MAX_CANDY_STORE)
    {
        return false;
    }
    _candy_store_position[_candy_store_count] = position;
    _candy_store_count++;
    return true;
}

bool Board::isPositionCandyStore(int board_position) // Checks to see if a players position is a candy store
{
    for (int i = 0; i < _candy_store_count; i++)
    {
        if(_candy_store_position[i] == board_position)
        {
            return true;
        }
    }
    return false;
}

bool Board::movePlayer(int tile_to_move_forward, int player)
{
    int new_player_position = tile_to_move_forward + _player_position[player];
    if(new_player_position < 0 || new_player_position >= _BOARD_SIZE)
    {
        return false;
    }
    _player_position[player] = new_player_position;
    return true;
}

