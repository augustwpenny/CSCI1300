#include"CandyStore.h"
#include<iostream>
// CSCI 1300 Fall 2023
// Author: August Penny
// TA: Guarav Roy
// CandyStore.cpp
using namespace std;


CandyStore::CandyStore()
{
    Candy temp={"","","",0,"", 0};
    for(int i=0;i<3;i++)
    {
        _candies[i]=temp;
    }
    
}

void CandyStore::removeCandy(string name)
{
    for(int i=0;i<3;i++)
    {
        if(_candies[i].name==name)
        {
            Candy temp={"","","",0,"", 0};
            _candies[i]=temp;
        }
    }

}

void CandyStore::displayCandy()
{
    for(int j=1;j<=3;j++)
    {
        cout << "[ ("<<j<<")   " << _candies[j-1].name << "]  ";
    }
    cout << endl;
}

Candy CandyStore::getCandy(int i)
{
    return _candies[i];
}

void CandyStore::addCandy(Candy candy, int i)
{
    _candies[i]=candy;
}

void CandyStore::printCandies()
{
        cout << "Here is a list of candies in the candy store:"<< endl;
        for(int i=0;i<3;i++)
        {
            cout << "Name: " << _candies[i].name << "\nDescription: " << _candies[i].description << "\nEffect: " << _candies[i].EffectType << "\nEffect value: "<<_candies[i].EffectValue<<"\nCandy Type: "<<_candies[i].Type <<"\nPrice: "<< _candies[i].price << endl;
            if(i<2)
            {
                cout <<"--------------------------" << endl;
            }
        }   
}

int CandyStore::getPosition()
{
    return _position;
}

void CandyStore::setPosition(int position)
{
    _position=position;
}
