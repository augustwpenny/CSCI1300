#include<sstream>
#include<iomanip>
#include<iostream>
#include<array>
#include<fstream>
#include<fstream>


using namespace std;

int main()
{
    cout << "Enter file names:" << endl;
    string fileName1;
    string fileName2;
    getline(cin, fileName1);
    getline(cin, fileName2);c
    ifstream filein1;
    ifstream filein2;
    filein1.open(fileName1);
    filein2.open(fileName2);
    cout << "Enter the output filename:" << endl;
    string outputFile;
    getline(cin, outputFile);
    ofstream outFile;
    outFile.open(outputFile);
    
    string text;
    while(!filein1.eof())
    {
        getline(filein1, text);
        
        outFile << text << endl;
        
    }
    while(!filein2.eof())
    {
        getline(filein2, text);
        
        outFile << text << endl;
        
    }
    
    

    return 0;
}