// CSCI 1300, Fall 2023
// Supriya Naidu
// Lecture 2: garbage values

#include <iostream>

using namespace std;


int main()
{
    int var1;
    // variables of numeric data types should be initialized before use
    // if a variable is uninitialized then we may get 0 or garbage values
    cout << var1 << endl;

    return 0;
}