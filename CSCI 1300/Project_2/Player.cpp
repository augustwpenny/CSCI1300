#include "Player.h"

using namespace std;


Player::Player()
{
    _name="";
    _stamina=0;
    _gold=0;
    _position=0;


}



// Player::Player(string name, int stamina, int gold, Candy candies[], int length, int number)
// {
//     _name=name;
//     _stamina=stamina;
//     _gold=gold;
//     _position=0;
//     _number=number;
//     if(length>9)
//     {
//         for(int i=0;i<9;i++)
//         {
//              _inventory[i]=candies[i];
//         }
//     }
//     if(length<9)
//     {
//         Candy c1;
//         c1.name="Empty";
//         c1.description="";
//         c1.EffectType="";
//         c1.EffectValue=0;
//         c1.Type="";
//         c1.price = 0;
//         for(int i=0;i<length;i++)
//         {
//             _inventory[i]=candies[i];
//         }
//         for(int j=length;j<9;j++)
//         {
//             _inventory[j]=c1;
//         }
//     }
// }




void Player::setName(string name)
{
    _name=name;
}
string Player::getName()
{
    return _name;
}

void Player::setPosition(int pos)
{
    _position=pos;
}
int Player::getPosition()
{
    return _position;
}

void Player::setGold(int gold)
{
    _gold=gold;
}
int Player::getGold()
{
    return _gold;
}

void Player::setStamina(int stamina)
{
    _stamina=stamina;
}
int Player::getStamina()
{
    return _stamina;
}

void Player::printInventory()
{
    cout << "Name: " << _name << "\nStamina: " << _stamina << "\nGold: " << _gold << "\nPosition: " << _position << "\nCandies: "<< endl;
    for(int i=0;i<9;i++)
    {
        cout << "Name: "<<_inventory[i].name << "\n"  endl;
    }
}


void Player::setInventory(Candy arr[], int length) //use a loop to translate values. the length should come from the _invSize
{
    if(length>=9)
    {
        for(int i=0;i<9;i++)
        {
             _inventory[i]=arr[i];
        }
    }
    if(length<9)
    {
        Candy c1;
        c1.name="Empty";
        c1.description="";
        c1.EffectType="";
        c1.EffectValue=0;
        c1.Type="";
        c1.price = 0;
        for(int i=0;i<length;i++)
        {
            _inventory[i]=arr[i];
        }
        for(int j=length;j<9;j++)
        {
            _inventory[j]=c1;
        }
    }
}

void setInventory(Candy candy, int index)
{
    _inventory[index]=candy;
}

int searchInventory(string name)
{
    /*
    1. looks through the inventory for a candy matching the name inputted
    2. returns the index of that candy or returns -1 if it cannot find it
    */
}