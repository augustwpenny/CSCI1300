#include<iostream>
#include"Pokemon.h"

using namespace std;

// Default initializer
Pokemon::Pokemon()
{
    _HP = 50;
    _attack = 10;
    _defense = 5;
    _max = 100;
    _speed = 0;
    _name = "";
}
Pokemon::Pokemon(string name, double HP, int attack, int defense, int max, int speed)
{
    _name=name;
    _HP=HP;
    _attack=attack;
    _defense=defense;
    _max=max;
    _speed=speed;
}





// Setters
// Use the "Pokemon::" to connect it to the correct file/class
void Pokemon::setHP(double HP) // Sets the private _HP variable to the passed in value HP
{
    _HP=HP;
}
void Pokemon::setAttack(int attack)
{
    _attack = attack;
}
void Pokemon::setSpeed(int speed)
{
    _speed = speed;
}
void Pokemon::setDefense(int defense)
{
    _defense = defense;
}
void Pokemon::setMax(int max)
{
    _max = max;
}
void Pokemon::setName(string name)
{
    _name = name;
}





// Getters
// Const prevents the function from changing values, only can read them
double Pokemon::getHP() const
{
    return _HP;
}
int Pokemon::getAttack() const
{
    return _attack;
}
int Pokemon::getSpeed() const
{
    return _speed;
}
int Pokemon::getDefense() const
{
    return _defense;
}
int Pokemon::getMax() const
{
    return _max;
}
string Pokemon::getName() const
{
    return _name;
}
