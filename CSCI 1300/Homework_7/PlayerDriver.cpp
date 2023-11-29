#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<cctype>
#include<limits>
#include<climits>
#include"Player.h"

using namespace std;

bool checkPresent(string names[], string n);

void playRockPaperScissors(Player players[2])
{

    bool b = true;

    //Player 1
    string s1;
    cout << "Player 1 Inventory" << endl;
    players[0].printInventory();
    cout << "Player 1: Select candy to bet" << endl;

    while(b==true)
    {
        cin >> s1;
        if(players[0].isValid(s1)==true)
        {
            b=false;
            break;
        }
        cout << "Invalid selection!" << endl;
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    }

    b=true;
    
    


    // Player 2
    string s2;
    cout << "Player 2 Inventory" << endl;
    players[1].printInventory();
    cout << "Player 2: Select candy to bet" << endl;
    while(b==true)
    {
        cin >> s2;
        if(players[1].isValid(s2)==true)
        {
            b=false;
            break;
        }
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    }


    
    bool t=true;
    int win=0;
    do{

        //Player 1 selection
        cout << "Player 1: Enter r, p or s" << endl;
        char c1;
        cin >> c1;
        while((c1!= 'r' && c1!= 'p' && c1!= 's'))
        {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid selection!" << endl; 
            cin >> c1;
        }


        //Player 2 selection
        cout << "Player 2: Enter r, p or s" << endl;
        char c2;
        cin >> c2;
        while(c2!= 'r' && c2!= 'p' && c2!= 's')
        {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid selection!" << endl;
            cin >> c2;
        }

        // Tie check
        if(c1==c2) 
        {
            cout << "Tie! Play again" << endl;
            continue;
        }

        if(c1=='r' && c2=='s') win=1;
        if(c1=='p' && c2=='r') win=1;
        if(c1=='s' && c2=='p') win=1;

        if(c1=='s' && c2=='r') win=2;
        if(c1=='r' && c2=='p') win=2;
        if(c1=='p' && c2=='s') win=2;
        break;

    } while(t==true);

    if(win==1) 
    {
        cout << "Player 1 has won " << s2 << " from player 2!" << endl;
        players[1].removeCandy(s2);
        players[0].addCandy(players[1].findCandy(s2));
    }
    if(win==2)
    {
        cout << "Player 2 has won " << s1 << " from player 1!" << endl;
        players[0].removeCandy(s1);
        players[1].addCandy(players[0].findCandy(s1));
    }
    cout << "Player 1 Inventory after:" << endl;
    players[0].printInventory();
    cout << "Player 2 Inventory after:" << endl;
    players[1].printInventory();


}

int main()
{
    Candy test1{"Brown Candy", "From mud", 1.01, "Buff"};
    Candy test2{"red Candy", "From red", 2.21, "Buff"};
    // Candy empty[2]{test1, test2};
    Player p1 = Player();
    Player p2 = Player();
    p1.addCandy(test1);
    p1.addCandy(test2);
    p2.addCandy(test1);
    p2.addCandy(test2);

    Player players[2]{p1,p2};
    playRockPaperScissors(players);
}



bool checkPresent(string names[], string n)
{
    for(int i=0;i<4;i++)
    {
        if(names[i]==n) return true;
    }
    return false;
}