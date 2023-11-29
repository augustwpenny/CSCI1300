#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

struct Candy  // Struct for candy that will store info about candies in stores and inventories
{
    string name;
    string description;
    string EffectType;
    int EffectValue;
    string Type;
    double price;
    
};

struct Character // Characters are read in from a file and store data until a player chooses them
{
    string name;
    int gold;
    int stamina;
    Candy candies[9]; 
};

int main()
{
    Candy a,b,c,d, e;
    a.name="A";
    b.name="B";
    c.name="C";
    d.name="D";
    e.name="E";
    Candy _candies[5] = {a,b,c,d,e};

    string names[4] = {"A", "B", "C", "D"};

    Candy candies[4];

    Character c1;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(_candies[j].name==names[i])
            {
                candies[i]=_candies[j];
                break;
            }
        }
    }
    





    
    c1.candies[0]=a;

    cout << c1.candies[0].name << endl;

}

