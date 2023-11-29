#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void compareAttendanceSheet(string firstFile, string secondFile);

// int main()
// {
// string f1;
// string f2;
// cout << "Enter files" << endl;
// cin >> f1;
// cin >> f2;
// compareAttendanceSheet(f1, f2);

// }

void compareAttendanceSheet(string firstFile, string secondFile)
{
    vector<string> vec1;
    vector<string> vec2;
    vector<string> absent;
    ifstream file1(firstFile);
    ifstream file2(secondFile);
    string student;
    int l1, l2;

    if(file1.fail() || file2.fail()) 
    {
        cout << "Failed to open attendance files" << endl;
        return;
    }
    
    while(!file1.eof())
    {
        getline(file1, student);
        vec1.push_back(student);
    }
    l1=int(vec1.size());

    while(!file2.eof())
    {
        getline(file2, student);
        vec2.push_back(student);
    }
    l2=int(vec2.size());

    for(int i=0;i<l1;i++)
    {
        string compare=vec1.at(i);
        bool present=false;
        for(int j=0;j<l2;j++)
        {
            if(vec2.at(j)==compare)
            {
                present=true;
                break;
            }
            
        }
        if(present==false) absent.push_back(compare);
    }
    if(int(absent.size()==0))
    {
        cout << "Every student has boarded the bus. It's time to leave." << endl;
    } else 
    {
        cout << "Students yet to board the bus are" << endl;
        for(int i=0;i<int(absent.size());i++) cout << absent.at(i) << endl;
    }
}