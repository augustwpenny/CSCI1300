#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

int main()
{
    ifstream file_in;

    // Open the file
    file_in.open("sales1.txt");

    // Check if file is open
    if(file_in.fail())
    {
        cout << "File does not exist. Terminating" << endl;
        return 1;
    }

    string tempHeader;
    // Ignore the header. either use '>>' operator or getLine(file_in, temp);
    getline(file_in, tempHeader);

    // Make the loop. this is designed to take stuff in like
    // january    15
    // february 4
    // march   8
    // the >> operator will skip the spaces to find the 
    string month;
    double sales=0;
    while(file_in >> month >> sales)
    {
        cout << setw(10) << month << setw(6) << sales << endl;
    }

    // Close the file
    file_in.close();
    return 0;

    
}