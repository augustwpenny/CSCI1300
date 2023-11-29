#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<cctype>
#include"Player.h"
 





Player::Player()
{
    _stamina = 0;
    _gold = 0;
    _effect = "";
    

    


}
Player::Player(int stamina, double gold , string effect, Candy candy_array[], const int CANDY_ARR_SIZE)
{
    _stamina = stamina;
    _gold = gold;
    _effect = effect;
    


    int i=0;
    while(i<CANDY_ARR_SIZE)
    {
        if(candy_array[i].name!="Empty")
        {
        _inventory[i]=candy_array[i];
        }
        i++;
    }
    
    
}

 bool Player::isValid(string s)
 {
    for(int i=0;i<4;i++)
    {
        if(_inventory[i].name==s) return true;
    }
    return false;
 }

int Player::getCandyAmount()
{
    return _candy_amount;
}

void Player::setStamina(int stamina)
{
    _stamina = stamina;
}

int Player::getStamina()
{
    return _stamina;
}

void Player::setGold(double gold)
{
    _gold = gold;
}
double Player::getGold()
{
    return _gold;
}

void Player::setEffect(string effect)
{
    _effect = effect;
}
string Player::getEffect()
{
    return _effect;
}

void Player::printInventory()
{
        cout << "|[";
        if(_inventory[0].name=="")
        {
            cout << "Empty";
        } else 
        {
            cout << _inventory[0].name;
        }
        cout << "]|[";
        if(_inventory[1].name=="")
        {
            cout << "Empty";
        } else 
        {
            cout << _inventory[1].name;
        }
        cout << "]|" << endl;
        cout << "|[";
        if(_inventory[2].name=="")
        {
            cout << "Empty";
        } else 
        {
            cout << _inventory[2].name;
        }
        cout << "]|[";
        if(_inventory[3].name=="")
        {
            cout << "Empty";
        } else 
        {
            cout << _inventory[3].name;
        }
        cout << "]|" << endl;

}

Candy Player::findCandy(string candy_name)
{
    for(int i=0;i<_MAX_CANDY_AMOUNT;i++)
    {
        if(candy_name == _inventory[i].name)
        {
            return _inventory[i];
        }
    }
    Candy temp;
    temp.name="";
    temp.candy_type="";
    temp.price=0;
    temp.description="";
    return temp;
}

bool Player::addCandy(Candy candy)
{
    if(_candy_amount>=_MAX_CANDY_AMOUNT) return false;
    for(int i=0;i<_MAX_CANDY_AMOUNT;i++)
    {
        if(_inventory[i].name=="")
        {
            _inventory[i]=candy;
            _candy_amount++;
            return true;
        }
    }
    return false;
}

bool Player::removeCandy(string candy_name)
{
    int ind=-1;
    for(int i=0;i<_MAX_CANDY_AMOUNT;i++)
    {
        if(_inventory[i].name==candy_name)
        {
            ind=i;
        }
    }
    if(ind>=0)
    {
        _inventory[ind].name="";
            _inventory[ind].description="";
            _inventory[ind].candy_type="";
            _inventory[ind].price=0;
            _candy_amount--;
            return true;
    }

    return false;
}







bool Player::compareStrings(string s1, string s2)
{
    int len=0;
    if(s2.length()!=s1.length()) return false;

    len = s1.size();

    int c1;
    int c2;
    bool same=true;
    for(int i=0;i<len;i++)
    {
        c1=int(s1.at(i));
        c2=int(s2.at(i));
        if(toupper(c1)!=toupper(c2))
        {
            same=false;
            break;
        }
    }
    return same;

}