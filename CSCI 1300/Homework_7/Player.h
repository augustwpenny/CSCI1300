#ifndef PLAYER_H
#define PLAYER_H

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<cctype>

using namespace std;

struct Candy
{
    string name="";
    string description="";
    double price=0;
    string candy_type="";
};

class Player
{
    public:
    

    Player();
    Player(int, double, string, Candy[], const int);

    int getCandyAmount();
    bool isValid(string);

    void setStamina(int);
    int getStamina();

    void setGold(double);
    double getGold();

    void setEffect(string);
    string getEffect();

    void printInventory();

    Candy findCandy(string);

    bool addCandy(Candy);

    bool removeCandy(string);

    private:

    const static int _MAX_CANDY_AMOUNT=4;
    int _stamina;
    double _gold;
    string _effect;
    Candy _inventory[_MAX_CANDY_AMOUNT];
    int _candy_amount=0;

    


    bool compareStrings(string,string);
  

};

#endif
