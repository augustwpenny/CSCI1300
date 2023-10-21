#include<iostream>
#include<iomanip>
#include<cmath>

// CSCI 1300 Fall 2023
// Author: August Penny
// TA: Guarav Roy
// Question 1

using namespace std;
void createArrays();

int main()
{

createArrays();
}

void createArrays()
{
    string card_names[9]={"Ace", "Clubs", "Diamonds", "Hearts", "Spades", "Jack", "Queen", "King", "Joker"};
    double sq_root_nums[10]={sqrt(1), sqrt(2), sqrt(3), sqrt(4), sqrt(5), sqrt(6), sqrt(7), sqrt(8), sqrt(9), sqrt(10)};
    for(int i=1;i<=10;i++)
    {
        sq_root_nums[i-1]=sqrt(double(i));
    }
    
    int numbers[7];
    int c=0;
    for(int i=50;i<=100;i++)
    {
        if(i%7==0)
        {
            numbers[c]=i;
            c++;
        }
    }

    char letters[52];
    int u=65;
    int l=97;
    for(int i=0;i<52;i+=2)
    {
        letters[i]=char(u);
        letters[i+1]=char(l);
        u++;
        l++;
    }
    

    cout << fixed << setprecision(3);

    for(int i=0;i<9;i++)
    {
        cout << card_names[i] << endl;
    }

    for(int i=0;i<10;i++)
    {
        cout << sq_root_nums[i] << endl;
    }

    for(int i=0;i<7;i++)
    {
        cout << numbers[i] << endl;
    }

    for(int i=0;i<52;i++)
    {
        cout << letters[i] << endl;
        
    }
    


}