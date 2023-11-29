#include "Board.h"
#include"CandyStore.h"
#include <iostream>

// CSCI 1300 Fall 2023
// Author: August Penny
// TA: Guarav Roy
// boardDriver.cpp

using namespace std;

// bool isPositionCandyStore(int index);

int main()
{
    Board board;

    // Candy red = {"Red", "red candy", 10 , ""};
    // Candy yellow = {"Yellow", "yellow candy", 20 , ""};
    // Candy blue = {"Blue", "blue candy", 30 , ""};
    // Candy green = {"Green", "green candy", 40 , ""};

    // CandyStore c1("Winnie's store"), c2("Bunny's store"), c3("Donald's store");
    // assert(c1.addCandy(red));
    // assert(c1.addCandy(yellow));
    // assert(c2.addCandy(blue));
    // assert(c3.addCandy(green));

    // board.addCandyStore(20);
    // board.addCandyStore(35);
    // board.addCandyStore(50);



    // CandyStore candy_stores[]={c1,c2,c3};

    
    for(int i=0;i<83;i++)
    {
        if(i%10==0)
        {
            board.setPlayerPosition(i, i%1);
            board.displayBoard();
        }
        
    }
    return 0;

}

