#include<iostream>

using namespace std;

int fibonacci(int n)
{
    if(n<=1) return n;
    return fibonacci(n-1)+fibonacci(n-2);
}

int towerOfHanoi(int n, char sourceRod, char destinationRod, char auxilliaryRod)
{
    int moves=0;
    if(n==1) return 1;
    moves+=towerOfHanoi(n-1, sourceRod, auxilliaryRod, destinationRod);
    moves++;
    moves+=towerOfHanoi(n-1, auxilliaryRod, destinationRod, sourceRod);
    return moves;
}

int main()
{
    int input;
    cout << "How many discs do you want to use" << endl;
    cin >> input;
    cout << "Number of moves: " << towerOfHanoi(input, 'A', 'B', 'C') << endl;
    return 0;
}