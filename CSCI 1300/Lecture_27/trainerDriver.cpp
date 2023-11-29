#include<iostream>
#include<string>
#include<vector>
#include"Pokemon.h"
#include"Trainer.h"

using namespace std;

int main()
{
    Trainer t;
    Pokemon picachu("Picachu",35,55,30,90,50);
    Pokemon eevee("Eevee",55,55,50,55,65);
    Pokemon hypno("Hypno",85,7370,67,115);

    vector<Pokemon> pokedex = {picachu, eevee, hypno};
    Badge demo1 = {"Gold","Gary"};
    Badge demo2 = {"Silver","Brock"};
    vector<Badges> badges = {demo1,demo2};

    Trainer ash("Ash", demo2);
    Trainer 

}