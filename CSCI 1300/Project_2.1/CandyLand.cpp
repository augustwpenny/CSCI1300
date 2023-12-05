#include <iostream>
#include <vector>
#include<sstream>
#include<fstream>
#include<cstdlib>
#include<string>
#include"CandyLand.h"
#include"Player.h"




using namespace std;

CandyLand::CandyLand()
{
    srand(time(0));
    _board.setSpecials();
}
// int countTimes(string s, char seperator);
// int split(string input, char seperator, string arr[], int arr_size);
// int numCharacters(string filename);

CandyLand::CandyLand(string candyFile, string characterFile)
{
    
    loadCandies(candyFile);
    // loadCharacters(characterFile);
}



void CandyLand::loadCharacters(string filename)
{
    ifstream filein;
   filein.open(filename); // replace with the name of file
   
   string candyNames[9];
   
   
   
   
   
   int i=0;
   string line;

   while(i<4 && getline(filein, line))//loop repeats 4 times or until file end is reached. whole line saved to line
   {
    Character temp; //temp character to be put in array
    string s_stamina, s_gold, name, candyString; // strings for stamina, gold, name and string of candies
    int numNames=0; // how many candies are in the string
    int stamina, gold;
    
    stringstream ss(line);
    getline(ss, name, '|');
    getline(ss, s_stamina, '|');
    getline(ss, s_gold, '|');
    getline(ss, candyString);
    
    stringstream stam(s_stamina);
    stam >> stamina;
    stringstream gol(s_gold);
    gol >> gold;

    
    temp.name=name;
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

    for(int j=0;j<numNames;j++)
    {
        temp.candies[j]=getCandy(candyNames[j]);
    }
    temp.numCandies=numNames;
    _characters[i]=temp;
    i++;
   }
}

void CandyLand::printCharacters()
{
    for(int i=0;i<4;i++)
    {
        cout << "Name: " << _characters[i].name << "\nStamina: " << _characters[i].stamina << "\nGold: " << _characters[i].gold << "\nCandies:\n";

        for(int j=0;j<_characters[i].numCandies;j++)
        {
            cout << "["<< _characters[i].candies[j].name << "]\n";
            
        }
    cout << "----------------------------------------------" << endl;

    }
}

void CandyLand::chooseCharacter(int player)
{
    string choice;
    printCharacters();
    bool success=false;
    cout << "Player "<<player+1<<": Enter the name of the character you would like." << endl;
    while(success==false)
    {
        getline(cin, choice);
        for(int i=0;i<4;i++)
        {
        if(_characters[i].name==choice)
            {
                _players[player].setGold(_characters[i].gold);
                _players[player].setStamina(_characters[i].stamina);
                _players[player].setPosition(0);
                _players[player].setInventory(_characters[i].candies, _characters[i].numCandies);
                return;
            }
        }
        cout << "No such character exists. Try again." << endl;
    }
    

}

 bool CandyLand::checkSkipTurn(int player)
 {
    if(_players[player].getTurns()>0)
    {
        if(_players[player].getTurns()==1)
        {
            _players[player].setStamina(_players[player].getStamina()+20);
        }
        cout << _players[player].getName() << " Your turn is being skipped. " << endl;
        _players[player].incrementTurns(-1);
        return true;
    }
    return false;
 }

void CandyLand::printInfo(int player)
{
    _players[player].printInventory();
}

void CandyLand::loadCandies(string filename) // Works out
{
   ifstream filein;
   filein.open(filename); // This is ok for now, but eventually find a better way maybe pass in the function
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
}


Candy CandyLand::randomCandy()
{
    srand(time(0));
    int ind = rand()%_numCandies;
    return _candies[ind];
}

// void CandyLand::setupBoard()
// {
//     /*
//     1. creates 3 new CandyStore objects with random candies determined by three random candies from the _candies list
//     2. assigns each of the the candy stores a random number from the list of random positions they can be at (_firstPos, _secondPos, or _thirdPos)

//     2. creates a board object() and passes in the three candyStores
//     3. 
//     */
// }
// void CandyLand::setupStores()
// {
//     srand(time(0));
//     int r1, r2, r3;
//     CandyStore store;
//     r1=rand()%10;
//     r2=rand()%9;
//     r3=rand()%9;
//     for(int j=0;j<3;j++)
//     {
//         int location=0;
//         for(int i=0;i<3;i++)
//         {
//             store.addCandy(randomCandy(), i);
//         }

