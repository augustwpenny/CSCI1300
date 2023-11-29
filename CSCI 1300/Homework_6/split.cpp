#include<sstream>
#include<fstream>
#include<vector>
#include<iostream>

using namespace std;


int split(string input_string, char seperator, string arr[], int arr_size);



int split(string input_string, char seperator, string arr[], int arr_size)
{
    int count=0;
    stringstream ss1;
    ss1 << input_string;
    char temp;
    int len=0;
   while(ss1 >> temp) //gets the number of times the seperator occurs
    {
        if(temp==seperator) count++;
        len++;
    }
    
    if(count==0) 
    {
        arr[0]=input_string;
        return 1;
    }

    stringstream ss;
    ss << input_string;
    string word;
    int length=0;
    for(int i=0;i<=count;i++) 
    {

        getline(ss, word, seperator);
        arr[i]=word;
        length++;
    }   
    if(count>arr_size)
    {
        return -1;
    }
    return length;
}