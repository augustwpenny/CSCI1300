#include "Aquarium.h"
#include<fstream>
#include<sstream>

using namespace std;

int main()
{
    //create an aquarium object
Aquarium billys_aquarium("Billy");

//load fish from file
billys_aquarium.loadFish("fish_example.txt");

//try adding a Fish that doesn't exist + print the result
cout << billys_aquarium.addFish("not a real fish") << endl;

//add a fish that does exist + print the result. Note: the fish requires 5 gallons
cout << billys_aquarium.addFish("platinum ogon koi") << endl;

// add two more fish, for a total of 11 gallons of water used
cout << billys_aquarium.addFish("eLePhAnt EaR bEtTa") << endl; // requires 3 gallons
cout << billys_aquarium.addFish("Blue Peacock Cichlid") << endl; // requires 3 gallons

//try adding another fish that would result in 13 gallons used
cout << billys_aquarium.addFish("red PANDA guppy") << endl;
    return 0;
}