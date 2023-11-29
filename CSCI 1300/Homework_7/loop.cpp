#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<cctype>
#include<limits>
#include<climits>

using namespace std;

struct Test
{
    string t;
};

// int main()
// {
//     Test a;
//     a.t="this";
//     string c="";
//     cout << "Enter char" << endl;
//     cin >> c;
//     while(c!=a.t)
//     {
//         cin.clear();
//         cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
//         cout << "bad" << endl;
//         cin >> c;
//     }
//     return 0;
// }