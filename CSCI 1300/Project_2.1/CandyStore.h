#ifndef CANDYSTORE_H
#define CANDYSTORE_H

#include"Player.h"

using namespace std;

class CandyStore{
    private:
    Candy _candies[3];
    int _position;

    public:
    CandyStore();
    CandyStore(Candy candies[], int);

    void removeCandy(string);
    void addCandy(Candy, int);
    Candy getCandy(int);
    // Candy findCandy(string);
    void printCandies();
    int getPosition();
    void setPosition(int);

    void shop();

};

#endif