#ifndef PLAYER_H
#define PLAYER_H

#include<string>


using namespace std;

struct Candy  // Struct for candy that will store info about candies in stores and inventories
{
    string name;
    string description;
    string EffectType; //Needs to be gummy, immunity, poison or magical
    int EffectValue;
    string Type;
    int price;
    
};


class Player{
    private:
        string _name;
        int _stamina;
        int _gold;
        int _position;
        Candy _inventory[9];
        int _numCandies;
        int _turns=0;

    public:

    Player();
    // Player(string, int, int, Candy candies[], int); // this could be an issue, check if it is
    
    void setName(string);
    string getName();

    int getTurns();
    void setTurns(int);
    void incrementTurns(int);

    void setPosition(int);
    int getPosition();

    Candy getCandy(int);
    void removeCandy(int);

    void setStamina(int);
    int getStamina();
    
    void setGold(int);
    int getGold();

    void setInventory(Candy arr[], int); //use a loop to translate values. the length should come from the _invSize
    void printInventory();
    void printCandies();
    // void setInventory(Candy, int);
    // int searchInventory(string);
    


};

#endif



/**
 * Player should have: name, inventory of candies, positon, stamina, 
 * 
 * 
**/