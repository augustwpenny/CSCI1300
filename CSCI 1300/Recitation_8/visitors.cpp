#include<sstream>
#include<iomanip>
#include<iostream>
#include<array>
#include<fstream>


using namespace std;

int main()
{
    cout << "Enter file name:" << endl;
    string fileName;
    getline(cin, fileName);
    ifstream filein;
    filein.open(fileName);
    string dayNames[5]={"Monday","Tuesday","Wednesday","Thursday","Friday"};
    int days[5];
    int day=0;
    string text;

    while(!filein.eof())
    {
        getline(filein, text);
        int times=1;
        int t=text.length();
        for(int i=0;i<t;i++)
        {
            if(text.at(i)==',') 
            {
            times++;
            }
        }
        
        days[day]=times;
        day++;
    }
    
    
    int maxInd=0;
    for(int i=0;i<5;i++)
    {
        if(days[maxInd]<days[i])
        {
            maxInd=i;
        }
    }
    cout << dayNames[maxInd] << " is the busiest day of the week at the motel." << endl;

    return 0;
}