//         if(j==0)
//         {
//             location=_firstPos[r1];
//         } else if(j==1)
//         {
//             location=_secondPos[r2];
//         } else if(j==2)
//         {
//             location=_thirdPos[r3];
//         }
//         _board.addStores(store, location, j);
//     }
    
    
// }

Candy CandyLand::getCandy(string name) // works
{
    Candy temp;
    for(int i=0;i<_numCandies;i++)
    {
        if(_candies[i].name==name)
        {
            temp=_candies[i];
            return temp;
        }
    }
    return temp;
}

// void CandyLand::checkStore(int player)
// {
//     int location=_board.getPlayerPosition(player);
//     int storeNum=_board.isStore()
//     if(storeNum==-1)
//     {
//         return;
//     }

//     CandyStore store =_board.getStore(storeNum);
    

// }

void CandyLand::printBoard()
{
    _board.displayBoard();
}

Card CandyLand::drawCard()
{
    string cards[3] = {"Cotton Candy Magenta card", "Minty Green card", "Bubblegum blue card"};
    Card temp;
    int j=rand()%3;
    temp.color=cards[j];
    temp.name=cards[j];
    int dubl=rand()%4;

    if(dubl<1)
    {
        temp.dbl=true;
        string tmp=temp.name;
        temp.name="Dobule " + tmp;
    }

    return temp;
}

void CandyLand::specialTile(int player)
{
    int pos=_board.getPosition(player);
    int special=_board.getSpecial(pos);
    if(special==1)
    {
        _board.movePlayer(4, player);
        cout << "You landed on a shortcut tile. You will be moved forwards an additional 4 tiles." << endl;
        printBoard();
    }
    if(special==2)
    {
        cout << "You landed on an Ice cream shop. you will draw one more card." << endl;
        chooseCard(player);
    }
    if(special==3)
    {
        int lost=(rand()%6)+5;
        cout << "You landed in a gumdrop forest. You will move back 4 tiles and lose " << lost << " Gold coins." << endl;
        _board.movePlayer(-4, player);
        printBoard();
    }
    if(special==4)
    {
        _board.movePlayer(-1, player);
        // Remove immunity candy
        cout << "You landed in a Gingerbread house tile. you move 1 square back and lose an immunity candy" << endl;
        for(int i=0;i<9;i++)
        {
            if(_players[player].getCandy(i).Type=="immunity")
            {
                _players[player].removeCandy(i);
                break;
            }
        }
        printBoard();
    }
}

string CandyLand::move(Card card, int person)
{
    int currentPos=_board.getPlayerPosition(person);
    int currentColor=getColor(currentPos);
    string cardColor=card.color;
    int cardC=0;
    int advance=0;
    if(cardColor.at(0)=='C')
    {
        cardC=1;
    } else if(cardColor.at(0)=='M')
    {
        cardC=2;
    } else if(cardColor.at(0)=='B')
    {
        cardC=3;
    }
    int mtpl=0;
    if(card.dbl==true)
    {
        mtpl=3;
    }


    if(cardC==currentColor)
    {
        advance=3+mtpl;
        
        
    }else if(currentColor==1)
    {
        if(cardC==2)
        {
            advance=1+mtpl;
        }
        if(cardC==3)
        {
            advance=2+mtpl;
        }
    }else if(currentColor==2)
    {
        if(cardC==1)
        {
            advance=2+mtpl;
        }
        if(cardC==3)
        {
            advance=1+mtpl;
        }
    }
    else if(currentColor==3)
    {
        if(cardC==2)
        {
            advance=2+mtpl;
        }
        if(cardC==3)
        {
            advance=1+mtpl;
        }
    }

    _board.movePlayer(advance, person);
    return card.name;
}

