#include<iostream>
#include<fstream>
#include<cstring>

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

    // Make the loop. this is designed to take stuff in like
    // january    15
    // february 4
    // march   8
    // the >> operator will skip the spaces to find the 
    string line;
    string month;
    double sales;
    while(getline(file_in, line))
    {
        int len=line.length();
        for(int i=0;i<len;i++) 
        {
            if(line.at(i)==',')
            {
                month=line.substr(0,i);
                sales=stod(line,substr(i+1));
            }
        }
        cout << month << " " << sales << endl;
    }

    // Close the file
    file_in.close();
    return 0;

    
}