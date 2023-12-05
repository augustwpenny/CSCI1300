#include"CandyStore.h"
#include<iostream>

using namespace std;


CandyStore::CandyStore()
{
    Candy temp={"","","",0,"", 0};
    for(int i=0;i<3;i++)
    {
        _candies[i]=temp;
    }
    
    
}
CandyStore::CandyStore(Candy candies[], int position)
{
    for(int i=0;i<3;i++)
    {
        _candies[i]=candies[i];
    }
    _position=position;
    
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

Candy CandyStore::getCandy(int i)
{
    return _candies[i];
}

// int CandyStore::findCandy(string s) // Returns the index of a candy in the shop. returns -1 if that candy cant be found
// {
//     for(int i=0;i<3;i++)
//     {
//         if(_candies[i].name==s)
//         {
//             return i;
//         }
//     }
//     return -1;
// }

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

void CandyStore::shop()
{
    /*
    1. print the candies with printCandies()
    2. Ask which they would like and use getline(cin, choice) to get their choice
    3. use findCandy to get the index of the candy in the store, and if it returns -1, state that candy cannot be found and prompt again
    4. if there is not enough gold in their inventory, tell them that and exit
    5. if there is not enough space, prompt them to choose what to replace. use getCandy to return the candy from the store and then use
    findCandy in their inventory to get the index of the candy to be replaced in their inventory
    6. update their gold
    7. exit the shop
    */
}