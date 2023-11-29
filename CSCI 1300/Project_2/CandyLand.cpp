#include <iostream>
#include <vector>
#include<sstream>
#include<fstream>
#include<cstdlib>
#include<string>
#include"CandyLand.h"
#include"CandyStore.h"
#include"Board.h"


using namespace std;

int countTimes(string s, char seperator);
int split(string input, char seperator, string arr[], int arr_size);
int numCharacters(string filename);

CandyLand::CandyLand(string candyFile, string characterFile)
{
    loadCandies(candyFile);
    loadCharacters(characterFile);
    CandyStore c1, c2, c3; //Need to make three candy stores to pass into the board
}



void CandyLand::loadCharacters(string filename)
{
    /*
    1. create a stringstream
    2. create a for loop to run 4 times
        - use getline with the appropriate deliminator to get the name, gold, stamina and a string of candies
        - use split function to fill an array of candies with the appropriate candies by name
        - save this Character struct object in the _characters array
    */



    // ifstream filein;
    // filein.open(filename);
    // string line;
    // Character characters[numCharacters(filename)];
    // int index=0;
    // while(!filein.eof())
    // {
    //     string name, candie, s_stamina, s_gold;
    //     int stamina, gold;
    //     Candy candies[];
        
    //     getline(filein, line);
    //     stringstream ss (line);
    //     getline(ss, name, '|');
    //     getline(ss, s_stamina, '|');
    //     stamina=stoi(s_stamina);
    //     getline(ss, s_gold, '|');
    //     gold=stoi(s_gold);
    //     getline(ss, candie);



    //     Character c1;
    //     c1.name=name;
    //     c1.stamina=stamina;
    //     c1.gold=gold;
    //     c1.invSize=split(candie, ',', candies, countTimes(candie));
    //     c1.candies=candies;
        
    //     characters[index]=c1;
    //     index++;
    // }
}

void CandyLand::printCharacters()
{
    for(int i=0;i<4;i++)
    {
        cout << "Name: " << _characters[i].name << "\nStamina: " << _characters[i].stamina << "\nGold: " << _characters[i].gold << "\nCandies: ";
    for(int j=0;j<9;j++)
    {
        cout << "["<< _characters[i].candies[j].name << "]  ";
        if(i%3==0)
        {
            cout << endl;
        }
    }
    cout << "-----------------------------------------------" << endl;

    }
}

void CandyLand::loadCandies(string filename)
{
    /*
    1. Declares and initializes a counting variable to be 0
    2. creates a filein and has a while loop that runs until .eof is true
        - creates a temporary candy object
        - uses getline() with each line being made a stringstream to get the variables about the candy from the file
        - sets the temporary candy object's values to the appropriate ones from the file
        - adds the temporary candy to the array at the index of the counting variable
        - increments the counting variable
    3. sets _numCandies to the counting variable
    */
}


Candy CandyLand::randomCandy()
{
    /*
    returns a random candy from the candy list. used to populate stores.
    */
}

void CandyLand::setupBoard()
{
    /*
    1. creates 3 new CandyStore objects with random candies determined by three random candies from the _candies list
    2. assigns each of the the candy stores a random number from the list of random positions they can be at (_firstPos, _secondPos, or _thirdPos)

    2. creates a board object() and passes in the three candyStores
    3. 
    */
}

Card CandyLand::drawCard()
{
    string cards[3] = {"Cotton Candy Magenta card", "Minty Green card", "Bubblegum blue card"};
    Card temp;
    int j=rand()%3;
    temp.color=cards[j];
    temp.name=cards[j];

    if(rand()%5<1)
    {
        temp.dbl=true;
        string tmp=temp.name;
        temp.name="Dobule " + tmp;
    }

    return temp;
}

void CandyLand::move(Player player, Card card)
{
    int current= player.getPosition();

    if(card.name.at(0)=='C') //If magenta card
    {
        if(current%3==0)
    {
        if(card.dbl==true) 
        {
            player.setPosition(current+6);
        }
        else 
        {
            player.setPosition(current+3);
        }
        
    }
    if(current%3==1)
    {
        if(card.dbl==true) 
        {
            player.setPosition(current+4);
        }
        else 
        {
            player.setPosition(current+1);
        }
    }
    if(current%3==2)
    {
        if(card.dbl==true) 
        {
            player.setPosition(current+5);
        }
        else 
        {
            player.setPosition(current+2);
        }
    }
    }

    if(card.name.at(0)=='M') //If green
    {
        if(current%3==0)
    {
        if(card.dbl==true) 
        {
            player.setPosition(current+5);
        }
        else 
        {
            player.setPosition(current+2);
        }
        
    }
    if(current%3==1)
    {
        if(card.dbl==true) 
        {
            player.setPosition(current+3);
        }
        else 
        {
            player.setPosition(current+6);
        }
    }
    if(current%3==2)
    {
        if(card.dbl==true) 
        {
            player.setPosition(current+4);
        }
        else 
        {
            player.setPosition(current+1);
        }
    }
    }

    if(card.name.at(0)=='B') //If blue
    {
        if(current%3==0)
    {
        if(card.dbl==true) 
        {
            player.setPosition(current+5);
        }
        else 
        {
            player.setPosition(current+2);
        }
        
    }
    if(current%3==1)
    {
        if(card.dbl==true) 
        {
            player.setPosition(current+4);
        }
        else 
        {
            player.setPosition(current+1);
        }
    }
    if(current%3==2)
    {
        if(card.dbl==true) 
        {
            player.setPosition(current+6);
        }
        else 
        {
            player.setPosition(current+3);
        }
    }
    }

    
    

}

