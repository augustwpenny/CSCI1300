#include<iostream>
#include<cstdlib>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

struct Candy  // Struct for candy that will store info about candies in stores and inventories
{
    string name;
    string description;
    string EffectType;
    int EffectValue;
    string Type;
    int price;
    
};

struct Character // Characters are read in from a file and store data until a player chooses them
{
    string name;
    int gold;
    int stamina;
    Candy candies[9]; 
};

Candy getCandy(string name, Candy arr[], int _numCandies);

int main()
{
    //__________________________

    Candy _candies[30];
    Character _characters[4];
    int _numCandies=0;
    ifstream filein;
   filein.open("Candies.txt"); // This is ok for now, but eventually find a better way maybe pass in the function
   string line;
   

   string name, efType, desc, type, s_efVal, s_cost;
   int efVal, cost;

   while(!filein.eof())
   {
    getline(filein, line);
    stringstream ss(line);
    getline(ss, name, '|');
    getline(ss, desc, '|');
    getline(ss, efType, '|');
    getline(ss, s_efVal, '|');
    getline(ss, type, '|');
    getline(ss, s_cost);

    stringstream c(s_cost);
    c >> cost;
    stringstream ef(s_efVal);
    ef >> efVal;

    Candy temp;
    temp.name=name;
    temp.EffectType=efType;
    temp.description=desc;
    temp.Type=type;
    temp.price=cost;
    temp.EffectValue=efVal;

    _candies[_numCandies]=temp; 
    _numCandies++; 
   }
//  ________________________

   ifstream filein2;
   filein2.open("characters.txt"); // replace with the name of file
   
   string candyNames[9];
   int numNames=0;
   int stamina, gold;
   string line2, s_stamina, s_gold, name2, candyString;
   
   Character temp;
   

   for(int i=0;i<4;i++)
   {
    getline(filein2, line2);
    stringstream ss(line2);
    getline(ss, name2, '|');
    getline(ss, s_stamina, '|');
    getline(ss, s_gold, '|');
    getline(ss, candyString);
    
    stringstream stam(s_stamina);
    stam >> stamina;
    stringstream gol(s_gold);
    gol >> gold;

    
    temp.name=name2;
    temp.stamina=stamina;
    temp.gold=gold;

    string segment;
    stringstream s2 (candyString);
    while(!s2.eof())
    {
        getline(s2, segment, ',');
        candyNames[numNames]=segment;
        numNames++;
    }

    for(int i=0;i<numNames;i++)
    {
        temp.candies[i]=getCandy(candyNames[i], _candies, _numCandies);
    }

    _characters[i]=temp;
   }
    
    // _____________________________
    for(int i=0;i<4;i++)
    {
        cout << _characters[i].candies[i].name << " | " << _characters[i].candies[i].price << endl;
    }

}

Candy getCandy(string name, Candy arr[], int _numCandies)
{
    // replace arr[] with _candies[]
    Candy temp;
    for(int i=0;i<_numCandies;i++)
    {
        if(arr[i].name==name)
        {
            temp=arr[i];
            return temp;
        }
    }
    return temp;
}






