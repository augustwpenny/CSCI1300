#include<iostream>
#include"CandyLand.h"


using namespace std;

int main()
{
    
    CandyLand c;
    c.loadCandies("candies.txt");
    c.loadCharacters("characters.txt");
    c.chooseCharacter(0);
    c.chooseCharacter(1);
    bool t=true;
    int player=0;
    while(t==true)
    {
        if(c.checkSkipTurn(player)==true)
        {
            continue;
        }
        string choice;
        cout << "Player " << player+1 << ": Draw Card?(y/n) or display inventory(i) or use candy(u)" << endl;
        getline(cin, choice);
        if(choice.at(0)=='y')
        {
            c.chooseCard(player);
            c.specialTile(player);
        } else if(choice.at(0)=='i')
        {
            c.printInfo(player);
        } else if(choice.at(0)=='u')
        {
            c.useCandy(player);
        }
    
        if(player==0) 
        {
            player=1;
        } else if(player==1)
        {
            player=0;
        }
        
    }
    
    // c.printCharacters();


    // c.chooseCard(0);
    // cout << c.move(c.drawCard(),0) << endl;
    // c.printBoard();
    // cout << c.move(c.drawCard(),0) << endl;
    // c.printBoard();
    // cout << c.move(c.drawCard(),0) << endl;
    // c.printBoard();
    
    
    

    // b.setPlayerPosition(1, 0);
    // b.setPlayerPosition(b.getPlayerPosition(0)+1, 0);
    // b.setPlayerPosition(b.getPlayerPosition(0)+1, 0);
    // b.setPlayerPosition(b.getPlayerPosition(0)+1, 0);
    // b.setPlayerPosition(b.getPlayerPosition(0)+1, 0);
    // b.displayBoard();
    
    

    return 0;
}
