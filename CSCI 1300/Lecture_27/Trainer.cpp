#include<iostream>
#include<string>
#include<vector>
#include"Pokemon.h"
#include"Trainer.h"

using namespace std;

Trainer::Trainer()
{
    _name = "empty";
}
Trainer::Trainer(string name)
{
    _name = name;
}
Trainer::Trainer(string name, Pokemon p)
{
    _name = name;
    _myPokemons.push_back(p);
}
Trainer::Trainer(string name, vector<Pokemon> p_vec, vector<Badges> b_vec)
{
    _name = name;

    for(int i=0;i<p_vec.size();i++)
    {
        _myPokemons.at(i)=p_vec.at(i);
        _numPokemons++;
    }
    for(int i=0;i<b_vec.size();i++)
    {
        _badges.at(i)=p_vec.at(i);
        _numbadges++;
    }
}
Trainer::Trainer(string name, vector<Badges> b_vec)
{
    _name = name;
    
    for(int i=0;i<b_vec.size();i++)
    {
        _badges.at(i)=p_vec.at(i);
        _numbadges++;
    }
}




string Trainer::getName() const
{
    return _name;
}
bool Trainer::addPokemon(Pokemon p)
{
    //1. Look to see if there is a pokemon with the same name already
    // call findPokemon(p.getName())
    //2. if there isnt, add one. if there is, dont
}

int Trainer::findPokemon(string name)
{
    //1. Look to see if there is a pokemon with the same name already
    int index=-1;

    return index;

}
bool Trainer::setPokemonAt(Pokemon p, int index)
{

    int found = findPokemon(p.getName());

    if(index>=0 && index<_numPokemons && found == -1)
    {
        _myPokemons.at(index) = p;
        return true;
    }

    return false;
}
int Trainer::getNumPokemons() 
{
    return _numPokemons;
}
void Trainer::addBadge(Badge b)
{
    _badges.push_back(Badge b);
    _numBadges++;
}
void Trainer::displayBadges()
{
    for(int i=0;i<_numBadges;i++)
    {
        cout << "Type: "<<_badges.at(i).type<< endl;
        cout << "Trainer defeated: "<<_badges.at(i).type<< endl;
    }
}