int CandyLand::getColor(int position)
{
    // 1 for red, 2 for green, 3 for blue
    for(int i=0;i<27;i++)
    {
        if(position==_magenta[i])
        {
            return 1;
        }
        if(position==_green[i])
        {
            return 2;
        }
        if(position==_blue[i])
        {
            return 3;
        }
    }
    cout << "Cant find color in getColor()" << endl;
    return 0;
}
void CandyLand::chooseCard(int player)
{
    cout << "You drew a " << move(drawCard(), player) << ". Here is your updated position." << endl;
    _board.displayBoard();
}
// void setupPlayer(int player, int character, string name) // int is for which player. character int is 0-3 to determine what character they selected
// {
//     _players[player].setName(name);
//     _players[player].setPosition(0);
//     _players[player].setStamina(_characters[character].stamina);
//     _players[player].setGold(_characters[character].gold);
//     _players[player].setInventory(_characters[character].candies, 9);



//     // Candy candies[9];
//     // for(int i=0;i<9;i++)
//     // {
//     //     for(int j=0;j<_numCandies;j++)
//     //     {
//     //         if(_candies[j].name==names[i])
//     //         {
//     //             candies[i]=_candies[j];
//     //             break;
//     //         }
//     //     }
//     // }
//     // _players[player].setInventory(candies, 9);

// }

