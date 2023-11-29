#include<iostream>
#include<fstream>
#include<cstring>
#include<sstream>

using namespace std;

int main()
{
    ifstream file_in;

    // Open the file
    file_in.open("sales2.txt");

    // Check if file is open
    if(file_in.fail())
    {
        cout << "File does not exist. Terminating" << endl;
        return 1;
    }

    string tempHeader;
    // Ignore the header. either use '>>' operator or getLine(file_in, temp);
    getline(file_in, tempHeader);
    stringstream ss(line); // Stores the content of line into ss.
    // line/ss = "January,32"

    // first, stores 
    getline(ss, month, ',');
    // month = "January"
    // ss = "32"


    }

    // Close the file
    file_in.close();
    return 0;

    
}