void setupPlayer(int player, int character, string name) // int is for which player. character int is 0-3 to determine what character they selected
{
    _players[player].setName(name);
    _players[player].setPosition(0);
    _players[player].setStamina(_characters[character].stamina);
    _players[player].setGold(_characters[character].gold);
    _players[player].setInventory(_characters[character].candies, 9);



    // Candy candies[9];
    // for(int i=0;i<9;i++)
    // {
    //     for(int j=0;j<_numCandies;j++)
    //     {
    //         if(_candies[j].name==names[i])
    //         {
    //             candies[i]=_candies[j];
    //             break;
    //         }
    //     }
    // }
    // _players[player].setInventory(candies, 9);

}

void useCandy()

int showTurn()
{
    cout << "Please select a menu option:\n1. Draw a card\n2. Use candy\n3. Show player stats"
    int choice;
    getline(cin,choice);
    return choice;
    
}

void startGame()
{
    srand(time(0));
    CandyStore firstStore; // Will need some method to fill candy store with random candies and call it here

    string p1, p2;
    string character1, character2;
    int s1, s2;
    char c1,c2;
    cout << "Enter player 1 name:" << endl;
    getline(cin, p1);
    cout << "Awesome! here is a list of characters to choose from:" << endl;
    printCharacters();
    cout << "Select a character:" << endl;
    cin >> character1;
    if(character1==_characters[0].name) s1=0;
    if(character1==_characters[1].name) s1=1;
    if(character1==_characters[2].name) s1=2;
    if(character1==_characters[3].name) s1=3;
    setupPlayer(0, s1, character1); // Sets up the player at position 0 of player array with the info from the Character array at index p1
    cout << "Do you want to visit the candy store?(y/n)" << endl;
    cin >> c1;
    if(c1=='y') 
    {
        firstStore.shop();// This is the shop method. this may need to be refined
    }

    cout << "Enter player 2 name:" << endl;
    getline(cin, p2, character2);
    cout << "Awesome! here is a list of characters to choose from:" << endl;
    printCharacters();
    cout << "Select a character:" << endl;
    cin >> character2;
    if(character2==_characters[0].name) s2=0;
    if(character2==_characters[1].name) s2=1;
    if(character2==_characters[2].name) s2=2;
    if(character2==_characters[3].name) s2=3;
    setupPlayer(1, s1); // Sets up the player at position 1 of player array with the info from the Character array at index p2
    cout << "Do you want to visit the candy store?(y/n)" << endl;
    cin >> c2;
    if(c2=='y') 
    {
        firstStore.shop();// This is the shop method. this may need to be refined
    }


    int turn=0;
    while(_players[0].getPosition()<78 && _players[1].getPosition()<78)
    {
        cout << "It's " << _players[turn].getName(); < "'s turn" << endl;
        if(showTurn()==1)
        {
            Card temp=drawCard();
            cout << "You drew a " << temp.name << "." << endl;
            move(_players[turn], Card temp);
            cout << "This is the new board" << endl;
            _board.displayBoard();
        }
        if(showTurn()==2)
        {
            /*
            This is where use candy is called. not sure how to impliment this yet
            */
        }




        if(turn==0) //Alternates the turn of the player it is based on whose turn just finished their turn
        {
            turn=1;
        }
        else if (turn==1)
        {
            turn=0;
        }
    }


    /*
    1. prompt how many people will play and save this to an int. currently 2 people
    2. for loop to go repeat once for each player, asking them what character they want to be and printing out the list of characters. the info from selected character is then put into 
    a player in the array of players.
    3. there is a loop that goes until a players position reaches within 5 tiles of the castle at the end of the board with an integrer alternating between 1 and 2 to determine what player is playing
        - each loop starts off by displaying whose turn it is and offering them three options. take card, use candy or show stats
        - showing stats will show player info them prompt again
        - take card will randomly generate a card using the drawCard method
        - the card will be displayed and then the players position will be updated with the move function
        - if the player chooses to use a candy, their candies will be displayed and they type in the candy they want to use and it goes to the useCandy function

    */
}




int split(string input, char seperator, string arr[], int arr_size)
{
    if(int(input.length())==0 || arr_size==0) // Returns 0 if the string doesnt exist
    {
        return 0;
    }
    string segment;
    int index=0;
    stringstream ss (input);
    while(!ss.eof())
    {
        getline(ss, segment, seperator);
        if(index<arr_size)
        {
            arr[index]=segment;
            index++;
        }
        else{
            return -1;
        }
    }
    return index;
}

int countTimes(string s, char seperator){
    if(s.size()==0) return 0;
    int ret=1;
    for(int i=0;i<s.size();i++)
    {
        if(s.at(i)==seperator) ret++;
    }
    return ret;
}





