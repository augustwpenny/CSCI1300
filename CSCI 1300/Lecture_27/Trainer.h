#ifndef TRAINER_H
#define TRAINER_H

#include<iostream>
#include<string>
#include<vector>
#include"Pokemon.h"

using namespace std;


class Trainer
{
    public:
        Trainer();
        Trainer(string); //Name
        Trainer(string, vector<Pokemon>, vector<Badges>); //Name, 
        Trainer(string, vector<Badges>);
        string getName() const;

        bool addPokemon(Pokemon); // Vectors are passed by refrence, so easier to add to an existing one than return a new one
        bool removePokemon(string); // bools usually true if it worked, false if it didnt
        int findPokemon(string); // Finds the integer index of the pokemon in the vector
        int getNumPokemons() const; 
        Pokemon getPokemonAt(int) const; // A method just for returing values from the vector

        void addBadge(Badge);
        void displayBadges() const;

    private:
        string _name;
        vector<Pokemon> _myPokemons;
        int _numPokemons;
        vector<Badges> _badges;
        int _numBadges;
        
};

#endif