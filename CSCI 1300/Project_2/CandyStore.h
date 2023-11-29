#ifndef CANDYSTORE_H
#define CANDYSTORE_H
#include "CandyLand.h"


using namespace std;

class CandyStore{
    private:
    Candy _candies[3];
    int _position;

    public:
    CandyStore();
    CandyStore(Candy candies[]);

    void removeCandy(string);
    void addCandy(Candy, int);
    Candy getCandy(int);
    Candy findCandy(string);
    void printCandies();
    int getPosition();

    void shop();

};

#endif