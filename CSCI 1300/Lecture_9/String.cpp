#include<iostream>
#include<iomanip>


using namespace std;

int main()
{
    string name = "August";
    int len = name.length();

    cout << len << endl; // Will print out the length of the string, starting at 0
    
    // A U G U S T
    // 0 1 2 3 4 5

    // To get a Char at a point in the string:

    char letter = name[2];

    cout << letter << endl; // Will print out 'g', the char at index 2 of name

    string second = name.substr(2); // Will create substring from g to end "gust"


    

    return 0;
}