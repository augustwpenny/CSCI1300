// #include<iostream>
// #include"CandyStore.h"
// #include"Board.h"

// using namespace std;

// // CSCI 1300 Fall 2023
// // Author: August Penny
// // TA: Guarav Roy
// // CandyStore.cpp

// CandyStore::CandyStore()
// {
//     _store_name="";
//     _candy_count=0;
// }
// CandyStore::CandyStore(string store_name)
// {
//     _store_name=store_name;
//     _candy_count=0;
// }
// bool CandyStore::addCandy(Candy candy)
// {
//     if(_candy_count<_MAX_CANDIES)
//     {
//         _candies[_candy_count]=candy;
//         _candy_count++;
//         return true;
//     }
//     cout << "Store is full. cannot add candy" << endl;
//     return false;
// }
// bool CandyStore::removeCandy(string candy_name)
// {
//     bool removeCandy=false;
//     for(int i=0;i<_MAX_CANDIES;i++)
//     {
//         if(_candies[i].name==candy_name)
//         {
//             for(int j=i;j<_MAX_CANDIES; j++)
//             {
//                 _candies[j-1]=_candies[j];
//             }
//             _candy_count--;
//             removeCandy=true;
//             break;
//         }
//     }
//     return removeCandy;
// }
// void CandyStore::displayCandies()
// {
//     if(_candy_count==0)
//     {
//         cout << "No candies are present in " << _store_name << endl;
//         return;
//     }
//     cout << "Candies present in store " << _store_name << " are" << endl;
//     for(int i=0;i< _candy_count;i++)
//     {
//         cout << _candies[i].name << endl;
//     }

// }
