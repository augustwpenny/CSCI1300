#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<iomanip>



// // CSCI 1300 Fall 2023
// // Author: August Penny
// // TA: Guarav Roy
// // Question 1

using namespace std;

// struct Dog
// {
//     string name;
//     int age;
//     string favorite_toy;
// };



struct Candy
{
    string name;
    string description;
    double price;
    string candy_type;
};

vector<Candy> readCandy(string file_name, vector<Candy> candies)
{
    ifstream filein(file_name);
    if(filein.fail())
    {
        cout << "Failed to open file" << endl;
        return candies;
    }

    string line;
    while(getline(filein, line))
    {
        if(line == "" || line == "\n")
        {
            continue;
        }
        Candy c1;
        string p;
        stringstream ss(line);
        getline(ss, c1.name, '|');
        getline(ss, c1.description, '|');
        getline(ss, p, '|');
        getline(ss, c1.candy_type);
        c1.price=stod(p);
        candies.push_back(c1);
    }
    return candies;
}

// int main()
// {
//     // Dog d1;
//     // d1.name="spot";
//     // d1.age=3;
//     // d1.favorite_toy="tennis ball";
//     // Dog d2;
//     // d2.name="lassie";
//     // d2.age=3;
//     // d2.favorite_toy="frisbee";

//     // cout << "Name: "<< d1.name << ". Age: " << d1.age << ". Favorite Toy: " << d1.favorite_toy << "." << endl;
//     // cout << "Name: "<< d2.name << ". Age: " << d2.age << ". Favorite Toy: " << d2.favorite_toy << "." << endl;
    
//     // string fname;
//     // cout << "Enter file to read:" << endl;
//     // cin >> fname;

//     // vector<Candy> c;

//     // vector<Candy> c2 = readCandy(fname, c);
//     // for(int i=0;i<c2.size();i++)
//     // {
//     //     cout <<"Name: " <<c2.at(i).name << ". Description: " <<c2.at(i).description << ". Price: " << setprecision(2) << fixed << c2.at(i).price << ". Type: " << c2.at(i).candy_type <<endl;
//     // }

//     // return 0;
// }
