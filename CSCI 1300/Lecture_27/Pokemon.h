
// Header guards. make sure the same class is not defined multiple times. will define the clsss between them.
#ifndef POKEMON_H
#define POKEMON_H

// still can/need to include things
#include<string>
using namespace std;

class Pokemon // Define the class
{
    public: // Things the caller has access to. things like functions

    Pokemon(); // Default constructor with no inputs
    Pokemon(string, double, int, int, int, int); // Constructor that takes in all the values


    // Functions belonging to a class are "member functions"

    // Every variable needs a getter and setter method


    // Getter. doesnt take in any parameters, only meant to return data
    // use const because getters are not allowed to update the values
    double getHP() const;
    int getAttack() const;
    int getSpeed() const;
    int getDefense() const;
    int getMax() const;
    string getName() const;


    // Setters. prototype them in this file first??
    void setHP(double);
    void setAttack(int);
    void setSpeed(int);
    void setDefense(int);
    void setMax(int);
    void setName(string);




    private: // Things like variables/data that shouldnt be directly accessible

    double _HP; // Using an underscore for the private verson of the data helps to differentiate it
    int _attack;
    int _speed;
    int _defense;
    int _max;
    string _name;
};


#endif 