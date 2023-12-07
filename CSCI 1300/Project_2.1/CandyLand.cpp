#include<iostream>
#include<vector>
#include<sstream>
#include<fstream>
#include<cstdlib>
#include<string>
#include"CandyLand.h"
#include"Player.h"


// CSCI 1300 Fall 2023
// Author: August Penny
// TA: Guarav Roy
// CandyLand.cpp


using namespace std;

CandyLand::CandyLand()
{
    srand(time(0));
    _board.setSpecials();
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

void CandyLand::setOutputFile(string fileName)
{
    _outputFileName=fileName;
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

void CandyLand::printInfo(int player)
{
    _players[player].printInventory();
}

void CandyLand::printBoard()
{
    _board.displayBoard();
}

void CandyLand::writeGameInfo(string filename)
{
    ofstream fileout;
    fileout.open(filename);
    fileout << "Name: " << _players[0].getName() << "\nCharacter Name:" << _players[0].getCharName() << "\nStamina: " << _players[0].getStamina() << "\nGold: " << _players[0].getGold() << "\nPosition:" << _board.getPlayerPosition(0) << "\nCandies:\n";
    for(int i=0;i<9;i+=3)
    {
        fileout << "["<<_players[0].getCandy(i).name << "]   [" << _players[0].getCandy(i+1).name << "]   [" << _players[0].getCandy(i+2).name << "]\n";
    }

    fileout << "Name: " << _players[1].getName() << "\nCharacter Name:" << _players[1].getCharName() << "\nStamina: " << _players[1].getStamina() << "\nGold: " << _players[1].getGold() << "\nPosition:" << _board.getPlayerPosition(0) << "\nCandies:\n";
    for(int i=0;i<9;i+=3)
    {
        fileout << "["<<_players[1].getCandy(i).name << "]   [" << _players[1].getCandy(i+1).name << "]   [" << _players[1].getCandy(i+2).name << "]\n";
    }
    fileout << "\nWinner: " << _winner;
    
}

void CandyLand::setupStores()
{
    srand(time(0));
    int r1, r2, r3;
    CandyStore store;
    r1=rand()%10;
    r2=rand()%9;
    r3=rand()%9;
    for(int j=0;j<3;j++)
    {
        int location=0;
        for(int i=0;i<3;i++)
        {
            store.addCandy(randomCandy(), i);
        }

        if(j==0)
        {
            location=_firstPos[r1];
        } else if(j==1)
        {
            location=_secondPos[r2];
        } else if(j==2)
        {
            location=_thirdPos[r3];
        }
        _board.addStores(store, location, j);
    }
    
    
}

void CandyLand::chooseCharacter(int player)
{
    string choice;
    string playerName;
    cout << "Enter your name player " << player+1 <<":" << endl;
    getline(cin, playerName);
    printCharacters();
    bool success=false;
    cout << playerName <<": Enter the name of the character you would like." << endl;
    while(success==false)
    {
        getline(cin, choice);
        for(int i=0;i<4;i++)
        {
        if(_characters[i].name==choice)
            {
                _players[player].setName(playerName);
                _players[player].setGold(_characters[i].gold);
                _players[player].setStamina(_characters[i].stamina);
                _players[player].setPosition(0);
                _players[player].setInventory(_characters[i].candies, _characters[i].numCandies);
                _players[player].setCharName(_characters[i].name);
                return;
            }
        }
        cout << "No such character exists. Try again." << endl;
    }
    

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

bool CandyLand::checkSkipTurn(int player)
 {

    if(_players[player].getTurns()<0)
    {
        if(_players[player].getTurns()==-1)
        {
            _players[player].setStamina(_players[player].getStamina()+20);
        }
        cout << _players[player].getName() << " your turn is being skipped." << endl;
        _players[player].incrementTurns(1);
        return true;
    }
    return false;
 }

void CandyLand::chooseCard(int player)
{
    cout << "You drew a " << move(drawCard(), player) << ". Here is your updated position." << endl;
    _board.displayBoard();
    
}

void CandyLand::takeTurn(int player) 
{
    string choice;
    bool loop=true;
    cout << _players[player].getName() << ":\nDraw Card?(D)\nDisplay inventory(I)\nUse candy(U)" << endl;
    
    while(loop==true)
    {
        getline(cin, choice);
        if(choice.at(0)=='D')
        {
            chooseCard(player);// Chooses a players card and moves them accordingly then displays their new position on the board
            specialTile(player);//Checks to see if they landed on a special tile. if they do, move them accordingly snd display new board
            checkStore(player);//Checks if the player lands on a store and if they do prompts them to shop
            break;
        } else if(choice.at(0)=='I')
        {
            printInfo(player);
            takeTurn(player);
            break;
        } else if(choice.at(0)=='U')
        {
            useCandy(player); // calls the use candy method
            break;
        }
        cout << "Invalid input. Try again" << endl;
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

Candy CandyLand::randomCandy()
{
    int ind = rand()%_numCandies;
    return _candies[ind];
}

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

        
                
        if(ichoice<9 && ichoice>=0)
        {
            effectType=_players[player].getCandy(ichoice).Type;
            value=_players[player].getCandy(ichoice).EffectValue;
            name=_players[player].getCandy(ichoice).name;
            
            location=ichoice;

            break;
        }
        cout << "Not a valid candy. Please try again or type \"exit\" to exit" << endl;
    }

    
    
    if(effectType=="magical") // Done
    {
        _players[player].removeCandy(ichoice);
        int current=_players[player].getStamina();
        _players[player].setStamina(current+value);
        _players[player].removeCandy(location);
        cout << "Stamina increased by " << value << "." << endl;
        
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

void CandyLand::startGame()
{
    chooseCharacter(0); // sets up the two players info
    chooseCharacter(1); // same as above
    bool t=true;
    int player=0;
    while(t==true)
    {
        if(checkSkipTurn(player)==true) //start of each turn, it checks to see if the players turn is to be skipped
        {
        if(player==0) //Changes from 1 to 0 based on who just went
        {
            player=1;
        } else if(player==1)
        {
            player=0;
        }
        continue;
        }

        takeTurn(player);
        if(endGame()==true)// After each turn, checks to see if the game is over
        {
            break;
        }

        if(player==0) //Changes from 1 to 0 based on who just went
        {
            player=1;
        } else if(player==1)
        {
            player=0;
        }
    }
    writeGameInfo(_outputFileName); // Puts the info from the game into a file
}

void CandyLand::checkStore(int player)
{
    int location=_board.getPlayerPosition(player);
    int storeNum=_board.isStore(location);
    if(storeNum==-1)
    {
        return;
    }

    bool loop=true;
    string inp;
    cout << "You landed in a candy store. Want to shop?(y/n)" << endl;
    
    while(loop==true)
    {
        getline(cin, inp);
        if(inp=="exit") 
        {
            break;
        }
        if(inp.at(0)=='n')
        {
            break;
        } else if(inp.at(0)=='y')
        {
            CandyStore tempStore=_board.getStore(storeNum);
            bool loop2=true;
            string inp2;
            _board.getStore(storeNum).displayCandy();
            cout << "Enter number of the candy you want to purchase" << endl;

            while(loop2==true)
            {
                getline(cin, inp2);

                if(inp2=="exit")
                {
                    break;
                }
                int tempint=-1;
                
                try
                {
                    tempint=stoi(inp2)-1;
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }

                if(tempint>=0 && tempint<=2)
                {
                    Candy fromStore=tempStore.getCandy(tempint);
                    string inp3;
                    bool loop3=true;
                    cout << "What candy would you like to replace?" << endl;
                    _players[player].printCandies();
                    while(loop3==true)
                    {
                        getline(cin, inp3);
                        if(inp3=="exit")
                        {
                            break;
                        }

                        int choice;

                            try
                            {
                                choice=stoi(inp3)-1;
                            }
                            catch(const std::exception& e)
                            {
                                std::cerr << e.what() << '\n';
                            }
                        
                        
                        cout << choice << endl;
                        if(choice>=0&&choice<=8)
                        {
                            _players[player].setCandy(choice, fromStore);
                            cout << "New inventory:" << endl;
                            _players[player].printCandies();
                            return;
                        }
                        cout << "Try again or type exit to exit" << endl;
                    }

                }

                cout << "Invalid input. try again or type \"exit\"" << endl;
            }
        }
        cout << "Invalid input. type \"exit\" to exit or type (y/n)" << endl;
    }

    
    // cout << "Enter the n"
    

}

bool CandyLand::endGame()
{
    if((_board.getPlayerPosition(0)>=81))
    {
        cout << _players[0].getName() << " has won the game by reaching the castle (Character name: " << _players[0].getCharName() << ")" << endl;
        _players[0].printInventory();
        _winner=_players[0].getName();
        return true;
    }
    if((_board.getPlayerPosition(1)>=81))
    {
        cout << _players[1].getName() << " has won the game by reaching the castle (Character name: " << _players[1].getCharName() << ")" << endl;
        
        _players[0].printInventory();
        _winner=_players[1].getName();
        return true;
    }
    return false;
}