void CandyLand::useCandy(int player)
{

    string choice;
    string effectType;
    string name;
    int value=0;
    int affectedPlayer=0;
    int location=-1;
    int ichoice=-1;
    if(player==0) affectedPlayer=1;

    cout << "Here are your candies:" << endl;
    _players[player].printCandies();
    cout << "Enter the number of the candy you want to use:"<< endl;
    bool loop=false;
    
    while(loop==false)
    {
        getline(cin, choice);
        if(choice=="exit")
        {
            return;
        }
        


        try
        {
            ichoice=stoi(choice)-1;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
                
        if(ichoice<10 && ichoice>0)
        {
            effectType=_players[player].getCandy(ichoice).Type;
            value=_players[player].getCandy(ichoice).EffectValue;
            name=_players[player].getCandy(ichoice).name;
            location=ichoice;

            break;
        }
        cout << "Not a valid candy. Please try again or type \"exit\" to exit" << endl;
    }

    
    
    if(effectType=="stamina") // Done
    {
        _players[player].removeCandy(ichoice);
        int current=_players[player].getStamina();
        _players[player].setStamina(current+value);
        _players[player].removeCandy(location);
        cout << "Stamina increased by" << value << "." << endl;
        
    }
    else if(effectType=="poison") // Done
    {
        _players[player].removeCandy(ichoice);
        bool blocked=false;
        for(int i=0;i<9;i++)
        {
            if(_players[affectedPlayer].getCandy(i).Type=="immunity") 
            {
                cout << "You used your poison candy but they used their " << _players[affectedPlayer].getCandy(i).name << " candy to block the poison" << endl;
                _players[affectedPlayer].removeCandy(i);
                blocked=true;
                break;
            }
        }
        if(blocked==false)
        {
            int current=_players[affectedPlayer].getStamina();
            _players[affectedPlayer].setStamina(current+value);
            cout << "You used "<< name << " to reduce your opponent stamina by " << value << endl;
        }
        
    }
    else if(effectType=="immunity") // Done
    {
        cout << "Cannot use this candy unless posion candy is used against you" << endl;
    }
    
    else if(effectType=="gummy")
    {
        _players[player].removeCandy(ichoice);
        _players[affectedPlayer].setTurns(value);
        cout << "Gummy used to take "<< value << " turns from your opponent" << endl;
    } else 
    {
        cout << "Candy slot is empty" << endl;
    }
}

// int showTurn()
// {
//     cout << "Please select a menu option:\n1. Draw a card\n2. Use candy\n3. Show player stats"
//     int choice;
//     getline(cin,choice);
//     return choice;
    
// }

// int CandyLand::checkIsStore(int position) // returns which store is at the position
// {
//     for(int i=0;i<3;i++)
//     {
//         if(position==_stores[i])
//         {
//             return i;
//         }
//     }
//     return -1;
// }

// void startGame()
// {
//     srand(time(0));Candy candies[30]; // replace with the _candies array
//    ifstream filein;
//    filein.open("candies.txt"); // This is ok for now, but eventually find a better way maybe pass in the function
//    string line;
//    int interator=0;

//    string name, efType, desc, type, s_efVal, s_cost;
//    double cost;
//     int efVal;

//    while(!filein.eof())
//    {
    
    
    
//     getline(filein, line);
//     stringstream ss(line);
//     getline(ss, name, '|');
//     getline(ss, desc, '|');
//     getline(ss, efType, '|');
//     getline(ss, s_efVal, '|');
//     getline(ss, type, '|');
//     getline(ss, s_cost);

//     stringstream c(s_cost);
//     c >> cost;
//     stringstream ef(s_efVal);
//     ef >> efVal;



//     Candy temp;
//     temp.name=name;
//     temp.EffectType=efType;
//     temp.description=desc;
//     temp.Type=type;
//     temp.price=cost;
//     temp.EffectValue=efVal;

//     candies[interator]=temp; // replace
//     interator++; // replace with _numcandies


//     string p1, p2;
//     string character1, character2;
//     int s1, s2;
//     char c1,c2;
//     cout << "Enter player 1 name:" << endl;
//     getline(cin, p1);
//     cout << "Awesome! here is a list of characters to choose from:" << endl;
//     printCharacters();
//     cout << "Select a character:" << endl;
//     cin >> character1;
//     if(character1==_characters[0].name) s1=0;
//     if(character1==_characters[1].name) s1=1;
//     if(character1==_characters[2].name) s1=2;
//     if(character1==_characters[3].name) s1=3;
//     setupPlayer(0, s1, character1); // Sets up the player at position 0 of player array with the info from the Character array at index p1
//     cout << "Do you want to visit the candy store?(y/n)" << endl;
//     cin >> c1;
//     if(c1=='y') 
//     {
//         firstStore.shop();// This is the shop method. this may need to be refined
//     }

//     cout << "Enter player 2 name:" << endl;
//     getline(cin, p2, character2);
//     cout << "Awesome! here is a list of characters to choose from:" << endl;
//     printCharacters();
//     cout << "Select a character:" << endl;
//     cin >> character2;
//     if(character2==_characters[0].name) s2=0;
//     if(character2==_characters[1].name) s2=1;
//     if(character2==_characters[2].name) s2=2;
//     if(character2==_characters[3].name) s2=3;
//     setupPlayer(1, s1); // Sets up the player at position 1 of player array with the info from the Character array at index p2
//     cout << "Do you want to visit the candy store?(y/n)" << endl;
//     cin >> c2;
//     if(c2=='y') 
//     {
//         firstStore.shop();// This is the shop method. this may need to be refined
//     }


//     int turn=0;
//     int choice;
//     bool loop=true;
//     while(loop==true;)
//     {
//         choice=showTurn();
//         cout << "It's " << _players[turn].getName(); < "'s turn" << endl;
//         if(choice=3)
//         {
//             _players[turn].printInventory();
//             choice=showTurn();
//         }

//         if(choice==1)
//         {
//             Card temp=drawCard();
//             cout << "You drew a " << temp.name << "." << endl;
//             move(_players[turn], Card temp);
//             int store=checkIsStore(_players[turn].getPosition())
//             if(store>=0)
//             {
//                 char enter;
//                 cout << "You landed on a store. Enter?(y/n)" << endl;
//                 cin >> enter;
//                 if(enter=='y')
//                 {
//                     _stores[store].shop();
//                 }
//             }
//             cout << "This is the new board" << endl;
//             _board.displayBoard();
//         }
//         else if(choice==2)
//         {
            
//         }




//         if(turn==0) //Alternates the turn of the player it is based on whose turn just finished their turn
//         {
//             turn=1;
//         }
//         else if (turn==1)
//         {
//             turn=0;
//         }
//     }


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
// }




// int split(string input, char seperator, string arr[], int arr_size)
// {
//     if(int(input.length())==0 || arr_size==0) // Returns 0 if the string doesnt exist
//     {
//         return 0;
//     }
//     string segment;
//     int index=0;
//     stringstream ss (input);
//     while(!ss.eof())
//     {
//         getline(ss, segment, seperator);
//         if(index<arr_size)
//         {
//             arr[index]=segment;
//             index++;
//         }
//         else{
//             return -1;
//         }
//     }
//     return index;
// }

// int countTimes(string s, char seperator){
//     if(s.size()==0) return 0;
//     int ret=1;
//     for(int i=0;i<s.size();i++)
//     {
//         if(s.at(i)==seperator) ret++;
//     }
//     return ret;
// }





