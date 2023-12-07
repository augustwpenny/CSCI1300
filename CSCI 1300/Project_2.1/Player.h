#ifndef PLAYER_H
#define PLAYER_H

#include<string>

// CSCI 1300 Fall 2023
// Author: August Penny
// TA: Guarav Roy
// Player.h

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
        string _charname;

    public:

    Player();
    
    void setName(string); // Sets the Players name
    string getName(); // Returns the players name

    void setCharName(string); // Sets the player's chosen character name
    string getCharName(); // gets the player's chosen character name
    void setCandy(int, Candy); // Sets the candy at a players inventory slot to a candy

    int getTurns(); // checks how many turns this player has been docked
    void setTurns(int); // sets how many turns this player will have skipped
    void incrementTurns(int); // adds turns to be skipped

    void setPosition(int); // Sets the players position
    int getPosition(); // Returns the players position

    Candy getCandy(int); // Returns a candy from int 
    void removeCandy(int); // Removes a candy from their inventory
    void addCandy(Candy); // adds a candy to the players inventory

    void setStamina(int); // sets the players stamina
    int getStamina(); // returns the players stamina
    
    void setGold(int); // sets the players gold
    int getGold(); // returns the players gold

    void setInventory(Candy arr[], int); //use a loop to translate values. the length should come from the _invSize
    void printInventory(); // Prints the players info
    void printCandies(); // prints the players candies
    
};

#endif



/**
 * Player should have: name, inventory of candies, positon, stamina, 
 * 
 * 
**/